#include "kruskal.h"

Kruskal::Kruskal()
{

}

// Extraido de : https://xcodigoinformatico.blogspot.com/2012/09/algoritmo-de-kruskal-arbol-de-expansion.html
void Kruskal::initSet(int size)
{
    int i;
    pset.resize(size);
    REP(i,size+1)
        pset[i]=i;
}

int Kruskal::findSet(int i)
{
    return (pset[i]==i)? i:(pset[i]=findSet(pset[i]));
}

void Kruskal::unionSet(int i,int j)
{
    pset[findSet(i)]=findSet(j);
}

bool Kruskal::isSameSet(int i,int j)
{
    if(findSet(i) == findSet(j))
        return true;
    return false;
}

void  Kruskal::kruskal(int N)
{
    int sum=0,i=0;
    initSet(N);
    sort(grafo.begin(),grafo.end());

    for(i=0;i<grafo.size();i++)
    {      pair<int,ii>aux=grafo[i];
        if(!isSameSet(aux.second.first,aux.second.second))
        {   char x =aux.second.first+65;
            char y =aux.second.second+65;
            cout<<"pasa en: "<<x<<","<<y<<endl;
            sum=aux.first+sum;
            unionSet(aux.second.first,aux.second.second);
        }
    }
    cout<<"El peso "<<sum<<endl;
}
