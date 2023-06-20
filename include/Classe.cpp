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

void Grafo::encontrarCameras()
{
  cameras.clear();

  vector<bool> corredorCoberto(grafo.size(), false);

  for (int i = 0; i < grafo.size(); i++)
  {
    bool cobreCorredor = false;

    for (int j = 0; j < grafo[i].size(); j++)
    {
      int corredor = grafo[i][j];

      if (!corredorCoberto[corredor])
      {
        cobreCorredor = true;
        corredorCoberto[corredor] = true;
      }
    }

    if (!cobreCorredor)
    {
      cameras.insert(i);
    }
  }
}

void Grafo::imprimirCameras() {
  cout << "Câmeras instaladas: ";
  for (auto camera : cameras) {
    cout << camera << " ";
  }
  cout << endl;
}
