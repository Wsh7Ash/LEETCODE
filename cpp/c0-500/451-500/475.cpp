To solve the problem of finding the minimum radius of heaters such that all houses are covered, we can use a binary search approach. The idea is to search for the smallest radius that ensures every house is within the warm radius of at least one heater.

Approach:
Sort the Arrays: First, sort both the houses and heaters arrays. This allows us to efficiently find the closest heater for each house.

Binary Search for Radius: Perform a binary search on the possible radius values. The search range is from 0 to the maximum distance between any house and the farthest heater.

Check Feasibility: For each candidate radius during the binary search, check if all houses can be covered by the heaters using that radius. This is done by iterating through the houses and ensuring that each house is within the radius of at least one heater.

Result: The smallest radius that satisfies the condition is the answer.

Implementation in C++:
cpp
Copy
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        // Sort the houses and heaters arrays
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        // Binary search for the minimum radius
        int left = 0, right = max(*max_element(houses.begin(), houses.end()), 
                                  *max_element(heaters.begin(), heaters.end()));
        int result = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canCoverAllHouses(houses, heaters, mid)) {
                result = mid; // Try to find a smaller radius
                right = mid - 1;
            } else {
                left = mid + 1; // Increase the radius
            }
        }
        
        return result;
    }
    
private:
    bool canCoverAllHouses(const vector<int>& houses, const vector<int>& heaters, int radius) {
        int i = 0, j = 0;
        while (i < houses.size() && j < heaters.size()) {
            // Check if the current heater can cover the current house
            if (abs(houses[i] - heaters[j]) <= radius) {
                i++; // Move to the next house
            } else {
                j++; // Move to the next heater
            }
        }
        // If all houses are covered, return true
        return i == houses.size();
    }
};
Explanation:
Sorting: Sorting the houses and heaters arrays allows us to efficiently find the closest heater for each house.

Binary Search: We perform a binary search on the possible radius values. The search range is from 0 to the maximum distance between any house and the farthest heater.

Feasibility Check: For each candidate radius, we check if all houses can be covered by the heaters using that radius. This is done by iterating through the houses and ensuring that each house is within the radius of at least one heater.

Result: The smallest radius that satisfies the condition is the answer.

Example Walkthrough:
For the input houses = [1,2,3], heaters = [2]:

The binary search will find that a radius of 1 is sufficient to cover all houses.

The result is 1.

For the input houses = [1,2,3,4], heaters = [1,4]:

The binary search will find that a radius of 1 is sufficient to cover all houses.

The result is 1.

For the input houses = [1,5], heaters = [2]:

The binary search will find that a radius of 3 is required to cover all houses.

The result is 3.

Complexity:
Time Complexity: O((N + M) log D), where N is the number of houses, M is the number of heaters, and D is the maximum distance between any house and the farthest heater.

Space Complexity: O(1), as we are using constant extra space.
