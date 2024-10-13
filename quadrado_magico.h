#ifndef QUADRADO_MAGICO_H
    #define QUADRADO_MAGICO_H

    #include <vector>

    using namespace std;

    void solicitarOrdemMatriz(int* ordem);
    void solicitarValoresMatriz(vector<vector<int>>& matriz, int ordem);
    void verificarQuadradoMagico(vector<vector<int>>& matriz, int* primeiraSoma, int ordem);
    void verificarDiagonais (vector<vector<int>>&matriz, int& primeiraSoma, int ordem);
    void imprimirMatriz(vector<vector<int>>& matriz, int ordem);
    void imprimirResultados(vector<vector<int>>& matriz, int ordem, int primeiraSoma);

#endif
