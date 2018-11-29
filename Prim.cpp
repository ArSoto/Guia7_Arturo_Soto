#include "Prim.h"


Prim::Prim(GrafoMatriz g)
{
    n = g.OnumeroDeVertices();

    INFINITO = 0xFFFF;

    longMin = 0;

    typedef int * pint;

    T = new pint [n];

    for ( int i = 0 ; i < n; i++) {

        T[i] = new int [n];

        for(int j = 0; j < n; j++)

            T[i][j] = INFINITO;

    }
}


int Prim::arbolExpansionPrim(GrafoMatriz g)
{
    int menor;
    int i, j, z;
    int *coste = new int [n];
    int * masCerca = new int [n];
    bool *W = new bool [n];
    for (i = 0; i < n; i++)
        W[i] = false;
// conjunto vacío
    W[0] = true;
//se parte del vértice 0
// inicialmente, coste[i] es la arista (0,i)
    for (i = 1; i < n; i++)
    {
        coste[i] = g.Ovalor(0, i);
        masCerca[i] = 0;
    }
    coste[0] = INFINITO;
    for (i = 1; i < n; i++)
    { // busca vértice z de V-W mas cercano,
// de menor longitud de arista, a algún vértice de W
        menor = coste[1];
        z = 1;
        for (j = 2; j < n; j++)
            if (coste[j] < menor)
            {
                menor = coste[j];
                z = j;
            }
        longMin += menor;
// se escribe el arco incorporado al árbol de expansión
        cout << "V" << masCerca[z] << " -> V" << z;
        W[z] = true;
// vértice z se añade al conjunto W
        T[masCerca[z]][z] = T[z][masCerca[z]] = coste[z];
        coste[z] = INFINITO;
// debido a la incorporación de z,
// se ajusta coste[] para el resto de vértices
        for (j = 1; j < n; j++)
            if ((g.Ovalor(z, j) < coste[j]) && !W[j])
            {
                coste[j] = g.Ovalor(z, j);
                masCerca[j] = z;
            }
    }
    return longMin;
}