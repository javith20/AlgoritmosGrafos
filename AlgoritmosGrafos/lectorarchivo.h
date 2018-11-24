#ifndef LECTORARCHIVO_H
#define LECTORARCHIVO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "listaenlazada.h"
using namespace std;
class LectorArchivo
{
public:
    LectorArchivo();
    void LeerArchivos();
    void leer(string rutaStr);
    void cargarMatriz(int matriz[4][4] );
    string getTextoStr();
    int getCantVariables();
private:
   void calcularCantVariables();
   string textoStr;
   int cantVariables;
};

#endif // LECTORARCHIVO_H
