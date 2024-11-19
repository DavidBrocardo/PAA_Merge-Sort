#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

void merge_in_place(vector<int>& arr, int inicio, int meio, int fim) {
    int i = inicio;  // 1 atrib = 1
    int j = meio + 1;   // 1 atrib + 1 soma = 2

    while (i <= meio && j <= fim) { // n vezes no pior caso 
        if (arr[i] <= arr[j]) { // 1 comp * n
            i++; // n  // melhor caso (ordenado)
        } else { //Pior caso 
            int aux = arr[j]; // 1 atrib  * n = N 
            for (int k = j; k > i; k--) { // (1 atib + n(1 comp + 1 dec) )*n  = 2n^2 + n
                arr[k] = arr[k - 1]; // 2n^2
            }
            arr[i] = aux; // 1 atrib = n
            i++; // 1 inc = n
            meio++;// 1 inc = n
            j++;// 1 inc = n
        }
    } //4n^2 + 7n + 3 Pior caso 
     // caso base  2n + 3
}

void merge_sort_in_place(vector<int>& arr, int inicio, int fim) { // 2 Chamadas de n/2 + custo de 6n 
    if (inicio < fim) { // 1 comparacao * n-1 = 2n
        int meio = inicio + (fim - inicio) / 2; // 4n 
        merge_sort_in_place(arr, inicio, meio); // n/2 vezes
        merge_sort_in_place(arr, meio + 1, fim); // n/2 vezes
        merge_in_place(arr, inicio, meio, fim); //  
    } // T(n)  =  2T(n/2) + 4n^2 + 13n + 3 
    // T(n) = 2T(n/2) + n^2
    // Teorema mestre  =  n ^ Log(2)2 =1
    //                     f(n) =  n^2  -> Custo quadrático
}

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
