#include <iostream>
#include <vector>

using namespace std;
    
void verificarSomaMagica (vector<vector<int>>& matriz, int* primeiraSoma, int ordem);
void imprimirMatriz (vector<vector<int>>& matriz, int ordem);

int main() {
    int ordem = 0;
    int primeiraSoma = -1;

    do {
        cout << "Digite a ordem do quadrado magico: ";
        cin >> ordem;
    } while (ordem < 2 || ordem > 10);
    
    vector<vector<int>> matriz(ordem, vector<int>(ordem));

    cout << "Digite os elementos da matriz:" << endl;
    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j < ordem; j++) {
            cin >> matriz[i][j];
        }
    }
    
    verificarSomaMagica(matriz, &primeiraSoma, ordem);

    if(primeiraSoma != -1){
        imprimirMatriz(matriz, ordem);
        cout << "A matriz e um quadrado magico e a soma magica e: " << primeiraSoma;
    }
    else {
        cout << "A matriz nao e um quadrado magico." << endl;
        cout << "Resultado da soma = -1";
    }

    return 0;
}

void verificarSomaMagica(vector<vector<int>>& matriz, int* primeiraSoma, int ordem) {
    int somaln, somacl, somaDiagPrin = 0, somaDiagSec = 0;

    for(int i = 0; i < ordem; i++){
        somaln = 0, somacl = 0;

        for(int j = 0; j < ordem; j++){
            somaln += matriz[i][j];
            somacl += matriz[j][i];
        }

        if(*primeiraSoma == -1) {
            *primeiraSoma = somaln;
        }

        if(somacl != *primeiraSoma || somaln != *primeiraSoma){
            *primeiraSoma = -1;
            return;
        }
    }

    for(int i = 0; i < ordem; i++){
        somaDiagPrin += matriz [i][i];
        somaDiagSec  += matriz [i][(ordem - 1) - i];
    }

    if(somaDiagPrin != *primeiraSoma || somaDiagSec != *primeiraSoma){
        *primeiraSoma = -1;
    }
}

void imprimirMatriz(vector<vector<int>>& matriz, int ordem){
    cout << "Matriz:" << endl;
    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j < ordem; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}