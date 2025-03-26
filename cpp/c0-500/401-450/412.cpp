class Solution {
    public:
        vector<string> fizzBuzz(int n) {
            vector<string> answer(n);
            
            for (int i = 1; i <= n; i++) {
                if (i % 3 == 0 && i % 5 == 0) {
                    answer[i-1] = "FizzBuzz";
                }
                else if (i % 3 == 0) {
                    answer[i-1] = "Fizz";
                }
                else if (i % 5 == 0) {
                    answer[i-1] = "Buzz";
                }
                else {
                    answer[i-1] = to_string(i);
                }
            }
            
            return answer;
        }
    };
    How this solution works:
    
    Approach:
    Create a vector of strings with size n
    Iterate from 1 to n
    Check divisibility conditions in order of priority
    Fill array with appropriate string
    Key Logic:
    Check FizzBuzz (3 and 5) first since it's most specific
    Then check Fizz (3)
    Then check Buzz (5)
    Default to number as string
    Use i-1 for 1-indexed input to 0-indexed array
    Algorithm:
    Pre-allocate vector of size n
    For each i from 1 to n:
    Apply conditions in order
    Store result at index i-1
    Example Walkthrough (n = 5):
    text
    
    Collapse
    
    Wrap
    
    Copy
    i=1: 1%3≠0, 1%5≠0 → "1"
    i=2: 2%3≠0, 2%5≠0 → "2"
    i=3: 3%3=0 → "Fizz"
    i=4: 4%3≠0, 4%5≠0 → "4"
    i=5: 5%5=0 → "Buzz"
    Result: ["1","2","Fizz","4","Buzz"]
    Complexity:
    Time: O(n)
    Space: O(n) for the output array
    Key Features:
    1-indexed as required
    Returns strings
    Handles all cases correctly
    The solution satisfies all constraints:
    
    Works for n from 1 to 10⁴
    Alternative Solution (more concise):
    
    cpp
    
    Collapse
    
    Wrap
    
    Copy
    class Solution {
    public:
        vector<string> fizzBuzz(int n) {
            vector<string> answer(n);
            
            for (int i = 1; i <= n; i++) {
                string& s = answer[i-1];
                if (i % 3 == 0) s += "Fizz";
                if (i % 5 == 0) s += "Buzz";
                if (s.empty()) s = to_string(i);
            }
            
            return answer;
        }
    };
    Comparison:
    
    First solution:
    More explicit conditions
    Easier to read and maintain
    Slightly more verbose
    Second solution:
    More concise
    Builds string incrementally
    Slightly less intuitive
    Both solutions correctly handle:
    
    Example 1: n=3 → ["1","2","Fizz"]
    Example 2: n=5 → ["1","2","Fizz","4","Buzz"]
    Example 3: n=15 → ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
    The first solution is generally preferred because:
    
    Clearer logic flow
    Easier to modify if rules change
    More straightforward condition checking
    This solution efficiently generates the Fizz Buzz sequence by checking divisibility conditions in the proper order and converting numbers to strings only when necessary, meeting all requirements of the problem.