
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