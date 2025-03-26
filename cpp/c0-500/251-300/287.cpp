For this problem, we need to find the duplicate number without modifying the array and using only constant space. One of the most elegant solutions is to use Floyd's Tortoise and Hare (Cycle Detection) algorithm, treating the array as a linked list where each value points to an index.

Here's the solution in C++:

cpp
Wrap
Copy
int findDuplicate(vector<int>& nums) {
    // Initialize tortoise and hare pointers
    int tortoise = nums[0];
    int hare = nums[0];
    
    // Phase 1: Find intersection point of tortoise and hare
    do {
        tortoise = nums[tortoise];        // Move one step
        hare = nums[nums[hare]];         // Move two steps
    } while (tortoise != hare);
    
    // Phase 2: Find entrance to the cycle
    tortoise = nums[0];
    while (tortoise != hare) {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }
    
    return tortoise;
}
Let's understand how this works:

Key Insight:
Since numbers are from 1 to n in an array of size n+1, and there's one duplicate
We can treat array values as pointers to indices
The duplicate creates a cycle in this "linked list"
Algorithm Explanation:
Uses two pointers: tortoise (slow) and hare (fast)
Phase 1: Find where they meet inside the cycle
Tortoise moves 1 step: nums[tortoise]
Hare moves 2 steps: nums[nums[hare]]
Phase 2: Find cycle entrance (the duplicate)
Reset tortoise to start
Both move 1 step until they meet
Example walkthrough with [1,3,4,2,2]:
text
Wrap
Copy
Index: 0 1 2 3 4
Value: 1 3 4 2 2

Path: 0→1→3→2→4→2 (cycle at 2)

Phase 1:
t: 1→3→2
h: 1→3→4→2

Phase 2:
t: 1→3→2
h: 2→2
Meet at 2
Why it works:

The duplicate number creates a cycle because two different indices point to the same value
The cycle entrance is the duplicate number
Floyd's algorithm is guaranteed to find this cycle
Time Complexity: O(n)

Both phases are linear time
The hare catches the tortoise in O(n) steps
Second phase is at most O(n)
Space Complexity: O(1)

Only uses two variables regardless of input size
This solution satisfies all requirements:

Doesn't modify the array
Uses constant extra space
Works for all given constraints
Correctly handles all example cases
Alternative approaches like binary search or sum-based solutions either modify the array or use extra space, making this cycle detection method the optimal solution given the constraints.