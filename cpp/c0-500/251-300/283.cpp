void moveZeroes(vector<int>& nums) {
    int nonZeroPos = 0;  // Position to place next non-zero element
    
    // First pass: Move all non-zero elements to the front
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != 0) {
            nums[nonZeroPos] = nums[i];
            nonZeroPos++;
        }
    }
    
    // Second pass: Fill remaining positions with zeros
    for(int i = nonZeroPos; i < nums.size(); i++) {
        nums[i] = 0;
    }
}
Let's break down how this works:

We use a two-pass approach that modifies the array in-place.
First Pass:
nonZeroPos keeps track of where we should place the next non-zero element
We iterate through the array once
When we find a non-zero element, we:
Place it at nonZeroPos
Increment nonZeroPos
Second Pass:
Starting from nonZeroPos to the end
Fill all remaining positions with zeros
Time Complexity: O(n) where n is the length of the array
Space Complexity: O(1) as we do it in-place

Let's see it in action with Example 1: [0,1,0,3,12]

First Pass:

i=0: nums[0]=0, skip
i=1: nums[1]=1, nums[0]=1, nonZeroPos=1
i=2: nums[2]=0, skip
i=3: nums[3]=3, nums[1]=3, nonZeroPos=2
i=4: nums[4]=12, nums[2]=12, nonZeroPos=3 Result after first pass: [1,3,12,3,12]
Second Pass:

Fill from nonZeroPos=3 to end with zeros Final result: [1,3,12,0,0]
Alternative Solution using swap:

cpp
Wrap
Copy
void moveZeroes(vector<int>& nums) {
    int nonZeroPos = 0;
    
    // Move non-zero elements to front using swap
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != 0) {
            swap(nums[nonZeroPos], nums[i]);
            nonZeroPos++;
        }
    }
}
Both solutions:

Work in-place (no extra array)
Maintain relative order of non-zero elements
Handle all the constraints
Pass both example cases
The first solution might be slightly more efficient as it avoids unnecessary swaps when an element is already in its correct position, but both are valid approaches to solve this problem.