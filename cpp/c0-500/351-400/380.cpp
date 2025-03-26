#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <iostream>

class RandomizedSet {
private:
    // Hash map to store value to index mapping
    std::unordered_map<int, int> valToIndex;
    // Vector to store values
    std::vector<int> values;
    
public:
    RandomizedSet() {
        // Seed the random number generator
        srand(time(nullptr));
    }
    
    bool insert(int val) {
        // If value already exists, return false
        if (valToIndex.find(val) != valToIndex.end()) {
            return false;
        }
        
        // Add value to vector and update mapping
        values.push_back(val);
        valToIndex[val] = values.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        // If value doesn't exist, return false
        if (valToIndex.find(val) == valToIndex.end()) {
            return false;
        }
        
        // Get index of value to remove
        int index = valToIndex[val];
        int lastVal = values.back();
        
        // Move last element to position of element to be removed
        values[index] = lastVal;
        valToIndex[lastVal] = index;
        
        // Remove last element
        values.pop_back();
        valToIndex.erase(val);
        
        return true;
    }
    
    int getRandom() {
        // Generate random index and return corresponding value
        return values[rand() % values.size()];
    }
};

// Test code
int main() {
    RandomizedSet randomizedSet;
    
    std::cout << randomizedSet.insert(1) << std::endl;    // true
    std::cout << randomizedSet.remove(2) << std::endl;    // false
    std::cout << randomizedSet.insert(2) << std::endl;    // true
    std::cout << randomizedSet.getRandom() << std::endl;  // 1 or 2
    std::cout << randomizedSet.remove(1) << std::endl;    // true
    std::cout << randomizedSet.insert(2) << std::endl;    // false
    std::cout << randomizedSet.getRandom() << std::endl;  // 2
    
    return 0;
}
This implementation uses a combination of a hash map and a vector to achieve O(1) average time complexity for all operations. Here's how it works:

Data Structures:

valToIndex: Hash map storing value-to-index mapping
values: Vector storing the actual values
Operations:

insert(int val):

Check if value exists using hash map (O(1))
If not present:
Add to vector (O(1) amortized)
Update hash map (O(1))
Time complexity: O(1) average
remove(int val):

Check if value exists using hash map (O(1))
If present:
Get index from hash map (O(1))
Move last element to this position (O(1))
Update last element's index in hash map (O(1))
Remove last element (O(1))
Erase from hash map (O(1))
Time complexity: O(1) average
getRandom():

Generate random index using rand() (O(1))
Return value at that index (O(1))
Time complexity: O(1)
Key Insights:

Using both vector and hash map allows O(1) access and random selection
For removal, we swap with last element to avoid shifting elements
Each element has equal probability of being selected in getRandom()
Complexity:

Time Complexity: O(1) average for all operations
Space Complexity: O(n) where n is the number of elements stored
Implementation Notes:

We seed the random number generator in the constructor
The remove operation maintains the data structure's integrity by updating both vector and hash map
Using unordered_map gives us average O(1) operations (though worst case is O(n))
This solution meets all requirements:

O(1) average time complexity for all operations
Handles the given constraints (-2³¹ ≤ val ≤ 2³¹-1)
Works with up to 2 * 10⁵ calls
Provides random selection with equal probability
The swap-with-last technique in remove() is crucial for maintaining O(1) time complexity, as simply removing an element from the middle of a vector would be O(n).