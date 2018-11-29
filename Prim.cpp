#include "Prim.h"


Prim::Prim(GrafoMatriz g)
{
    n = g.OnumeroDeVertices();

    INFINITO = 0xFFFF;

    longMin = 0;


    T = new int *[n];

    for ( int i = 0 ; i < n; i++) {

        T[i] = new int [n];

        for(int j = 0; j < n; j++)

            T[i][j] = INFINITO;

    }
}


int Prim::arbolExpansionPrim(GrafoMatriz g)
{
    int menor;
    int  z;
    int *coste = new int [n];
    int * masCerca = new int [n];
    bool *W = new bool [n];

    ofstream archivo2;

    for (int i = 0; i < n; i++)     // conjunto vacío
        W[i] = false;


    W[0] = true;        //se parte del vértice 0

    imprimirInicio(archivo2);


// inicialmente, coste[i] es la arista (0,i)
    for (int i = 1; i < n; i++)
    {
        coste[i] = g.Ovalor(0, i);
        masCerca[i] = 0;
    }


    coste[0] = INFINITO;    //impide ciclo infinito


    for (int i = 1; i < n; i++){        // busca vértice z de V-W mas cercano de menor longitud de arista, a algún vértice de W
        menor = coste[1];
        z = 1;
        for (int j = 2; j < n; j++)
            if (coste[j] < menor) {
                menor = coste[j];
                z = j;
            }
        longMin += menor;

        // se escribe el arco incorporado al árbol de expansión


        archivo2 << g.nombreVertice(masCerca[z]) << " -> " << g.nombreVertice(z);
        archivo2 << "[label="<< g.Ovalor(masCerca[z], z) << "]"<< endl;

        W[z] = true;  //indica que el vector de la pocision z ya esta en el camino



        T[masCerca[z]][z] = T[z][masCerca[z]] = coste[z];

        coste[z] = INFINITO;

// debido a la incorporación de z,
// se ajusta coste[] para el resto de vértices

        for (int j = 1; j < n; j++)
            if ((g.Ovalor(z, j) < coste[j]) && !W[j])
            {
                coste[j] = g.Ovalor(z, j);
                masCerca[j] = z;
            }
    }
    imprimirCerrar(archivo2);
    return longMin;
}



void Prim::imprimirInicio(ofstream &archivo2) {


    /* Se abre/crea el archivo datos.txt, a partir de este se generará el grafo */
    archivo2.open("datos2.txt");

    /* Se escribe dentro del archivo datos.txt "digraph G { " */


    archivo2 << "digraph G {" << endl ;
    archivo2 << "graph [rankdir=LR]" << endl;

}



void Prim::imprimirCerrar(ofstream &archivo2) {

    archivo2 << "}" << endl;
    archivo2.close();

    /* genera el grafo */
    system("dot -Tpng -ografoprim.png datos2.txt &");

}