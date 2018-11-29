#include "Vertice.cpp"
#include <fstream>
#include "string"
#include <iostream>
using namespace std;

#ifndef GRAFOMATRIZ_H
#define GRAFOMATRIZ_H

class GrafoMatriz {


protected:
    int maxVerts;       // máximo numero de vértices
    int numVerts;       // número de vértices actual
    Vertice * verts;    // array de vértices
    int ** matriz;       // matriz de adyacencia



public:
    //Constructores
    GrafoMatriz(int mx);

    //metodos encargados de obtener el número de vértices
    // y de cambiar el número de vértices de la clase

    int infinito;


    //agrega nuevo vertice
    void nuevoVertice (string nom);

    string nombreVertice(int);

    //Busca si hay un vertice con el nombre del parametro otorgado
    int numVertice(string v);

    int OnumeroDeVertices();

    void nuevoArco(string, string, int valor);

    int Ovalor( int va, int vb);

    void imprimir();

    string OnombreVertice(int);




private:   // métodos privados de la clase GrafoMariz

    void auxImprimir(ofstream&);

};

#endif
