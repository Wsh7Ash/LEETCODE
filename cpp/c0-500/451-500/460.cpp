#include <unordered_map>

class LFUCache {
private:
    struct Node {
        int key;
        int value;
        int freq;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), freq(1), prev(nullptr), next(nullptr) {}
    };
    
    struct FreqList {
        Node* head;
        Node* tail;
        int size;
        FreqList() {
            head = new Node(0, 0);  // Dummy head
            tail = new Node(0, 0);  // Dummy tail
            head->next = tail;
            tail->prev = head;
            size = 0;
        }
        
        void addNode(Node* node) {
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
            size++;
        }
        
        void removeNode(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            size--;
        }
        
        ~FreqList() {
            delete head;
            delete tail;
        }
    };
    
    int capacity;
    int size;
    int minFreq;
    std::unordered_map<int, Node*> keyToNode;                  // key -> Node
    std::unordered_map<int, FreqList*> freqToList;            // freq -> FreqList
    
    void updateFreq(Node* node) {
        // Remove from old frequency list
        freqToList[node->freq]->removeNode(node);
        if (freqToList[node->freq]->size == 0 && node->freq == minFreq) {
            minFreq++;
        }
        
        // Increment frequency
        node->freq++;
        
        // Add to new frequency list
        if (freqToList.find(node->freq) == freqToList.end()) {
            freqToList[node->freq] = new FreqList();
        }
        freqToList[node->freq]->addNode(node);
    }
    
public:
    LFUCache(int capacity) : capacity(capacity), size(0), minFreq(0) {}
    
    int get(int key) {
        if (capacity == 0 || keyToNode.find(key) == keyToNode.end()) {
            return -1;
        }
        
        Node* node = keyToNode[key];
        updateFreq(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        
        // If key exists, update value and frequency
        if (keyToNode.find(key) != keyToNode.end()) {
            Node* node = keyToNode[key];
            node->value = value;
            updateFreq(node);
            return;
        }
        
        // If cache is full, remove LFU item
        if (size == capacity) {
            FreqList* minFreqList = freqToList[minFreq];
            Node* lfuNode = minFreqList->tail->prev;
            keyToNode.erase(lfuNode->key);
            minFreqList->removeNode(lfuNode);
            delete lfuNode;
            size--;
        }
        
        // Add new node
        Node* newNode = new Node(key, value);
        keyToNode[key] = newNode;
        if (freqToList.find(1) == freqToList.end()) {
            freqToList[1] = new FreqList();
        }
        freqToList[1]->addNode(newNode);
        minFreq = 1;
        size++;
    }
    
    ~LFUCache() {
        for (auto& pair : keyToNode) {
            delete pair.second;
        }
        for (auto& pair : freqToList) {
            delete pair.second;
        }
    }
};
Let's break down how this works:

Data Structures:
Node: Stores key, value, frequency, and doubly linked list pointers
FreqList: Doubly linked list for nodes with same frequency
keyToNode: Maps keys to their nodes
freqToList: Maps frequencies to their lists of nodes
Key Features:
Maintains nodes in frequency-based lists
Within each frequency, maintains LRU order
Tracks minimum frequency for quick LFU access
All operations are O(1)
Operations:
get(key):
Look up key in hash map
Update frequency
Return value or -1
put(key, value):
If exists: update value and frequency
If new and full: remove LFU/LRU item
Add new node with freq=1
Time Complexity: O(1) for both get and put
Hash map lookups: O(1)
List operations: O(1)
Frequency updates: O(1)
Space Complexity: O(capacity)
Stores at most capacity nodes
Additional hash maps and lists proportional to capacity
The solution handles all constraints and requirements:

Works for capacity 1 to 10⁴
Handles keys 0 to 10⁵ and values 0 to 10⁹
Maintains LFU property with LRU tiebreaker
O(1) time complexity for operations
Properly handles memory management