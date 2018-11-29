#ifndef GUIA7_ARTURO_SOTO_PRIM_H
#define GUIA7_ARTURO_SOTO_PRIM_H

#include "GrafoMatriz.h"


class Prim {


protected :


    int ** T;
    int longMin;
    private:
    int n;
    int INFINITO;
    ofstream *archivo2;


public:
    int ** OT(){ return T;} // Arbol de expansión

    int OlongMin(){ return longMin;} // peso del Árbol expansión
    Prim(GrafoMatriz g);
// constructor
    int arbolExpansionPrim(GrafoMatriz g);
    // algoritmo de Prim

    void imprimirInicio();





};


#endif
