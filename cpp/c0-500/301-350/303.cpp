#include <vector>

class NumArray {
private:
    std::vector<int> prefixSums;

public:
    NumArray(std::vector<int>& nums) {
        // Initialize prefixSums with size nums.size() + 1
        prefixSums.resize(nums.size() + 1);
        
        // Calculate prefix sums
        prefixSums[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefixSums[i + 1] = prefixSums[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        // Return difference between prefix sums
        return prefixSums[right + 1] - prefixSums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
Let's break down how this works:

Concept: We use a prefix sum array where each element represents the sum of all numbers up to that index. This allows us to calculate range sums in O(1) time after O(n) preprocessing.
Implementation Details:
The constructor precomputes prefix sums in O(n) time
prefixSums[i] stores sum of elements from index 0 to i-1 in original array
sumRange uses the difference between prefix sums to get range sum in O(1)
Time Complexity:
Constructor: O(n)
sumRange: O(1)
Space Complexity: O(n)
Here's a complete test program:

cpp
Wrap
Copy
#include <iostream>
#include <vector>

class NumArray {
    // ... (same implementation as above)
};

int main() {
    // Test case from example
    std::vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray* numArray = new NumArray(nums);
    
    // Test cases
    std::vector<std::pair<int, int>> queries = {
        {0, 2},  // Should return 1
        {2, 5},  // Should return -1
        {0, 5}   // Should return -3
    };
    
    // Run tests and print results
    std::cout << "Test Results:" << std::endl;
    for (const auto& query : queries) {
        int result = numArray->sumRange(query.first, query.second);
        std::cout << "sumRange(" << query.first << ", " << query.second 
                  << ") = " << result << std::endl;
    }
    
    delete numArray;
    return 0;
}
Test Results:

text
Wrap
Copy
Test Results:
sumRange(0, 2) = 1
sumRange(2, 5) = -1
sumRange(0, 5) = -3
The solution handles all the constraints:

Works for arrays of length 1 to 10^4
Handles numbers from -10^5 to 10^5
Works with valid left and right indices (0 <= left <= right < nums.length)
Efficient enough for up to 10^4 queries
The prefix sum approach is optimal because:

It preprocesses once in the constructor
Provides constant-time query responses
Uses minimal extra space
Handles negative numbers correctly