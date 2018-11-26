#ifndef PRIMDIJKSTRA_H
#define PRIMDIJKSTRA_H
#include "kruskal.h"
# include <iostream>
# include <conio.h>
# include <stdio.h>
# include <stdlib.h>
# include "lectorarchivo.h"
using namespace std;
struct vertice {
       char nod;
       int marca=0;
       struct vertice *sig;
       struct arco *arc;
};
struct arco {
       struct vertice *ver;
       int marca=0;
       int suma=0;
       int clave=0;
       struct arco *sig;
};

class PrimDijkstra
{
public:
    PrimDijkstra();
    void algoritmoPrim (char vertice);
    void algoritmoDijkstra(char vertice);
    void algoritmoKruskal();
    void listarAdyacencia();
private:
    Kruskal kruskal;
    struct vertice *pri=NULL, *nue=NULL, *aux=NULL, *ult=NULL, *aux2=NULL;
    struct arco *nueArc=NULL, *auxArc=NULL, *arcMen=NULL, *auxArc2=NULL, *antArc=NULL;
    char auxNod=NULL, auxNod2=NULL, ban2=NULL, let=NULL;
    int ban=0, enlace=0, ban3=0, ban4=0, numVer=0;
    LectorArchivo lectorArchivos;
    void actualizarCampos ();
    void crearVertice(char valor);
    void enlazarVertices(char inicioNodo,char finNodo,int valor);
    void enlazar(int valor);

    void obtenerArcoMenor();
    void listarAdyacenciaPrim ();
    void sumaCaminos();
    void cargarArchivo();
    void obtenerSumaMenor ();
    void paso2 ();
    void paso2Dijkstra();
    void liberarMemoria ();

};





#endif // PRIMDIJKSTRA_H
