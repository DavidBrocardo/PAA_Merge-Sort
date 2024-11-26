void merge_sort_in_place(vector<int>& arr, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        merge_sort_in_place(arr, inicio, meio);
        merge_sort_in_place(arr, meio + 1, fim);
        merge_in_place(arr, inicio, meio, fim);
    }
}