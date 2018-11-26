#include "primdijkstra.h"

PrimDijkstra::PrimDijkstra()
{
    //A=65 B=66 C=67 D=68 E=69 F=70
    /*
    for(int letra=65; letra<71 ; letra++)
        crearVertice(letra);
    enlazarVertices('A','B',2);
    enlazarVertices('A','D',1);
    enlazarVertices('A','F',6);
    enlazarVertices('A','E',3);
    enlazarVertices('B','C',2);
    enlazarVertices('B','D',3);
    enlazarVertices('C','D',4);
    enlazarVertices('F','E',4);*/
    cargarArchivo();

}

void PrimDijkstra::crearVertice (char valor) {
     if (pri == NULL){
        pri = new vertice;
        pri->nod = valor;
        pri->marca = 0;
        pri->arc = NULL;
        pri->sig = NULL;
        ult = pri;

     }
     else {

          let = valor;
          /*do {
              aux = pri;
              ban = 0;
              while (aux != NULL){
                    if (aux->nod == let){
                          ban = 1;
                    }
                    aux = aux->sig;
              }
              if (ban == 1) {
                     cout << "\nEsa letra clave ya fue usada, igual que las siguientes:\n";
                     aux = pri;
                     while (aux != NULL) {
                           cout << aux->nod << " ";
                           aux = aux->sig;
                     }
                     cout << "\nDigita una letra diferente: ";
                     cin >> let;
              }
          }while (ban == 1);*/
          nue = new vertice;
          nue->nod = let;
          nue->marca = 0;
          nue->sig = NULL;
          nue->arc = NULL;
          ult->sig = nue;
          ult = nue;

     }

}

void PrimDijkstra::enlazarVertices (char inicioNodo,char finNodo,int valor) {
     if (pri != NULL){
        aux = pri;
        /*while (aux != NULL){
              cout << aux->nod << "\n";
              aux = aux->sig;
        }
        cout << "\nDigite la letra del nodo al cual desea enlazar: ";
        */
        auxNod = inicioNodo; /// Guarda el valor del nodo inicial
        /*ban = 0;
        while (ban == 0){
              aux = pri;
              while (aux != NULL && ban == 0){
                   if (aux->nod == auxNod){
                      ban = 1;
                   }
                   aux = aux->sig;
              }
              if (ban == 0){
                 cout << "\nEl nodo no existe\nPor favor digite uno de los listados anteriormente: ";
                 cin >> auxNod;
              }
        }
        cout << "\nEstos son los nodos disponibles para hacer el respectivo enlace:\n";
        aux = pri;
        aux2 = pri;
        while (aux2->nod != auxNod){
              aux2 = aux2->sig;
        }
        while (aux != NULL){
              if (aux->nod != auxNod){
                  auxArc = aux2->arc;
                  ban4 = 0;
                  while (auxArc != NULL && ban4 == 0){
                        if (aux->nod == auxArc->ver->nod){
                           ban4 = 1;
                        }
                        auxArc = auxArc->sig;
                  }
                  if (ban4 == 0){
                     cout << aux->nod << "\n";
                  }
              }

              aux = aux->sig;
        }*/
       // cout << "\nDigite la letra del nodo al cual desea enlazar el nodo elegido: ";
        auxNod2=finNodo;
        ban = 0;
        while (ban == 0){
              aux = pri;
              /*
              while (auxNod2 == auxNod){
                    cout << "\nNo se puede hacer ese enlace\nDigite otro nodo disponible: ";
                    cin >> auxNod2;
              }*/
              while (aux != NULL && ban == 0){
                   if (aux->nod == auxNod2){
                      ban = 1;
                   }
                   aux = aux->sig;
              }/*
              if (ban == 0){
                 cout << "\nEl nodo no existe\nPor favor digite uno de los listados anteriormente: ";
                 cin >> auxNod2;
              }*/
        }
        aux = pri;
        /*
        while (aux->nod != auxNod){
              aux = aux->sig;
        }*/
        auxArc = aux->arc;
        ban3 = 0;
        /*
        while (auxArc != NULL && ban3 == 0){
              if (auxArc->ver->nod == auxNod2  ){
                 ban3 = 1;
              }
              auxArc = auxArc->sig;
        }*/
        if (ban3 == 0){
           enlazar(valor);
           //cout << "\nEnlace creado correctamente.";
        }
        else {
             cout << "\nEse enlace ya existe. Compruebe el enlace la proxima vez.";
        }
     }
}

