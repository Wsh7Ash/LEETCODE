class Solution {
    public:
        vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
            // Sort by height descending, then by k ascending
            sort(people.begin(), people.end(), 
                 [](vector<int>& a, vector<int>& b) {
                     return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
                 });
            
            // Insert each person at their k index
            vector<vector<int>> result;
            for (auto& person : people) {
                result.insert(result.begin() + person[1], person);
            }
            
            return result;
        }
    };
    How this solution works:
    
    Approach:
    Sort people by height in descending order (and k in ascending order for ties)
    Insert each person at index k in the result array
    Greedy: taller people first, then shorter ones
    Key Insight:
    Taller people should be placed first because their k value counts only taller/equal height people
    After sorting, inserting at index k works because:
    All previously placed people are taller
    k represents exactly how many taller/equal people should be in front
    Algorithm:
    Sort: O(n log n)
    Insert each person at position k: O(n²) due to shifting
    Total time: O(n²)
    Example Walkthrough ([[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]):
    text
    
    Collapse
    
    Wrap
    
    Copy
    After sort: [[7,0],[7,1],[6,1],[5,0],[5,2],[4,4]]
    Insert process:
    - [7,0] at 0: [[7,0]]
    - [7,1] at 1: [[7,0],[7,1]]
    - [6,1] at 1: [[7,0],[6,1],[7,1]]
    - [5,0] at 0: [[5,0],[7,0],[6,1],[7,1]]
    - [5,2] at 2: [[5,0],[7,0],[5,2],[6,1],[7,1]]
    - [4,4] at 4: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
    Complexity:
    Time: O(n²) - sorting O(n log n) + insertion O(n²)
    Space: O(1) extra space (not counting output)
    Key Features:
    Maintains original [h,k] format
    Guarantees valid reconstruction
    Handles all valid k values
    The solution satisfies all constraints:
    
    Works for people.length from 1 to 2000
    Handles heights from 0 to 10⁶
    Handles k from 0 to length-1
    Alternative Approach (using list for O(n²) with better constants):
    
    cpp
    
    Collapse
    
    Wrap
    
    Copy
    class Solution {
    public:
        vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
            sort(people.begin(), people.end(), 
                 [](vector<int>& a, vector<int>& b) {
                     return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
                 });
            
            list<vector<int>> result;
            for (auto& person : people) {
                auto it = result.begin();
                advance(it, person[1]);
                result.insert(it, person);
            }
            
            return vector<vector<int>>(result.begin(), result.end());
        }
    };
    The first solution is preferred because:
    
    Simpler implementation
    Uses standard vector operations
    No need for additional data structure conversion
    Both solutions correctly handle:
    
    Example 1: [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]] → [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
    Example 2: [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]] → [[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]
    The greedy approach works because:
    
    Placing taller people first ensures their k value is satisfied
    Shorter people inserted later don't affect taller people's k count
    The sorting ensures we process in the correct order
    This solution efficiently reconstructs the queue while maintaining all the required properties specified in the problem.