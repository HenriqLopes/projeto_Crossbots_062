/*Se estiver usando o VSCode, colocar no terminal o comando 
" g++ main.cpp funcoes.cpp -o quadradoMagico.exe ", depois vai na pasta do arquivo e roda o executável.*/

#include <iostream>
#include "quadrado_magico.h"

using namespace std;

int main() {
    int ordem = 0;
    int primeiraSoma = -1;

    solicitarOrdemMatriz (&ordem);
    
    vector<vector<int>> matriz(ordem, vector<int>(ordem, 0));

    solicitarValoresMatriz (matriz, ordem);
    verificarQuadradoMagico (matriz, &primeiraSoma, ordem);
    imprimirResultados (matriz, ordem, primeiraSoma);

    system("pause");

    return 0;
}