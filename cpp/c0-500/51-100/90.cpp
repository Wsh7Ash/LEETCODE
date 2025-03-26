#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void backtrack(std::vector<int>& nums, int start, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Add the current subset to the result
        result.push_back(current);
        
        // Start iterating from the given start index
        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates by checking if the current element is the same as the previous one
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // Include nums[i] in the current subset and move to the next element
            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, result);  // Move to the next index
            current.pop_back();  // Backtrack by removing the last element
        }
    }

    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        
        // Sort the input array to group duplicates together
        std::sort(nums.begin(), nums.end());
        
        // Start backtracking from index 0
        backtrack(nums, 0, current, result);
        
        return result;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1, 2, 2};
    
    // Generate subsets
    std::vector<std::vector<int>> result = sol.subsetsWithDup(nums);
    
    // Output the subsets
    for (const auto& subset : result) {
        std::cout << "[";
        for (int i = 0; i < subset.size(); i++) {
            std::cout << subset[i];
            if (i < subset.size() - 1) std::cout << ", ";
        }
        std::cout << "] ";
    }
    std::cout << std::endl;

    return 0;
}
