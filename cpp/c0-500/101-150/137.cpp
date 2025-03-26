#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < 32; ++i) { // Iterate through each bit position
            int sum = 0;
            for (int num : nums) {
                // Count the number of set bits at the current position
                sum += (num >> i) & 1;
            }
            // If the sum is not a multiple of 3, set the bit in the result
            if (sum % 3 != 0) {
                result |= (1 << i);
            }
        }
        return result;
    }
};