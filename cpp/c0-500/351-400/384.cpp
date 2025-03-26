class Solution {
    private:
        vector<int> original;  // Store original array
        vector<int> current;   // Store current working array
        
    public:
        Solution(vector<int>& nums) {
            original = nums;
            current = nums;
        }
        
        vector<int> reset() {
            current = original;
            return current;
        }
        
        vector<int> shuffle() {
            int n = current.size();
            
            // Fisher-Yates shuffle
            for (int i = n - 1; i > 0; i--) {
                // Generate random index from 0 to i
                int j = rand() % (i + 1);
                
                // Swap elements at i and j
                swap(current[i], current[j]);
            }
            
            return current;
        }
    };
    
    /**
     * Your Solution object will be instantiated and called as such:
     * Solution* obj = new Solution(nums);
     * vector<int> param_1 = obj->reset();
     * vector<int> param_2 = obj->shuffle();
     */
    Let's break down how this solution works:
    
    Class Structure:
    Two vectors: original (immutable copy) and current (working copy)
    Constructor initializes both with input array
    reset() Method:
    Copies original array back to current
    Time complexity: O(n)
    Space complexity: O(n)
    shuffle() Method:
    Implements Fisher-Yates shuffle algorithm
    Time complexity: O(n)
    Space complexity: O(1) extra space
    Fisher-Yates Algorithm:
    Iterates through array from end to beginning
    For each position i:
    Picks random index j from 0 to i
    Swaps elements at i and j
    Ensures uniform distribution of permutations
    Why it works:
    For n elements:
    First element has 1/n chance of ending anywhere
    Second element has 1/(n-1) chance of ending in remaining positions
    And so on...
    Results in n! equally likely permutations
    Example:
    text
    
    Collapse
    
    Wrap
    
    Copy
    Input: [1,2,3]
    Possible iteration:
    i=2: swap(3,rand(0-2)) -> [1,3,2]
    i=1: swap(3,rand(0-1)) -> [3,1,2]
    Notes:
    
    Uses rand() for simplicity; in production, consider using <random> library
    Each shuffle modifies the current array and returns it
    Original array remains unchanged for reset
    The solution meets all constraints:
    
    Works for arrays of length 1 to 50
    Handles values from -10^6 to 10^6
    Assumes unique elements
    Can handle up to 10^4 calls
    Provides uniform random shuffles
    Time Complexity:
    
    Constructor: O(n)
    reset(): O(n)
    shuffle(): O(n)
    Space Complexity:
    
    O(n) for storing two copies of the array
    This implementation provides an efficient and unbiased shuffle while maintaining the ability to reset to the original configuration.