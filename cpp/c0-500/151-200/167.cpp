#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            
            if (sum == target) {
                return {left + 1, right + 1};  // Convert to 1-based index
            }
            else if (sum < target) {
                left++;  // Increase sum
            }
            else {
                right--; // Decrease sum
            }
        }
        
        return {}; // This line won't be reached due to guaranteed solution.
    }
};

// **Example Usage**
int main() {
    Solution sol;
    
    vector<int> numbers1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = sol.twoSum(numbers1, target1);
    cout << "[" << result1[0] << ", " << result1[1] << "]" << endl;  // Output: [1,2]

    vector<int> numbers2 = {2, 3, 4};
    int target2 = 6;
    vector<int> result2 = sol.twoSum(numbers2, target2);
    cout << "[" << result2[0] << ", " << result2[1] << "]" << endl;  // Output: [1,3]

    vector<int> numbers3 = {-1, 0};
    int target3 = -1;
    vector<int> result3 = sol.twoSum(numbers3, target3);
    cout << "[" << result3[0] << ", " << result3[1] << "]" << endl;  // Output: [1,2]

    return 0;
}
