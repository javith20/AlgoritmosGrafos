#include "lectorarchivo.h"

LectorArchivo::LectorArchivo()
{
    textoStr="";
    cantVariables =0;

}
void LectorArchivo::leer(string rutaStr)
{
    FILE *archivo;
    archivo = fopen(rutaStr.c_str(),"r+");
    char caracter;
    if (archivo == NULL)
    {
                printf("\nError de apertura del archivo. \n\n");
    }else{
        while((caracter = fgetc(archivo)) !=EOF )
            this->textoStr+=caracter;
        calcularCantVariables();
    }
    fclose(archivo);
}
void LectorArchivo::calcularCantVariables()
{
    int i=-1;
    string valorStr="";
    while(textoStr[i]!='\n')
    {
        i++;
        while(textoStr[i]!=',' && textoStr[i] !='\n')
        {
        valorStr +=textoStr[i++];

        }
        this->cantVariables++;

    }
}
void LectorArchivo::cargarMatriz(int matriza[6][6])
{

}
int LectorArchivo::getCantVariables()
{
    return cantVariables;
}
string LectorArchivo::getTextoStr()
{
    return textoStr;
}

