#include <iostream>
#include <vector>

using namespace std;

void backtrack(int start, const vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    // Add the current subset to the result
    result.push_back(current);
    
    // Try including each element starting from 'start'
    for (int i = start; i < nums.size(); ++i) {
        current.push_back(nums[i]);  // Include nums[i]
        backtrack(i + 1, nums, current, result);  // Recurse with next element
        current.pop_back();  // Backtrack: Remove the last element
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    backtrack(0, nums, current, result);  // Start backtracking from index 0
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);
    
    // Print all subsets
    for (const auto& subset : result) {
        cout << "[";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "] ";
    }
    cout << endl;
    
    return 0;
}
