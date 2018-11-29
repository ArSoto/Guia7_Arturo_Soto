#include <iostream>
#include "GrafoMatriz.h"


using namespace std;

void menu(GrafoMatriz*);

void ordenDij(GrafoMatriz *);

int main(){


    int n;
    cin >> n;
    string nombre;
    GrafoMatriz *grafo;


    grafo = new GrafoMatriz(n);

    menu(grafo);


    return 0;
}

void menu (GrafoMatriz *grafo){

    int opcion = 0;
    int aux;
    string verticeA;
    string verticeB;



    while(opcion != 9){

        cout << "       MENU    " << endl;
        cout << endl;
        cout << "[1] Agregar Vertice" << endl;
        cout << "[2] Agregar arco (o arista) entre Vertices" << endl;
        cout << "[3] Dijkstra" << endl;
        cout << "[4] Generar grafico" << endl;
        cout << "[9] Salir" << endl;

        cin >> opcion;

        switch (opcion){

            case 1:
                cout << "Nombre del nuevo Vertice" << endl;
                cin >> verticeA;
                grafo->nuevoVertice(verticeA);

                break;
            case 2:
                cout << "Nombre del Vertice de inicio" << endl;
                cin >> verticeA;
                cout << "Nombre del Vertice de destino" << endl;
                cin >> verticeB;
                cout << "Distancia entre los vertices" << endl;
                cin >> aux;

                grafo->nuevoArco(verticeA, verticeB, aux );
                break;


            case 3:
                ordenDij(grafo);

                break;

            case 4:
                grafo ->imprimir();
                break;

            case 9:
                continue;

            default:
                cout <<"Numero no valido"<< endl;
                break;
        }


    }


}

