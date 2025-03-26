#include <iostream>
#include <vector>

using namespace std;

void backtrack(int start, int n, int k, vector<int>& current, vector<vector<int>>& result) {
    // If the current combination size is equal to k, add it to the result
    if (current.size() == k) {
        result.push_back(current);
        return;
    }
    
    // Try all the numbers from start to n
    for (int i = start; i <= n; ++i) {
        current.push_back(i); // Choose the number i
        backtrack(i + 1, n, k, current, result); // Explore the next numbers
        current.pop_back(); // Backtrack and remove the last number
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> current;
    backtrack(1, n, k, current, result); // Start with 1 to n
    return result;
}

int main() {
    int n = 4, k = 2;
    vector<vector<int>> result = combine(n, k);
    
    // Print the combinations
    for (const auto& comb : result) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