void PrimDijkstra::enlazar (int valor){
        aux = pri;
        while (aux->nod != auxNod){
              aux = aux->sig;
        }
        aux2 = pri;
        while (aux2->nod != auxNod2){
              aux2 = aux2->sig;
        }
        if (aux->arc == NULL){
           nueArc = new arco;
           nueArc->ver = aux2;
           enlace = valor; // Asigna el valor del peso
           while (nueArc->clave < 0){
                 cout << "\nEl valor debe ser positivo\nDigite el valor del enlace: ";
                 enlace = valor;
           }
           nueArc->clave = enlace;
           nueArc->marca = 0;
           nueArc->suma = 0;
           nueArc->sig = NULL;
           aux->arc = nueArc;
           if (aux2->arc == NULL){
               nueArc = new arco;
               nueArc->ver = aux;
               nueArc->clave = enlace;
               nueArc->marca = 0;
               nueArc->suma = 0;
               nueArc->sig = NULL;
               aux2->arc = nueArc;
            }
            else {
               nueArc = new arco;
               nueArc->ver = aux;
               nueArc->clave = enlace;
               nueArc->marca = 0;
               nueArc->suma = 0;
               nueArc->sig = NULL;
               auxArc = aux2->arc;
               while (auxArc->sig != NULL){
                     auxArc = auxArc->sig;
               }
               auxArc->sig = nueArc;
            }
        }
        else {
           nueArc = new arco;
           nueArc->ver = aux2;
          // cout << "\nDigite el valor del enlace: ";
            enlace = valor; // Asigna el valor del peso
           while (enlace < 0){
                 cout << "\nEl valor debe ser positivo\nDigite el valor del enlace: ";
                 cin >> enlace;
           }
           nueArc->clave = enlace;
           nueArc->marca = 0;
           nueArc->suma = 0;
           nueArc->sig = NULL;
           auxArc = aux->arc;
           while (auxArc->sig != NULL){
                 auxArc = auxArc->sig;
           }
           auxArc->sig = nueArc;
           if (aux2->arc == NULL){
               nueArc = new arco;
               nueArc->ver = aux;
               nueArc->clave = enlace;
               nueArc->marca = 0;
               nueArc->suma = 0;
               nueArc->sig = NULL;
               aux2->arc = nueArc;
            }
            else {
               nueArc = new arco;
               nueArc->ver = aux;
               nueArc->clave = enlace;
               nueArc->marca = 0;
               nueArc->suma = 0;
               nueArc->sig = NULL;
               auxArc = aux2->arc;
               while (auxArc->sig != NULL){
                     auxArc = auxArc->sig;
               }
               auxArc->sig = nueArc;
            }
        }
}

void PrimDijkstra::obtenerArcoMenor () {
     aux2 = pri;
     arcMen = NULL;
     while (aux2 != NULL){
           if (aux2->marca == 1){
                      auxArc = aux2->arc;
                      while (auxArc != NULL){
                            if (auxArc->marca == 1){
                                  if (arcMen == NULL){
                                         arcMen = auxArc;
                                  }
                                  else{
                                       if (auxArc->clave < arcMen->clave){
                                              arcMen = auxArc;
                                       }
                                  }
                            }
                            auxArc = auxArc->sig;
                      }
           }
           aux2 = aux2->sig;
     }
     arcMen->marca = 3;
     arcMen->ver->marca = 1;
}

void PrimDijkstra::obtenerSumaMenor () {
     aux2 = pri;
     arcMen = NULL;
     while (aux2 != NULL){
           if (aux2->marca == 1){
                      auxArc = aux2->arc;
                      while (auxArc != NULL){
                            if (auxArc->marca == 1){
                                  if (arcMen == NULL){
                                         arcMen = auxArc;
                                  }
                                  else{
                                       if (auxArc->suma < arcMen->suma){
                                              arcMen = auxArc;
                                       }
                                  }
                            }
                            auxArc = auxArc->sig;
                      }
           }
           aux2 = aux2->sig;
     }
     arcMen->marca = 3;
     arcMen->ver->marca = 1;
     auxArc = arcMen->ver->arc;
     while (auxArc != NULL){
           auxArc->suma = arcMen->suma + auxArc->clave;
           auxArc = auxArc->sig;
     }
}

