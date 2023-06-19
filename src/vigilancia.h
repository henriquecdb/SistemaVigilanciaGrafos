#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> findCameraLocations(const vector<vector<int>> &corridors) {
    unordered_set<int> cameraLocations;
    for (const auto &corridor : corridors) {
        int maxCorridor = -1;
        int maxUncovered = 0;
        // Verifica cada sala do corredor e escolhe a sala que cobre a maior quantidade de corredores não cobertos
        for (const auto &room : corridor) {
            int uncoveredCount = 0;
            // Conta a quantidade de corredores não cobertos pela sala atual
            for (const auto &otherCorridor : corridors) {
                if (otherCorridor != corridor && find(otherCorridor.begin(), otherCorridor.end(), room) == otherCorridor.end()) {
                    uncoveredCount++;
                }
            }
            // Atualiza a sala escolhida se ela cobrir mais corredores não cobertos
            if (uncoveredCount > maxUncovered) {
                maxCorridor = room;
                maxUncovered = uncoveredCount;
            }
        }
        // Adiciona a sala escolhida à configuração de câmeras
        cameraLocations.insert(maxCorridor);
    }
    return vector<int>(cameraLocations.begin(), cameraLocations.end());
}
