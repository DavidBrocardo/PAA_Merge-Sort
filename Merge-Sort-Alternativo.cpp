#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

void merge_in_place(vector<int>& arr, int inicio, int meio, int fim) {
    int i = inicio;  // 1 atrib = 1
    int j = meio + 1;   // 1 atrib + 1 soma =  2
    while (i <= meio && j <= fim) { // 2 comparacao * n = 2n 
        if (arr[i] <= arr[j]) { // (1 comp + 2 indexação) * n = 2n 
            i++; // n  
        } else { 
            int aux = arr[j]; // (1 atrib + 1 index) * n =  2n  
            for (int k = j; k > i; k--) { // (1 atib*n + ((n^2+n)/2 * (1 comp + 1 dec)) + 1comp *n  = n^2 + 3n
                arr[k] = arr[k - 1]; // (1 atrib + 1 index + 1 sub)* (n^2+n)/2 = 2n^2 + 2n
            }
            arr[i] = aux; // 1 atrib + 1 index = 2n
            i++; // 1 inc = n
            meio++;// 1 inc = n
            j++;// 1 inc = n
        }
    } //Total = 3n^2 + 17n + 3 
}

void merge_sort_in_place(vector<int>& arr, int inicio, int fim) { 
    if (inicio < fim) { // 1 comparacao 
        int meio = inicio + (fim - inicio) / 2; // (1 atrib + 1 soma + 1 sub + 1 div) 
        merge_sort_in_place(arr, inicio, meio); // 1 chamada rec 
        merge_sort_in_place(arr, meio + 1, fim); // (1 chamada rec + 1 soma )
        merge_in_place(arr, inicio, meio, fim); //  (1 chamada de funcao)
    } 
}// 

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <nome_do_arquivo>" << endl;
        return 1;
    }

    ifstream arquivo(argv[1]);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return 1;
    }

    vector<int> vetor;
    string linha;
    while (getline(arquivo, linha)) {
        try {
            int numero = stoi(linha);
            vetor.push_back(numero);
        } catch (invalid_argument& e) {
            cerr << "Erro ao converter linha para número: " << linha << endl;
        }
    }
    arquivo.close();

    merge_sort_in_place(vetor, 0, vetor.size() - 1);

    return 0;
}
