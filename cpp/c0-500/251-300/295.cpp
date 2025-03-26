class MedianFinder {
    private:
        priority_queue<int> lower;  // Max heap for lower half
        priority_queue<int, vector<int>, greater<int>> upper;  // Min heap for upper half
        
    public:
        MedianFinder() {
            // Constructor is empty as heaps are initialized automatically
        }
        
        void addNum(int num) {
            // First element goes to lower heap
            if (lower.empty()) {
                lower.push(num);
                return;
            }
            
            // Decide which heap to put the number in
            if (num < lower.top()) {
                lower.push(num);
            } else {
                upper.push(num);
            }
            
            // Balance the heaps: lower can have at most one more element than upper
            if (lower.size() > upper.size() + 1) {
                upper.push(lower.top());
                lower.pop();
            } else if (upper.size() > lower.size()) {
                lower.push(upper.top());
                upper.pop();
            }
        }
        
        double findMedian() {
            // If equal size, average the middle two numbers
            if (lower.size() == upper.size()) {
                return (lower.top() + upper.top()) / 2.0;
            }
            // If uneven, lower has one more, so its top is the median
            return lower.top();
        }
    };
    Let's break down how this works:
    
    Data Structure:
    lower: Max heap containing smaller half of numbers
    upper: Min heap containing larger half of numbers
    Keep heaps balanced (or lower having one more element)
    addNum(int num):
    If empty, add to lower heap
    Otherwise:
    If num < lower.top(), add to lower
    Else add to upper
    Rebalance:
    If lower > upper + 1: move top of lower to upper
    If upper > lower: move top of upper to lower
    findMedian():
    If sizes equal: average top elements of both heaps
    If uneven: return top of lower heap (which has one more)
    Example walkthrough:
    
    text
    Wrap
    Copy
    addNum(1):  lower=[1]  upper=[]          // [1]
    addNum(2):  lower=[1]  upper=[2]         // [1,2]
    findMedian: (1+2)/2 = 1.5
    addNum(3):  lower=[1,2] upper=[3]        // [1,2,3]
    findMedian: 2
    Time Complexity:
    
    addNum: O(log n) - heap insertion
    findMedian: O(1) - just accessing top elements
    Space Complexity: O(n) - storing all elements in heaps
    
    Key Points:
    
    Maintains lower.size() = upper.size() or lower.size() = upper.size() + 1
    Median is either:
    Average of lower.top() and upper.top() (even count)
    lower.top() (odd count)
    Handles all constraints:
    Works with -10⁵ ≤ num ≤ 10⁵
    Efficient for up to 5 * 10⁴ operations
    This solution provides an efficient way to maintain a data stream and find the median instantly, much better than sorting the entire array each time (which would be O(n log n) per median find).