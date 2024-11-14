#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void merge(vector<int>& vetor, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    //criando vetores temporarios
    vector<int> L(n1), R(n2);

    //copiando para vetor temporario left
    for (int i = 0; i < n1; i++)
        L[i] = vetor[left + i];

    //copiando para vetor temporario right
    for (int j = 0; j < n2; j++)
        R[j] = vetor[mid + 1 + j];

    
    int i = 0, j = 0, k = left;

    //mesclando os temp vet de volta ao: vetor[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vetor[k] = L[i];
            i++;
        } else {
            vetor[k] = R[j];
            j++;
        }
        k++; 

    }

    //se a metade final não foi toda consumida, faz o append.
    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }

    //se a metade inicial não foi toda consumida, faz o append.
    while (j < n2) {
        vetor[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& vetor, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        //chamadas recursivas para as metades esquerda e direita
        mergeSort(vetor, left, mid);
        mergeSort(vetor, mid + 1, right);

        //mesclando os vetorays já ordenados
        merge(vetor, left, mid, right);
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


    int n = vetor.size(); //tam vetoray

    mergeSort(vetor, 0, n - 1);

    /*cout << "vetoray ordenado: ";
    for (int i = 0; i < n; i++)
        cout << vetor[i] << " ";
    cout << endl;*/

    return 0;
}