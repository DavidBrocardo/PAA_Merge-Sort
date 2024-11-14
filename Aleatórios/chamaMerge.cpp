#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> 
#include <time.h>

using namespace std;

int main() {
    ifstream arquivo("nomes.txt");
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo."  << endl;
        return 1;
    }


    int compilacao = system("g++ Merge-Sort-Alternativo.cpp -o MergeA");
    if (compilacao != 0) {
        cerr << "Erro ao compilar" << endl;
        return 1;
    }
    string linha;


    FILE* arquivoTempo = fopen("TempoAleatorio.csv", "a");
    if (arquivoTempo == nullptr) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return 1;
    }
    fprintf(arquivoTempo, "Arquivo , Merge-Sort, Merge-Sort-Aleatorio \n");

    while (getline(arquivo, linha)) {
        cout << "Arquivo atual : " << linha << endl;
        for (int i = 0; i < 6; i++){
            clock_t Ticks[2];
            Ticks[0] = clock();
            string exe = "MergeA " + linha+ ".txt";
            int execucao = system(exe.c_str());
            if (execucao != 0) {
                cerr << "Erro ao executar" << endl;
                return 1;
            }            
            Ticks[1] = clock();
            double TempoAlternativo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
            if (i != 0){
                fprintf(arquivoTempo, "%s, 0 , %f\n", linha.c_str(), TempoAlternativo);
            }
            
            cout << "Tempo gasto: "<< TempoAlternativo << "ms." << endl;     
                   
        } 

    }
    arquivo.close();

    return 0;
}
