string getHint(string secret, string guess) {
    int bulls = 0;
    int cows = 0;
    vector<int> secretFreq(10, 0);  // Frequency of digits in secret
    vector<int> guessFreq(10, 0);   // Frequency of digits in guess
    
    // First pass: Count bulls and build frequency tables
    for (int i = 0; i < secret.length(); i++) {
        if (secret[i] == guess[i]) {
            bulls++;
        } else {
            secretFreq[secret[i] - '0']++;
            guessFreq[guess[i] - '0']++;
        }
    }
    
    // Second pass: Count cows using frequency tables
    for (int i = 0; i < 10; i++) {
        cows += min(secretFreq[i], guessFreq[i]);
    }
    
    // Format result
    return to_string(bulls) + "A" + to_string(cows) + "B";
}
Let's break down how this works:

Approach:
Use two passes to handle bulls and cows separately
Use frequency arrays to track non-bull digits
Take minimum of frequencies to avoid overcounting
First Pass:
Compare secret and guess position by position
If digits match → increment bulls
If digits don't match → increment frequency in respective arrays
Second Pass:
For each digit (0-9), take minimum of frequencies
This gives us the number of cows (matches in wrong positions)
Example walkthrough with "1807" and "7810":

text
Wrap
Copy
First pass:
i=0: '1'≠'7' → secretFreq[1]++, guessFreq[7]++
i=1: '8'='8' → bulls=1
i=2: '0'≠'1' → secretFreq[0]++, guessFreq[1]++
i=3: '7'≠'0' → secretFreq[7]++, guessFreq[0]++

Freq arrays:
secretFreq: [1,1,0,0,0,0,0,1,0,0]  // 0:1, 1:1, 7:1
guessFreq:  [1,1,0,0,0,0,0,1,0,0]  // 0:1, 1:1, 7:1

Second pass:
cows = min(1,1) + min(1,1) + min(0,0) + ... + min(1,1) = 3

Result: "1A3B"
Time Complexity: O(n)

Single pass through the strings
Fixed-size (10) frequency array operations
Space Complexity: O(1)

Two fixed-size arrays of 10 elements
Regardless of input size
This solution:

Correctly handles duplicate digits
Meets all constraints (length 1-1000, only digits)
Produces output in required format "xAyB"
Handles bulls before cows to avoid double-counting
Works efficiently with a single pass
The key insight is using frequency arrays to handle the cow counting, ensuring we don't count a digit as a cow more times than it appears in both strings. This approach avoids the need for multiple passes or complex matching algorithms.