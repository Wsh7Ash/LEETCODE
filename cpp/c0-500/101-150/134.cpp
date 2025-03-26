#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        // Step 1: Check if total gas is enough to cover total cost
        int totalGas = 0, totalCost = 0;
        for (int i = 0; i < n; ++i) {
            totalGas += gas[i];
            totalCost += cost[i];
        }
        if (totalGas < totalCost) {
            return -1; // Not enough gas to complete the circuit
        }

        // Step 2: Find the starting station
        int currentGas = 0;
        int startStation = 0;

        for (int i = 0; i < n; ++i) {
            currentGas += gas[i] - cost[i];
            if (currentGas < 0) {
                // Reset and try the next station as the starting point
                currentGas = 0;
                startStation = i + 1;
            }
        }

        return startStation;
    }
};