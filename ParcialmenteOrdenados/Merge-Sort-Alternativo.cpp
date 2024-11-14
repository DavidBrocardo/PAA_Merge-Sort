#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

void merge_in_place(vector<int>& arr, int inicio, int meio, int fim) {
    int i = inicio;  
    int j = meio + 1; 

    while (i <= meio && j <= fim) {
        if (arr[i] <= arr[j]) {
            i++;
        } else {
            int aux = arr[j];
            for (int k = j; k > i; k--) {
                arr[k] = arr[k - 1];
            }
            arr[i] = aux;
            i++;
            meio++;
            j++;
        }
    }
}

void merge_sort_in_place(vector<int>& arr, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        merge_sort_in_place(arr, inicio, meio);
        merge_sort_in_place(arr, meio + 1, fim);
        merge_in_place(arr, inicio, meio, fim);
    }
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

    /*cout << "Vetor antes da ordenação: ";
    for (int num : vetor) {
        cout << num << " ";
    }
    cout << endl;*/
    merge_sort_in_place(vetor, 0, vetor.size() - 1);

    /*cout << "Vetor ordenado: ";
    for (int num : vetor) {
        cout << num << " ";
    }
    cout << endl;*/

    return 0;
}
