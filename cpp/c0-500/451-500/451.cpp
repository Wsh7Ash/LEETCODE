#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count frequency of each character
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        // Step 2: Create vector of pairs for sorting
        vector<pair<char, int>> freqVec;
        for (auto& entry : freq) {
            freqVec.push_back({entry.first, entry.second});
        }
        
        // Step 3: Sort by frequency in descending order
        sort(freqVec.begin(), freqVec.end(), 
             [](const pair<char, int>& a, const pair<char, int>& b) {
                 return a.second > b.second;
             });
        
        // Step 4: Build result string
        string result;
        for (auto& p : freqVec) {
            result.append(p.second, p.first);  // append char p.second times
        }
        
        return result;
    }
};
Let's break down how this solution works:

Frequency Counting:
We use an unordered_map to store the frequency of each character
Time complexity: O(n) where n is the length of the string
Space complexity: O(k) where k is the number of unique characters
Convert to Vector:
We convert the map to a vector of pairs (char, frequency) to enable sorting
Space complexity: O(k) for the vector
Sorting:
We sort the vector based on frequency in descending order using a lambda function
Time complexity: O(k log k) where k is the number of unique characters
The lambda function compares the second element (frequency) of each pair
Result Building:
We build the result string by appending each character its frequency number of times
Time complexity: O(n) as we need to write all n characters
Overall Complexity:

Time Complexity: O(n + k log k) where n is string length and k is number of unique characters
Space Complexity: O(k) for the map and vector
Since k ≤ n and k ≤ 62 (26 lowercase + 26 uppercase + 10 digits), we can simplify to:
Time Complexity: O(n log n) in worst case
Space Complexity: O(1) as k is bounded by a constant
Example Walkthrough:
For input "tree":

freq = {t:1, r:1, e:2}
freqVec = [(t,1), (r,1), (e,2)]
After sort = [(e,2), (t,1), (r,1)]
result = "ee" + "t" + "r" = "eetr"
The solution handles all the constraints:

Works for strings of length 1 to 5*10^5
Correctly processes uppercase, lowercase, and digits
Groups same characters together
Sorts by decreasing frequency
Alternative approaches could use:

Bucket sort (O(n) time but O(n) space)
Priority queue (similar complexity to current solution) This solution provides a good balance of simplicity and efficiency.