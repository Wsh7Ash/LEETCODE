#include <unordered_map>
#include <unordered_set>
#include <string>

class AllOne {
private:
    // Node for doubly linked list
    struct Node {
        int count;
        unordered_set<string> keys;
        Node* prev;
        Node* next;
        Node(int c) : count(c), prev(nullptr), next(nullptr) {}
    };
    
    // Hash map to store key -> node mapping
    unordered_map<string, Node*> keyToNode;
    
    // Dummy head and tail for the doubly linked list
    Node* head;  // smallest count
    Node* tail;  // largest count
    
    // Helper function to remove a node with no keys
    void removeNode(Node* node) {
        if (node->keys.empty() && node != head && node != tail) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node;
        }
    }
    
    // Helper function to get or create node with count+1
    Node* getOrCreateNextNode(Node* curr, const string& key) {
        if (curr->next->count == curr->count + 1) {
            return curr->next;
        }
        Node* newNode = new Node(curr->count + 1);
        newNode->next = curr->next;
        newNode->prev = curr;
        curr->next->prev = newNode;
        curr->next = newNode;
        return newNode;
    }
    
    // Helper function to get or create node with count-1
    Node* getOrCreatePrevNode(Node* curr, const string& key) {
        if (curr->prev->count == curr->count - 1) {
            return curr->prev;
        }
        Node* newNode = new Node(curr->count - 1);
        newNode->prev = curr->prev;
        newNode->next = curr;
        curr->prev->next = newNode;
        curr->prev = newNode;
        return newNode;
    }

public:
    AllOne() {
        head = new Node(0);  // Dummy head
        tail = new Node(0);  // Dummy tail
        head->next = tail;
        tail->prev = head;
    }
    
    void inc(string key) {
        if (keyToNode.find(key) == keyToNode.end()) {
            // Key doesn't exist, add to count 1
            Node* node = head->next->count == 1 ? head->next : getOrCreateNextNode(head, key);
            node->keys.insert(key);
            keyToNode[key] = node;
        } else {
            // Key exists, increment its count
            Node* curr = keyToNode[key];
            curr->keys.erase(key);
            Node* nextNode = getOrCreateNextNode(curr, key);
            nextNode->keys.insert(key);
            keyToNode[key] = nextNode;
            removeNode(curr);
        }
    }
    
    void dec(string key) {
        Node* curr = keyToNode[key];
        curr->keys.erase(key);
        
        if (curr->count > 1) {
            Node* prevNode = getOrCreatePrevNode(curr, key);
            prevNode->keys.insert(key);
            keyToNode[key] = prevNode;
        } else {
            keyToNode.erase(key);
        }
        
        removeNode(curr);
    }
    
    string getMaxKey() {
        if (tail->prev == head) return "";
        return *(tail->prev->keys.begin());
    }
    
    string getMinKey() {
        if (head->next == tail) return "";
        return *(head->next->keys.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
Let's break down how this solution works:

Data Structure Design:
Doubly linked list of Nodes, each containing:
count (frequency)
set of keys with that count
prev/next pointers
Hash map mapping keys to their Nodes
Dummy head and tail nodes for easier boundary handling
Key Operations:
inc:
If new key: add to count 1
If existing: move to next count node
dec:
Move to previous count node
Remove if count becomes 0
getMaxKey: Return any key from tail->prev
getMinKey: Return any key from head->next
Time Complexity: O(1) average for all operations
Hash map provides O(1) access to key's node
Linked list node creation/insertion is O(1)
Set operations (insert/erase) are O(1) average
Space Complexity: O(n) where n is number of unique keys
Storage for nodes and hash map entries
Key Features:
Maintains ordered counts via linked list
Quick access to min/max via head/tail
Handles duplicate keys efficiently
Cleans up empty nodes
Example Walkthrough:
inc("hello"): ["hello":1]
inc("hello"): ["hello":2]
getMaxKey(): "hello"
getMinKey(): "hello"
inc("leet"): ["leet":1, "hello":2]
getMaxKey(): "hello"
getMinKey(): "leet"
The solution meets all requirements:

O(1) average time complexity
Handles all operations correctly
Works within constraints
Returns empty string when no elements exist