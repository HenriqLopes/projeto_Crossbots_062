#include <iostream>
#include "quadrado_magico.h"

void solicitarOrdemMatriz (int* ordem) {
    do {
        cout << "Digite a ordem do quadrado magico: ";
        cin >> *ordem;
    } while (*ordem < 2 || *ordem > 10);
}

void solicitarValoresMatriz (vector<vector<int>>& matriz, int ordem){
    cout << "Digite os elementos da matriz:" << endl;
    for (int linha = 0; linha < ordem; linha++) {
        for (int coluna = 0; coluna < ordem; coluna++) {
            cin >> matriz[linha][coluna];
        }
    }
}

void verificarQuadradoMagico (vector<vector<int>>& matriz, int* primeiraSoma, int ordem) {
    verificarLinhas   (matriz, *primeiraSoma, ordem);
    verificarDiagonais(matriz, *primeiraSoma, ordem);
}

void verificarLinhas (vector<vector<int>>&matriz, int& primeiraSoma, int ordem) {
    int somaln, somacl;

    for(int linha = 0; linha < ordem; linha++) {
        somaln = 0, somacl = 0;

        for(int coluna = 0; coluna < ordem; coluna++) {
            somaln += matriz[linha][coluna];
            somacl += matriz[coluna][linha];
        }

        if(primeiraSoma == -1) {
            primeiraSoma = somaln;
        }

        if(somacl != primeiraSoma || somaln != primeiraSoma) {
            primeiraSoma = -1;
            return;
        }
    }
}

void verificarDiagonais (vector<vector<int>>&matriz, int& primeiraSoma, int ordem) {
    int somaDiagPrin = 0, somaDiagSec = 0;
    
    for(int linha = 0; linha < ordem; linha++){
        somaDiagPrin += matriz [linha][linha];
        somaDiagSec  += matriz [linha][(ordem - 1) - linha];
    }

    if(somaDiagPrin != primeiraSoma || somaDiagSec != primeiraSoma){
        primeiraSoma = -1;
    }
}

void imprimirMatriz (vector<vector<int>>& matriz, int ordem) {
    cout << "Matriz:" << endl;
    for (int linha = 0; linha < ordem; linha++) {
        for (int coluna = 0; coluna < ordem; coluna++) {
            cout << matriz[linha][coluna] << " ";
        }
        cout << endl;
    }
}

void imprimirResultados (vector<vector<int>>&matriz, int ordem, int primeiraSoma){
    if(primeiraSoma != -1){
        imprimirMatriz (matriz, ordem);
        cout << "A matriz e um quadrado magico e a soma magica e: " << primeiraSoma << endl;
    }
    else {
        cout << "A matriz nao e um quadrado magico." << endl;
        cout << "Resultado da soma = -1" << endl;
    }
}