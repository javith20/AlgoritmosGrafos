#include <QCoreApplication>
#include "primdijkstra.h"
#include <iostream>
#include <string.h>
#include <cstring>
#include "primdijkstra.h"
using namespace std;

int main(int argc, char *argv[])
{
    PrimDijkstra algoritmos;
    int op = 0;
    char letra ;
    do{
       system("cls");
       letra='A';
       cout<<"---Tecnologico de Costa Rica---";
       cout<<"\n     Ing. Computación";
       cout<<"\n--- GRAFOS Kruskal, Prim  y Dijkstra---";
       cout<<"\nRealizado Por:";
       cout<<"\n\nJavith Aguero";
       cout<<"\nKendall Tencio";
       cout<<"\n\n-----MENU-----";
       cout<<"\n1. Listar Vertices con su lista de adyacencia.";
       cout<<"\n2. Algoritmo de Prim.";
       cout<<"\n3. Algoritmo de Dijkstra.";
       cout<<"\n4. Algoritmo de Kruskal.";
       cout<<"\n6. Salir";
       cout<<"\n\nDigite la Opcion:==>";
       cin>> op;
       switch (op) {
       case 1:
           algoritmos.listarAdyacencia();
           getch();
           break;
       case 2:
           cout << "Digite la letra donde empezar A-F"<<endl;
           cin>>letra;
           algoritmos.algoritmoPrim(letra);
           getch();
           break;
       case 3:
           cout << "Digite la letra donde empezar A-F"<<endl;
           cin>>letra;
           algoritmos.algoritmoDijkstra(letra);
            getch();
           break;
       case 4:
           algoritmos.algoritmoKruskal();
           getch();
           break;
       default:
           cout << "Error de numero" <<endl;
           break;
       }
    }while(op<6);

    return 0;
}
