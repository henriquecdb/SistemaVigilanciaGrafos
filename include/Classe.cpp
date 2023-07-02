#include "Classe.h"

using namespace std;

Grafo::Grafo(int numVertices) { grafo.resize(numVertices); }

Grafo::Grafo(const string &nomeArquivo) {
  ifstream arquivo(nomeArquivo);
  if (arquivo.is_open()) {
    int numVertices, origem, destino;
    arquivo >> numVertices;

    grafo.resize(numVertices);

    while (arquivo >> origem >> destino) {
      adicionarAresta(origem, destino);
    }
    arquivo.close();
  } else {
    cerr << "Erro ao abrir o arquivo." << endl;
  }
}

void Grafo::adicionarAresta(int origem, int destino) {
  grafo[origem].push_back(destino);
  grafo[destino].push_back(origem);
}

void Grafo::imprimirGrafo() {
  for (int i = 0; i < grafo.size(); i++) {
    cout << "Vértice " << i << ": ";
    for (int j = 0; j < grafo[i].size(); j++) {
      cout << grafo[i][j] << " ";
    }
    cout << endl;
  }
}

void Grafo::encontrarCamerasAproximado() {
  cameras.clear();
  vector<bool> arestasCobertas(grafo.size(), false);
  while (!todasArestasCobertas(arestasCobertas)) {
    int maxGrau = -1;
    set<int> verticesSelecionados;
    // Calcula o maior grau
    for (int i = 0; i < grafo.size(); i++) {
      if (!arestasCobertas[i]) {
        int grau = 0;
        for (int adjacente : grafo[i]) {
          if (!arestasCobertas[adjacente]) {
            grau++;
          }
        }
        if (grau > maxGrau) {
          maxGrau = grau;
        }
      }
    }
    // Seleciona todos os vértices com o maior grau
    for (int i = 0; i < grafo.size(); i++) {
      if (!arestasCobertas[i]) {
        int grau = 0;
        for (int adjacente : grafo[i]) {
          if (!arestasCobertas[adjacente]) {
            grau++;
          }
        }
        if (grau == maxGrau) {
          verticesSelecionados.insert(i);
        }
      }
    }
    // Marca as arestas adjacentes aos vértices selecionados como cobertas
    for (int vertice : verticesSelecionados) {
      cameras.insert(vertice);
      arestasCobertas[vertice] = true;
      for (int adjacente : grafo[vertice]) {
        arestasCobertas[adjacente] = true;
      }
    }
  }
}

bool Grafo::todasArestasCobertas(const vector<bool> &arestasCobertas) {
  for (bool coberta : arestasCobertas) {
    if (!coberta) {
      return false;
    }
  }
  return true;
}

void Grafo::imprimirCameras() {
  cout << "Câmeras instaladas: ";
  for (auto camera : cameras) {
    cout << camera << " ";
  }
  cout << endl;
}
