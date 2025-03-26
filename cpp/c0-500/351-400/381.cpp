#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <cstdlib>
#include <iostream>

class RandomizedCollection {
private:
    // Vector to store values
    std::vector<int> values;
    // Map of value to set of indices where it appears
    std::unordered_map<int, std::unordered_set<int>> valToIndices;
    
public:
    RandomizedCollection() {
        srand(time(nullptr));
    }
    
    bool insert(int val) {
        // Add value to vector
        values.push_back(val);
        // Add index to set of indices for this value
        valToIndices[val].insert(values.size() - 1);
        // Return true if this was the first occurrence
        return valToIndices[val].size() == 1;
    }
    
    bool remove(int val) {
        // If value doesn't exist, return false
        if (valToIndices.find(val) == valToIndices.end() || valToIndices[val].empty()) {
            return false;
        }
        
        // Get index of one occurrence of val
        int index = *valToIndices[val].begin();
        int lastVal = values.back();
        
        // Move last element to position of element to be removed
        values[index] = lastVal;
        // Update indices: remove old index for val and update lastVal's index
        valToIndices[val].erase(index);
        if (val != lastVal) {
            valToIndices[lastVal].erase(values.size() - 1);
            valToIndices[lastVal].insert(index);
        }
        
        // Remove last element
        values.pop_back();
        
        // Clean up empty set
        if (valToIndices[val].empty()) {
            valToIndices.erase(val);
        }
        
        return true;
    }
    
    int getRandom() {
        return values[rand() % values.size()];
    }
};

// Test code
int main() {
    RandomizedCollection randomizedCollection;
    
    std::cout << randomizedCollection.insert(1) << std::endl;    // true
    std::cout << randomizedCollection.insert(1) << std::endl;    // false
    std::cout << randomizedCollection.insert(2) << std::endl;    // true
    std::cout << randomizedCollection.getRandom() << std::endl;  // 1 or 2
    std::cout << randomizedCollection.remove(1) << std::endl;    // true
    std::cout << randomizedCollection.getRandom() << std::endl;  // 1 or 2
    
    return 0;
}
This solution builds upon the previous problem (380) but modifies it to handle duplicates:

Data Structures:

values: Vector to store all values
valToIndices: Map from value to set of indices where it appears
Operations:

insert(int val):

Add value to vector (O(1) amortized)
Add new index to value's index set (O(1))
Return true if this was first occurrence (size was 0 before insert)
Time complexity: O(1) average
remove(int val):

Check if value exists (O(1))
Get one index of val from its set (O(1))
Swap with last element and update indices:
Remove old index from val's set (O(1))
Update last value's index set if different (O(1))
Remove last element (O(1))
Clean up empty set if necessary (O(1))
Time complexity: O(1) average
getRandom():

Generate random index (O(1))
Return value at that index (O(1))
Probability is proportional to count since each occurrence has its own index
Time complexity: O(1)
Key Differences from Problem 380:

Uses unordered_set instead of single index to track multiple occurrences
Insert always succeeds but returns false if value was already present
Remove only removes one occurrence
Probability in getRandom is proportional to number of occurrences
Complexity:

Time Complexity: O(1) average for all operations
Space Complexity: O(n) where n is the total number of elements
Correctness:

Maintains all occurrences of duplicates
Probability in getRandom is linear with frequency (each instance has equal chance)
Handles edge cases (empty collection, single element)
This solution meets all requirements:

O(1) average time complexity for all operations
Handles duplicates correctly
Provides random selection with probability proportional to frequency
Works within given constraints (-2³¹ ≤ val ≤ 2³¹-1, up to 2 * 10⁵ calls)
The use of an unordered_set for indices allows us to efficiently track multiple occurrences while maintaining O(1) average time complexity for all operations.