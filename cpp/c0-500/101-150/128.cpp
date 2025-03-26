class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            unordered_set<int> numSet(nums.begin(), nums.end()); // Store numbers in a set for O(1) lookups
            int longestStreak = 0;
    
            for (int num : numSet) {
                // Start only if it's the beginning of a sequence (no previous number exists)
                if (numSet.find(num - 1) == numSet.end()) {
                    int currentNum = num;
                    int currentStreak = 1;
    
                    // Count consecutive numbers
                    while (numSet.find(currentNum + 1) != numSet.end()) {
                        currentNum++;
                        currentStreak++;
                    }
    
                    longestStreak = max(longestStreak, currentStreak);
                }
            }
    
            return longestStreak;
        }
    };
    