class Solution {
    private:
        vector<int> numbers;
        
    public:
        Solution(vector<int>& nums) {
            numbers = nums;
            // Seed the random number generator
            srand(time(nullptr));
        }
        
        int pick(int target) {
            int count = 0;    // Count of numbers equal to target
            int result = -1;  // Selected index
            
            // Reservoir sampling
            for (int i = 0; i < numbers.size(); i++) {
                if (numbers[i] == target) {
                    count++;
                    // Randomly select this index with probability 1/count
                    if (rand() % count == 0) {
                        result = i;
                    }
                }
            }
            
            return result;
        }
    };
    
    /**
     * Your Solution object will be instantiated and called as such:
     * Solution* obj = new Solution(nums);
     * int param_1 = obj->pick(target);
     */
    How this solution works:
    
    Approach (Reservoir Sampling):
    Instead of storing all indices and picking randomly, we use reservoir sampling
    This ensures equal probability for each valid index with O(1) space
    Key Components:
    Constructor: Stores the input array and seeds random generator
    pick(): Uses reservoir sampling to select index
    Reservoir Sampling Algorithm:
    For each number equal to target:
    Increment count
    Select current index with probability 1/count
    This maintains equal probability for all matching indices
    Why it works:
    First occurrence: selected with probability 1
    Second occurrence: keep first with 1/2, select second with 1/2
    Third occurrence: keep previous with 2/3, select third with 1/3
    Final probability for each index = 1/total_count
    Example Walkthrough ([1,2,3,3,3], target=3):
    text
    
    Collapse
    
    Wrap
    
    Copy
    i=2: count=1, select 2 (prob 1)
    i=3: count=2, keep 2 (1/2), select 3 (1/2)
    i=4: count=3, keep prev (2/3), select 4 (1/3)
    Final prob for each: 1/3
    Complexity:
    Time: O(n) for pick(), O(1) for constructor
    Space: O(1) extra space (not counting input storage)
    Alternative Solution (Pre-processing):
    
    cpp
    
    Collapse
    
    Wrap
    
    Copy
    class Solution {
    private:
        unordered_map<int, vector<int>> indexMap;
        
    public:
        Solution(vector<int>& nums) {
            // Pre-process: map each number to its indices
            for (int i = 0; i < nums.size(); i++) {
                indexMap[nums[i]].push_back(i);
            }
            srand(time(nullptr));
        }
        
        int pick(int target) {
            auto& indices = indexMap[target];
            return indices[rand() % indices.size()];
        }
    };
    Comparison:
    
    Reservoir Sampling:
    Pros: O(1) space, no preprocessing
    Cons: O(n) time per pick
    Pre-processing:
    Pros: O(1) time per pick
    Cons: O(n) space, O(n) preprocessing time
    The solution satisfies all constraints:
    
    Works for nums.length from 1 to 2*10^4
    Handles values from -2³¹ to 2³¹-1
    Ensures target exists in array
    Handles up to 10^4 pick calls
    Provides equal probability for all valid indices
    For this specific problem, reservoir sampling is often preferred because:
    
    Space efficiency is valuable
    Number of pick calls (10^4) is reasonable for O(n) time
    No need to modify the solution if input array changes
    The random selection ensures each valid index has an equal probability of being chosen, meeting the problem's requirements perfectly.