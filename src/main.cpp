#include <iostream>
#include "vigilancia.h"

using namespace std;

int main() 
{
    vector<vector<int>> corridors = {
        {0, 1, 2},
        {1, 3},
        {2, 4},
        {3, 4}};

    // Encontrar a configuração mais eficiente de câmeras
    vector<int> cameraLocations = findCameraLocations(corridors);

    // Exibir as salas escolhidas para instalação das câmeras
    cout << "Salas escolhidas para instalação das câmeras:" << endl;
    for (const auto &room : cameraLocations) {
        cout << room << " ";
    }
    cout << endl;
    return 0;
}
