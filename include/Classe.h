#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

class Grafo
{
private:
    vector<vector<int>> grafo;
    set<int> cameras;

public:
    Grafo(int numVertices);
    Grafo(const string &nomeArquivo);
    void adicionarAresta(int origem, int destino);
    void imprimirGrafo();
    void encontrarCameras();
    void imprimirCameras();
};

#endif
