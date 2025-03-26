class PeekingIterator {
    private:
        Iterator<int>* iter;     // Pointer to the original iterator
        bool hasCached;         // Flag to indicate if we have a cached value
        int cachedValue;        // Stores the peeked value
        
    public:
        PeekingIterator(vector<int>& nums) {
            // Initialize with the given iterator
            iter = new Iterator<int>(nums);
            hasCached = false;
            cachedValue = 0;
        }
        
        // Returns the next element without moving the pointer
        int peek() {
            if (!hasCached) {
                // If we don't have a cached value, get it from iterator
                cachedValue = iter->next();
                hasCached = true;
            }
            return cachedValue;
        }
        
        // Returns the next element and advances the pointer
        int next() {
            if (hasCached) {
                // If we have a cached value from peek, use it
                hasCached = false;
                return cachedValue;
            }
            // Otherwise get next from iterator directly
            return iter->next();
        }
        
        // Returns true if there are more elements
        bool hasNext() {
            // True if we have a cached value or if iterator has more
            return hasCached || iter->hasNext();
        }
        
        // Destructor to clean up
        ~PeekingIterator() {
            delete iter;
        }
    };
    Let's break down how this works:
    
    Class Members:
    iter: Pointer to the original iterator
    hasCached: Boolean flag to track if we have a peeked value stored
    cachedValue: Stores the next value when we peek
    Constructor:
    Initializes with the given vector
    Sets up the iterator and initializes cache variables
    peek():
    If we don't have a cached value:
    Gets the next value from iterator
    Stores it in cachedValue
    Sets hasCached to true
    Returns the cached value without advancing
    next():
    If we have a cached value (from peek):
    Returns it and clears the cache
    Otherwise:
    Gets next value directly from iterator
    Advances the pointer in either case
    hasNext():
    Returns true if either:
    We have a cached value, or
    The underlying iterator has more elements
    For the example [1,2,3]:
    
    text
    Wrap
    Copy
    PeekingIterator p([1,2,3])  // [1,2,3], hasCached=false
    p.next()                    // returns 1, [2,3]
    p.peek()                    // returns 2, caches 2, [2,3]
    p.next()                    // returns 2 (cached), [3]
    p.next()                    // returns 3, []
    p.hasNext()                 // returns false
    Time Complexity:
    
    peek(): O(1)
    next(): O(1)
    hasNext(): O(1)
    Space Complexity: O(1) as we only store one extra value for caching
    
    This solution:
    
    Correctly implements all required operations
    Maintains the iterator functionality
    Handles peeking without advancing the pointer
    Works within the given constraints
    Properly manages memory with a destructor
    Note: The actual Iterator class interface might vary slightly depending on the specific problem platform, but this implementation assumes a standard iterator interface with next() and hasNext() methods.