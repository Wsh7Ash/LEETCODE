#include <vector>
#include <set>

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<double> lower;  // max heap for lower half
        multiset<double> upper;  // min heap for upper half
        vector<double> result;
        
        // Process first window
        for (int i = 0; i < k; i++) {
            if (lower.size() <= upper.size()) {
                upper.insert(nums[i]);
                lower.insert(*upper.begin());
                upper.erase(upper.begin());
            } else {
                lower.insert(nums[i]);
                upper.insert(*lower.rbegin());
                lower.erase(--lower.end());
            }
        }
        
        // Get median of first window
        if (k % 2 == 1) {
            result.push_back(*lower.rbegin());
        } else {
            result.push_back((*lower.rbegin() + *upper.begin()) / 2.0);
        }
        
        // Process remaining windows
        for (int i = k; i < nums.size(); i++) {
            // Remove element going out of window
            double out = nums[i - k];
            if (out <= *lower.rbegin()) {
                lower.erase(lower.find(out));
            } else {
                upper.erase(upper.find(out));
            }
            
            // Add new element
            if (lower.size() <= upper.size()) {
                upper.insert(nums[i]);
                lower.insert(*upper.begin());
                upper.erase(upper.begin());
            } else {
                lower.insert(nums[i]);
                upper.insert(*lower.rbegin());
                lower.erase(--lower.end());
            }
            
            // Calculate median
            if (k % 2 == 1) {
                result.push_back(*lower.rbegin());
            } else {
                result.push_back((*lower.rbegin() + *upper.begin()) / 2.0);
            }
        }
        
        return result;
    }
};

