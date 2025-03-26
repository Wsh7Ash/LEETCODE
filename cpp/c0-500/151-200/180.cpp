#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> findConsecutiveNums(const std::vector<int>& logs) {
    std::unordered_set<int> result;  // To store the numbers that appear consecutively 3 times
    int n = logs.size();

    // Iterate through the logs
    for (int i = 0; i < n - 2; ++i) {
        if (logs[i] == logs[i + 1] && logs[i + 1] == logs[i + 2]) {
            result.insert(logs[i]);  // Insert the number into the result set
        }
    }

    // Convert the result set to a vector
    std::vector<int> consecutiveNums(result.begin(), result.end());
    return consecutiveNums;
}

int main() {
    std::vector<int> logs = {1, 1, 1, 2, 1, 2, 2};
    std::vector<int> result = findConsecutiveNums(logs);

    // Print the result
    std::cout << "Consecutive Numbers: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
