#include "../include/Classe.h"
#include <iostream>

using namespace std;

int main() {
  Grafo grafo("/home/hcj/Documentos/SistemaVigilanciaGrafos/test/grafo2.txt");
  //grafo.imprimirGrafo();
  grafo.encontrarCamerasAproximado();
  grafo.imprimirCameras();
}
