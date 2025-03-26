class SummaryRanges {
    // Using TreeSet to maintain sorted order and uniqueness
    private TreeSet<Integer> numbers;
    
    public SummaryRanges() {
        numbers = new TreeSet<>();
    }
    
    public void addNum(int value) {
        numbers.add(value);
    }
    
    public int[][] getIntervals() {
        if (numbers.isEmpty()) {
            return new int[0][];
        }
        
        List<int[]> intervals = new ArrayList<>();
        int start = numbers.first();
        int prev = start;
        
        // Iterate through all numbers after the first one
        for (int curr : numbers.tailSet(start + 1)) {
            // If current number is not consecutive with previous
            if (curr > prev + 1) {
                // Add the completed interval
                intervals.add(new int[]{start, prev});
                // Start new interval
                start = curr;
            }
            prev = curr;
        }
        
        // Add the last interval
        intervals.add(new int[]{start, prev});
        
        // Convert List to array and return
        return intervals.toArray(new int[0][]);
    }
}
Let's break down how this solution works:

Data Structure Choice:
We use a TreeSet because it:
Maintains elements in sorted order automatically
Ensures uniqueness (no duplicates)
Provides efficient access to elements in order
Has O(log n) time complexity for insertions
Methods:
SummaryRanges(): Initializes an empty TreeSet
addNum(int value): Simply adds the number to the set
getIntervals(): Constructs and returns the disjoint intervals array
getIntervals() Logic:
If set is empty, return empty array
Start with first number as interval beginning
Iterate through numbers:
If gap > 1 between current and previous, end current interval and start new one
Keep track of previous number
Add final interval after loop
Convert List to required array format
Time Complexity:
addNum: O(log n) due to TreeSet insertion
getIntervals: O(n) where n is number of elements in set
Space Complexity: O(n) to store all unique numbers
Example Walkthrough:
text
Wrap
Copy
addNum(1) → [1]
getIntervals() → [[1,1]]

addNum(3) → [1,3]
getIntervals() → [[1,1],[3,3]]

addNum(7) → [1,3,7]
getIntervals() → [[1,1],[3,3],[7,7]]

addNum(2) → [1,2,3,7]
getIntervals() → [[1,3],[7,7]]  // 1-2-3 merges

addNum(6) → [1,2,3,6,7]
getIntervals() → [[1,3],[6,7]]  // 6-7 merges
The solution handles all constraints:

Works with values 0 to 10^4
Can handle 3 * 10^4 addNum calls
Efficient for up to 10^2 getIntervals calls
Returns intervals sorted by start value
Maintains disjoint intervals correctly
This implementation provides an efficient and clean solution to the data stream interval problem while meeting all the specified requirements.