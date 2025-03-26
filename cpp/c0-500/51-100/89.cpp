#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> grayCode(int n) {
        std::vector<int> result = {0}; // Start with the 1-bit Gray code: [0]
        
        // Generate Gray codes for 2 to n bits
        for (int i = 0; i < n; ++i) {
            int size = result.size();
            // Mirror the result and add 1 to the mirrored part
            for (int j = size - 1; j >= 0; --j) {
                result.push_back(result[j] | (1 << i)); // Add 1 << i (which is 2^i) to the number
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    int n = 2; // Example input
    std::vector<int> result = sol.grayCode(n);
    
    // Output the Gray code sequence
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
