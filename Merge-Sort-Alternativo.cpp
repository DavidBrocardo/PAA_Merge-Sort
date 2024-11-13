#include <iostream>
#include <vector>
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

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    merge_sort_in_place(arr, 0, arr.size() - 1);

    
    cout << "Vetor ordenado: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
