#include "GrafoMatriz.h"

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

class CaminoMinimo {
protected:
    int *ultimo;
    int *D;
private:
    int origen, numVertices;

public:
    CaminoMinimo(int, GrafoMatriz*);

    void Dijkstra(GrafoMatriz grafoMatriz, int origen); // dijkstra
    void recuperaCamino(int v);

    int *OdistanciaMinima();

    int *Oultimo();

private:
    int minimo(bool F[]); // metodo privado usado por dijkstra };
};

#endif