
#include "Dijkstra.h"

CaminoMinimo::CaminoMinimo(int tmp, GrafoMatriz *g) {
    numVertices = g->OnumeroDeVertices();
    origen = tmp;
    ultimo = new int[numVertices];
    D = new int[numVertices];
}


void CaminoMinimo::Dijkstra(GrafoMatriz grafoMatriz, int origen){
    bool * F;
    F = new bool [numVertices];// valores iniciales
    for (int i = 0; i < numVertices; i++){
        F[i] = false;
        D[i] = grafoMatriz.Ovalor(origen, i);
        ultimo[i] = origen;
    }

    F[origen] = true;        //Marca origen e inicializa distancia
    D[origen] = 0;

    for (int i = 1; i < numVertices; i++)
    {
        int v = minimo(F);
        //selecciona vértice no marcado de menor distancia
        F[v] = true;
        // actualiza distancia de vértices no marcados
        for (int w = 0; w < numVertices; w++)
            if (!F[w])
                if (D[v] + grafoMatriz.Ovalor(v, w) < D[w]){
                    D[w] = D[v] + grafoMatriz.Ovalor(v, w);
                    ultimo[w] = v;
                }
    }
}



int CaminoMinimo::minimo( bool F[]){
    int mx = -1;// valor de infinito
    int v;
    for (int j = 0; j < numVertices; j++) {
        if (!F[j] && (mx == D[j])) {
            mx = D[j];
            v = j;
        }
    }
    return v;
}

int *CaminoMinimo::OdistanciaMinima() {
    return D;
}



