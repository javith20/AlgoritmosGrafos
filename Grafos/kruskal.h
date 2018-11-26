#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include<stdio.h>
#include<conio.h>
#define DEBUG
#define REP(i,a)  for(i=0;i<a;i++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define ii pair<int,int>

using namespace std;


class Kruskal
{
public:

    Kruskal();
    void  kruskal(int N);
    vector<int> pset;
    vector<pair<int,ii> >grafo;
private:
    void initSet(int size);
    int findSet(int i);
    void unionSet(int i,int j);
    bool isSameSet(int i,int j);
    void loadData(int);


};

#endif // KRUSKAL_H
