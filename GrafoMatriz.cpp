#include "GrafoMatriz.h"

typedef int * pint;  // para el dimensionamiento de la matriz

GrafoMatriz::GrafoMatriz(int mx) {
    maxVerts = mx;
    verts = new Vertice[mx] ;
    matriz = new pint[mx];
    numVerts = 0;


    for (int i = 0; i < mx; i++) {       //crea y prepara la matriz;
        matriz[i] = new int[mx];
        for (int j = 0; j <mx ; ++j) {
            (i==j) ? matriz[i][j] = 0 : matriz[i][j] = -1;
        }
    }
}

void GrafoMatriz::nuevoVertice (string nom){

    bool esta = numVertice(nom) >= 0; //si el Vertice se encuentra ya en el grafo
    if (!esta){
        if(numVerts < maxVerts) {    // comprueba que no sobrepase el máximo

            Vertice v;
            v.nombre = nom;
            v.numVertice = numVerts;
            verts[numVerts++] = v; // se asigna a la lista.


        } else{
            cout <<"El grafo ya no recibe Vertices, maximo alcanzado." << endl;
        }

    } else{
        cout << "Ya existe un Vertice con ese nombre." << endl;
    }
}

int GrafoMatriz::numVertice(string v){

    int i = 0;
    bool encontrado = false;

    while(i < numVerts && !encontrado){
        encontrado = (verts[i].nombre == v);
        if (!encontrado) {
            i++;
        }
    }
    return (i < numVerts) ? i : -1 ;
}


void GrafoMatriz::nuevoArco(string a, string b, int valor) {
    int va, vb;
    va = numVertice(a);
    vb = numVertice(b);
    matriz[va][vb] = valor;
}


int GrafoMatriz::Ovalor( int va, int vb) {
    if (va < 0 || vb < 0 || va >= numVerts || vb >= numVerts){
       cout << "hay camino entre esos vetores"<< endl;
        return -1;
    }
    return matriz[va][vb];
}

string GrafoMatriz::nombreVertice(int i) {

    return verts[i].nombre;
}

void GrafoMatriz::imprimir() {

    ofstream archivo;
    /* Se abre/crea el archivo datos.txt, a partir de este se generará el grafo */
    archivo.open("datos.txt");

    /* Se escribe dentro del archivo datos.txt "digraph G { " */
    archivo << "digraph G {" << endl ;
    archivo << "graph [rankdir=LR]" << endl;

    auxImprimir(archivo); //Recorre la matriz para imprimir el grafico

    archivo << "}" << endl;
    archivo.close();

    /* genera el grafo */
   system("dot -Tpng -ografo.png datos.txt &");

}

void GrafoMatriz::auxImprimir(ofstream &archivo) {

    for (int i = 0; i < numVerts ; ++i) {
        for (int j = 0; j <numVerts ; ++j) {

            if(matriz[i][j] > 0){

                archivo <<  verts[i].nombre << " -> " << verts[j].nombre;
                archivo << "[label=" << matriz[i][j] << "];"<< endl;
            }

        }

    }

}

int GrafoMatriz::OnumeroDeVertices() {
    return numVerts;
}










