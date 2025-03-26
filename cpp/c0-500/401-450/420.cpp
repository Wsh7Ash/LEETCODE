class Solution {
    public:
        int strongPasswordChecker(string password) {
            // Get count of present character types (lowercase, uppercase, digit)
            int types = countTypes(password);
            int n = password.size();
    
            // Case 1: Password too short (< 6 characters)
            if (n < 6) {
                // Return maximum of characters needed to reach 6 or missing types
                return max(6 - n, 3 - types);
            }
    
            // Case 2: Password length is valid (6-20 characters)
            if (n <= 20) {
                int replace = 0;  // Number of replacements needed for repeats
                int cnt = 0;      // Current count of consecutive identical chars
                char prev = '~';  // Previous character (start with non-matching char)
                
                // Scan password to count replacements needed
                for (char& curr : password) {
                    if (curr == prev) {
                        ++cnt;  // Increment count of consecutive characters
                    } else {
                        replace += cnt / 3;  // Add replacements needed for previous group
                        cnt = 1;            // Start new group count
                        prev = curr;        // Update previous character
                    }
                }
                replace += cnt / 3;  // Handle the last group
                // Return max of replacements or missing types
                return max(replace, 3 - types);
            }
    
            // Case 3: Password too long (> 20 characters)
            int replace = 0;      // Total replacements needed
            int remove = n - 20;  // Number of characters to remove
            int remove2 = 0;      // Groups with remainder 1 that can use 2 deletions
            int cnt = 0;          // Current count of consecutive identical chars
            char prev = '~';      // Previous character
            
            // First pass: Count repeats and optimize with deletions
            for (char& curr : password) {
                if (curr == prev) {
                    ++cnt;  // Increment consecutive character count
                } else {
                    // Process previous group if we have deletions available
                    if (remove > 0 && cnt >= 3) {
                        if (cnt % 3 == 0) {  // Remainder 0: 1 deletion saves 1 replacement
                            --remove;
                            --replace;
                        } else if (cnt % 3 == 1) {  // Remainder 1: 2 deletions might help
                            ++remove2;
                        }
                    }
                    replace += cnt / 3;  // Add replacements for this group
                    cnt = 1;            // Start new group
                    prev = curr;        // Update previous character
                }
            }
            
            // Handle the final group
            if (remove > 0 && cnt >= 3) {
                if (cnt % 3 == 0) {
                    --remove;
                    --replace;
                } else if (cnt % 3 == 1) {
                    ++remove2;
                }
            }
            replace += cnt / 3;  // Add replacements for last group
    
            // Optimize remaining deletions
            // Use pairs of deletions for remainder 1 cases
            int use2 = min(min(replace, remove2), remove / 2);
            replace -= use2;    // Reduce replacements needed
            remove -= use2 * 2; // Use up deletions (2 per case)
    
            // Use triplets of deletions for remaining cases
            int use3 = min(replace, remove / 3);
            replace -= use3;    // Reduce replacements needed
            remove -= use3 * 3; // Use up deletions (3 per case)
    
            // Total steps = initial excess chars + max of remaining replacements or missing types
            return (n - 20) + max(replace, 3 - types);
        }
    
        // Helper function to count present character types
        int countTypes(string& s) {
            int a = 0;  // Flag for lowercase
            int b = 0;  // Flag for uppercase
            int c = 0;  // Flag for digit
            for (char& ch : s) {
                if (islower(ch))
                    a = 1;       // Found lowercase
                else if (isupper(ch))
                    b = 1;       // Found uppercase
                else if (isdigit(ch))
                    c = 1;       // Found digit
            }
            return a + b + c;  // Return count of types present (0-3)
        }
    };
    Key Optimizations Explained:
    Single Pass:
    Processes the string in one pass for cases n ≤ 20 and n > 20, reducing complexity
    Combines repeat detection and deletion optimization
    Smart Deletion Usage:
    For n > 20, prioritizes deletions that save replacements:
    1 deletion for remainder 0 (saves 1 replacement)
    2 deletions for remainder 1 cases (tracked in remove2)
    3 deletions for remaining cases
    Memory Efficiency:
    Avoids storing repeat groups in a vector
    Uses running counters instead
    Correctness:
    Handles all three cases (n < 6, 6 ≤ n ≤ 20, n > 20)
    Ensures minimum of missing types vs. operations needed
    Optimally uses deletions to minimize total operations
    This version is more efficient than the previous ones (O(n) time, O(1) space) while correctly handling all strong password requirements.