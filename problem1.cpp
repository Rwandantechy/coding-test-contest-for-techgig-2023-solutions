/* Read input from STDIN. Print your output to STDOUT*/
#include <math.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <algorithm>
#include <limits.h>
#include <stdbool.h>

int findMinimumEnergyLevel(const std::vector<int>& energyLevels, int capacity) {
    std::vector<int> sortedEnergyLevels = energyLevels;
    std::sort(sortedEnergyLevels.begin(), sortedEnergyLevels.end(), std::greater<int>());

    int minEnergyLevel = 0;
    int n = sortedEnergyLevels.size();

    for (int i = 0; i < n; i++) {
        int currentEnergyLevel = sortedEnergyLevels[i];
        int count = std::count_if(sortedEnergyLevels.begin(), sortedEnergyLevels.begin() + i + 1,
                                  [currentEnergyLevel](int energy) { return energy >= currentEnergyLevel; });

        if (count >= capacity) {
            minEnergyLevel = currentEnergyLevel;
            break;
        }
    }

    if (minEnergyLevel == 0)
        return -1;  // Not possible to save exactly X animals
    else
        return minEnergyLevel;
}

int main(int argc, char *a[])
{
     int N, X;
    std::cin >> N >> X;

    std::vector<int> energyLevels(N);
    for (int i = 0; i < N; i++)
        std::cin >> energyLevels[i];

    int minimumEnergyLevel = findMinimumEnergyLevel(energyLevels, X);

    if (minimumEnergyLevel == -1)
        std::cout << X << std::endl;
    else
        std::cout << minimumEnergyLevel << std::endl;

    return 0;
}
