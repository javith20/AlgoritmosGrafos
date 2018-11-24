#include "primdijkstra.h"

PrimDijkstra::PrimDijkstra()
{

}

void crearVertice (char valor) {
     if (pri == NULL){
        pri = new vertice;
        //cout << "El Grafo no tiene vertices\nDigite la letra del Primer Nodo: ";
        pri->nod = valor;
        pri->marca = 0;
        pri->arc = NULL;
        pri->sig = NULL;
        ult = pri;
        cout << "\nNodo registrado correctamente.";
     }
     else {
          cout << "Digite la letra del vertice: ";
          let = valor;
          do {
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
          }while (ban == 1);
          nue = new vertice;
          nue->nod = let;
          nue->marca = 0;
          nue->sig = NULL;
          nue->arc = NULL;
          ult->sig = nue;
          ult = nue;
          cout << "\nNodo registrado correctamente.";

     }

     ////getch();
}

void enlazarVertices (char inicioNodo,char finNodo,int valor) {
     system ("cls");
     if (pri != NULL){
        aux = pri;
        while (aux != NULL){
              cout << aux->nod << "\n";
              aux = aux->sig;
        }
        cout << "\nDigite la letra del nodo al cual desea enlazar: ";
         auxNod = inicioNodo; /// Guarda el valor del nodo inicial
        ban = 0;
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
        }
        cout << "\nDigite la letra del nodo al cual desea enlazar el nodo elegido: ";
        auxNod2=finNodo;
        ban = 0;
        while (ban == 0){
              aux = pri;
              while (auxNod2 == auxNod){
                    cout << "\nNo se puede hacer ese enlace\nDigite otro nodo disponible: ";
                    cin >> auxNod2;
              }
              while (aux != NULL && ban == 0){
                   if (aux->nod == auxNod2){
                      ban = 1;
                   }
                   aux = aux->sig;
              }
              if (ban == 0){
                 cout << "\nEl nodo no existe\nPor favor digite uno de los listados anteriormente: ";
                 cin >> auxNod2;
              }
        }
        aux = pri;
        while (aux->nod != auxNod){
              aux = aux->sig;
        }
        auxArc = aux->arc;
        ban3 = 0;
        while (auxArc != NULL && ban3 == 0){
              if (auxArc->ver->nod == auxNod2){
                 ban3 = 1;
              }
              auxArc = auxArc->sig;
        }
        if (ban3 == 0){
           enlazar(valor);
           cout << "\nEnlace creado correctamente.";
        }
        else {
             cout << "\nEse enlace ya existe. Compruebe el enlace la proxima vez.";
        }
     }
}

void enlazar (int valor){
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
           cout << "\nDigite el valor del enlace: ";
           enlace = valor; // Asigna el valor del peso
           while (nueArc->clave < 0){
                 cout << "\nEl valor debe ser positivo\nDigite el valor del enlace: ";
                 cin >> enlace;
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
           cout << "\nDigite el valor del enlace: ";
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

void obtenerArcoMenor () {
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

void obtenerSumaMenor () {
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

void paso2 (){
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

void paso2Dijkstra () {
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

void algoritmoPrim (char vertice) {
     system("cls");
     if (pri != NULL){
            actualizarCampos();
            cout << "Digite el vertice inicial: ";
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

void listarAdyacencia () {
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

void sumaCaminos () {
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

void listarAdyacenciaPrim () {
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

void liberarMemoria () {
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


void algoritmoDijkstra (char vertice ) {
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
void cargarArchivo(){
    a.leer("C:/Users/Javith/Documents/AlgoritmosGrafos/1.txt");
    cout << a.getTextoStr() << endl;
    int dimension = a.getCantVariables();
    int matriz[4][4];
    a.cargarMatriz(matriz);
    int op = 0;
    for(int letra=65; letra<69 ; letra++)
        crearVertice(letra);

    for(int fila = 65; fila <69 ; fila++)
        for(int columna = 65; columna < 69 ;columna++)
            if(matriz[fila-65][columna-65]!=999 && fila !=columna)
                enlazarVertices(fila,columna,matriz[fila-65][columna-65]);

}
void actualizarCampos () {
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

main (){
    cargarArchivo();



    algoritmoDijkstra('A');
}
    /*
    do{
       system("cls");
       cout<<"---UNIVERSIDAD DE NARIÑO---";
       cout<<"\n---FACULTAD DE INGENIERIA---";
       cout<<"\n     INGENIERIA DE SISTEMAS";
       cout<<"\n---TALLER 03. GRAFOS---";
       cout<<"\nRealizado Por:";
       cout<<"\n\nMario Florez";
       cout<<"\nMarcelo Tabango";
       cout<<"\n\n-----MENU-----";
       cout<<"\n1. Crear Vertices.";
       cout<<"\n2. Enlazar Vertices.";
       cout<<"\n3. Listar Vertices con su lista de adyacencia.";
       cout<<"\n4. Algoritmo de Prim.";
       cout<<"\n5. Algoritmo de Dijkstra.";
       cout<<"\n6. Liberar Memoria.";
       cout<<"\n7. Salir";
       cout<<"\n\nDigite la Opcion:==>";
       cin>>op;
       while (op>7){
             cout << "Esa opcion no existe digite un numero del 1 al 7: ";
             cin >> op;
       }
       switch(op){
                  case 1: crearVertice('a'); break;
                  case 2: enlazarVertices('a','a',1); break;////getch();
                  case 3: listarAdyacencia(); break;
                  case 4: algoritmoPrim(); break;
                  case 5: algoritmoDijkstra(); break;
                  case 6: liberarMemoria (); break;
                  case 7: exit (0);
       }
    }while(op<7);
}*/