void PrimDijkstra::paso2 (){
            obtenerArcoMenor();
            cout << "\nEl arco menor es: "<< arcMen->ver->nod << " vale: " << arcMen->clave;
            //////getch();
            aux = arcMen->ver;
            auxArc = aux->arc;
            while (auxArc != NULL){
                  if (auxArc->ver->marca == 0){
                         aux2 = pri;
                         while (aux2 != NULL){
                               if (aux2 != aux && aux2->marca == 1){
                                     auxArc2 = aux2->arc;
                                     while (auxArc2 != NULL){
                                           if (auxArc->ver->nod == auxArc2->ver->nod){
                                                  if (auxArc->clave < auxArc2->clave){
                                                         auxArc2->marca = 2;
                                                         auxArc->marca = 1;
                                                  }
                                                  else {
                                                       auxArc->marca = 2;
                                                       auxArc2->marca = 1;
                                                  }
                                           }
                                           auxArc2 = auxArc2->sig;
                                     }
                               }
                               aux2 = aux2->sig;
                         }
                         if (auxArc->marca == 0){
                                auxArc->marca = 1;
                         }
                  }
                  else {
                       auxArc->marca = 2;
                  }
                  auxArc = auxArc->sig;
            }
}

void PrimDijkstra::paso2Dijkstra () {
            obtenerSumaMenor();
            cout << "\nLa sumatoria hasta el arco " << arcMen->ver->nod << " es: "<< arcMen->suma;
            ////getch();
            aux = arcMen->ver;
            auxArc = aux->arc;
            while (auxArc != NULL){
                  if (auxArc->ver->marca == 0){
                         aux2 = pri;
                         while (aux2 != NULL){
                               if (aux2 != aux && aux2->marca == 1){
                                     auxArc2 = aux2->arc;
                                     while (auxArc2 != NULL){
                                           if (auxArc->ver->nod == auxArc2->ver->nod){
                                                  if (auxArc->suma  < auxArc2->suma){
                                                         auxArc2->marca = 2;
                                                         auxArc->marca = 1;
                                                  }
                                                  else {
                                                       auxArc->marca = 2;
                                                       auxArc2->marca = 1;
                                                  }
                                           }
                                           auxArc2 = auxArc2->sig;
                                     }
                               }
                               aux2 = aux2->sig;
                         }
                         if (auxArc->marca == 0){
                                auxArc->marca = 1;
                                auxArc->suma = arcMen->suma + auxArc->clave;
                         }
                  }
                  else {
                       auxArc->marca = 2;
                  }
                  auxArc = auxArc->sig;
            }
}

void PrimDijkstra::algoritmoPrim (char vertice) {
     system("cls");
     if (pri != NULL){
            actualizarCampos();
            auxNod= vertice;
            ban = 0;
            while (ban == 0){
                  aux = pri;
                  while (aux != NULL){
                        if (aux->nod == auxNod){
                               ban = 1;
                        }
                        aux = aux->sig;
                  }
                  if (ban == 0){
                         cout << "\nNo existe un nodo con esa letra.";
                         aux = pri;
                         cout << "\n---Lista de Nodos---\n";
                         while (aux != NULL){
                               cout << aux->nod << " ";
                               aux = aux->sig;
                         }
                         cout << "\nDigite uno de los anteriores nodos: ";
                         cin >> auxNod;
                  }
            }
            aux = pri;
            while (aux->nod != auxNod){
                  aux = aux->sig;
            }
            aux->marca = 1;
            auxArc = aux->arc;
            while (auxArc != NULL){
                  auxArc->marca = 1;
                  auxArc = auxArc->sig;
            }
            cout << "\nSe han marcado todos los arcos para el vertice elegido.";
            ban2 = 1;
            while (ban2 == 1){
                  paso2();
                  ban2 = 0;
                  aux = pri;
                  while (aux != NULL){
                        if (aux->marca == 0){
                               ban2 = 1;
                        }
                        aux = aux->sig;
                  }
            }
            listarAdyacenciaPrim ();
            sumaCaminos();
     }
     ////getch();
}

void PrimDijkstra::listarAdyacencia () {
     system ("cls");
     if (pri != NULL){
        aux = pri;
        cout << "---Lista de Adyacencia---\n";
        while (aux != NULL){
              auxArc = aux->arc;
              cout << "\n|\n" << aux->nod << "->";
              while (auxArc != NULL){
                    cout << auxArc->ver->nod << " ";
                    auxArc = auxArc->sig;
              }
              aux = aux->sig;
        }
        ////getch();
     }
}

void PrimDijkstra::sumaCaminos () {
     aux = pri;
     int suma = 0;
     while (aux != NULL){
           auxArc = aux->arc;
           while (auxArc != NULL){
                 if (auxArc->marca == 3){
                        suma = suma + auxArc->clave;
                 }
                 auxArc = auxArc->sig;
           }
           aux = aux->sig;
     }
     cout << "\nLa suma de los caminos es: " << suma;
}

