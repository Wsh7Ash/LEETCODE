#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache;  // Doubly Linked List: {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> hashmap;  // {key, iterator to cache}

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (hashmap.find(key) == hashmap.end()) {
            return -1;  // Key not found
        }

        // Move the accessed node to the front (most recently used)
        auto node = hashmap[key];
        int value = node->second;
        cache.erase(node);
        cache.push_front({key, value});
        hashmap[key] = cache.begin();

        return value;
    }

    void put(int key, int value) {
        if (hashmap.find(key) != hashmap.end()) {
            // Key exists: Remove old position
            cache.erase(hashmap[key]);
        } else if (cache.size() == capacity) {
            // Evict the least recently used (LRU) item
            auto last = cache.back();
            hashmap.erase(last.first);
            cache.pop_back();
        }

        // Insert the new key-value pair at the front
        cache.push_front({key, value});
        hashmap[key] = cache.begin();
    }
};

// Driver Code
int main() {
    LRUCache lruCache(2);

    lruCache.put(1, 1); // cache: {1=1}
    lruCache.put(2, 2); // cache: {1=1, 2=2}
    cout << lruCache.get(1) << endl; // Output: 1
    lruCache.put(3, 3); // Evicts key 2, cache: {1=1, 3=3}
    cout << lruCache.get(2) << endl; // Output: -1 (not found)
    lruCache.put(4, 4); // Evicts key 1, cache: {3=3, 4=4}
    cout << lruCache.get(1) << endl; // Output: -1 (not found)
    cout << lruCache.get(3) << endl; // Output: 3
    cout << lruCache.get(4) << endl; // Output: 4

    return 0;
}
