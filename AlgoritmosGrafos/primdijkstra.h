#ifndef PRIMDIJKSTRA_H
#define PRIMDIJKSTRA_H


class PrimDijkstra
{
public:
    PrimDijkstra();
};


# include <iostream>
# include <conio.h>
# include <stdio.h>
# include <stdlib.h>
# include "lectorarchivo.h"
using namespace std;
LectorArchivo a;
struct vertice {
       char nod;
       int marca;
       struct vertice *sig;
       struct arco *arc;
};

struct arco {
       struct vertice *ver;
       int marca;
       int suma;
       int clave;
       struct arco *sig;
};


struct vertice *pri, *nue, *aux, *ult, *aux2;
struct arco *nueArc, *auxArc, *arcMen, *auxArc2, *antArc;
char auxNod, auxNod2, ban2, let;
int ban, enlace, ban3, ban4, numVer;

void actualizarCampos ();
void crearVertice(char valor);
void enlazarVertices(char inicioNodo,char finNodo,int valor);
void enlazar(int valor);
void listarAdyacencia();
void obtenerArcoMenor();
void listarAdyacenciaPrim ();
void sumaCaminos();
void cargarArchivo();
#endif // PRIMDIJKSTRA_H