void PrimDijkstra::listarAdyacenciaPrim () {
     if (pri != NULL){
        aux = pri;
        cout << "\n---Lista de Adyacencia---\n";
        while (aux != NULL){
              auxArc = aux->arc;
              cout << "\n|\n" << aux->nod << "->";
              while (auxArc != NULL){
                    if (auxArc->marca == 3)
                    cout << auxArc->ver->nod << " ";
                    auxArc = auxArc->sig;
              }
              aux = aux->sig;
        }
     }
}

void PrimDijkstra::liberarMemoria () {
     if (pri != NULL){
        aux = pri;
        while (aux != NULL){
              auxArc = aux->arc;
              while (auxArc != NULL){
                    aux->arc = aux->arc->sig;
                    delete auxArc;
                    auxArc = aux->arc;
              }
              pri = pri->sig;
              delete aux;
              aux = pri;
        }
     }
     cout << "Memoria Libre";
     ////getch();
}

void PrimDijkstra::algoritmoDijkstra (char vertice ) {
     system("cls");
     if (pri != NULL){
            actualizarCampos ();
            cout << "Digite el vertice inicial: ";
            auxNod = vertice;
            ban = 0;
            while (ban == 0){
                  aux = pri;
                  while (aux != NULL){
                        if (aux->nod == auxNod){
                               ban = 1;
                        }
                        aux = aux->sig;
                  }
                  if (ban == 0){
                         cout << "\nNo existe un nodo con esa letra.";
                         aux = pri;
                         cout << "\n---Lista de Nodos---\n";
                         while (aux != NULL){
                               cout << aux->nod << " ";
                               aux = aux->sig;
                         }
                         cout << "\nDigite uno de los anteriores nodos: ";
                         cin >> auxNod;
                  }
            }
            aux = pri;
            while (aux->nod != auxNod){
                  aux = aux->sig;
            }
            aux->marca = 1;
            auxArc = aux->arc;
            while (auxArc != NULL){
                  auxArc->marca = 1;
                  auxArc->suma = auxArc->clave;
                  auxArc = auxArc->sig;
            }
            cout << "\nSe han trazado todos los arcos para el vertice elegido.";
            ban2 = 1;
            while (ban2 == 1){
                  paso2Dijkstra();
                  ban2 = 0;
                  aux = pri;
                  while (aux != NULL){
                        if (aux->marca == 0){
                               ban2 = 1;
                        }
                        aux = aux->sig;
                  }
            }
            listarAdyacenciaPrim ();
     }
     ////getch();
}

void PrimDijkstra::actualizarCampos () {
     aux = pri;
     while (aux != NULL){
           auxArc = aux->arc;
           while (auxArc != NULL){
                 auxArc->marca = 0;
                 auxArc->suma = 0;
                 auxArc = auxArc->sig;
           }
           aux->marca = 0;
           aux = aux->sig;
     }
}

void PrimDijkstra::cargarArchivo(){
    lectorArchivos.leer("C:/Users/Javith/Documents/GitHub/AlgoritmosGrafos/AlgoritmosGrafos/1.txt");
    /*----------------------------Cargar Matriz---------
    Esta funcion debe ir aparte pero por problemas con la matriz la
    voy a dejar por aca.
    */
    int matriz[6][6];
    string valorStr;
    int indice=0;
    string textoStr =this->lectorArchivos.getTextoStr();
    if( textoStr !="")
    {
        for(int fila = 0; fila <this->lectorArchivos.getCantVariables() ; fila++)
        {
            for(int columna = 0; columna <this->lectorArchivos.getCantVariables() ; columna++ )
            {
                valorStr="";
                while(textoStr[indice]!=',' && textoStr[indice]!='\n')
                {
                    valorStr+=textoStr[indice++];
                }
                indice++;
                matriz[fila][columna]= atoi(valorStr.c_str());
            }
        }

    }

    //---------------------------------------------------------
    lectorArchivos.cargarMatriz(matriz);
    int op = 0;
    for(int letra=65; letra<71 ; letra++)
        crearVertice(letra);
    int valorColumna=66;
    for(int fila = 65; fila <71 ; fila++)
    {
        for(int columna = valorColumna++; columna < 71 ;columna++)
            if(matriz[fila-65][columna-65]!=0 && fila !=columna)
            {
                enlazarVertices(fila,columna,matriz[fila-65][columna-65]);
                kruskal.grafo.push_back(pair<int,ii>(matriz[fila-65][columna-65],ii(fila-65,columna-65)));
            }

    }




}

void PrimDijkstra::algoritmoKruskal(){
    kruskal.kruskal(8);
}


