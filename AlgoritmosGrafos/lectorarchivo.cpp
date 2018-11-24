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
void LectorArchivo::cargarMatriz(int matriz[4][4])
{
    string valorStr;
    int indice=0;
    if(this->textoStr!="")
    {
        for(int fila = 0; fila <cantVariables ; fila++)
        {
            for(int columna = 0; columna <cantVariables ; columna++ )
            {
                valorStr="";
                while(this->textoStr[indice]!=',' && this->textoStr[indice]!='\n')
                {
                    valorStr+=this->textoStr[indice++];
                }
                indice++;
                matriz[fila][columna]= atoi(valorStr.c_str());
            }
        }


    }
}
int LectorArchivo::getCantVariables()
{
    return cantVariables;
}
string LectorArchivo::getTextoStr()
{
    return textoStr;
}

