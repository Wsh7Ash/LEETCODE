#include <vector>

class TrieNode {
public:
    TrieNode* children[2];
    TrieNode() {
        children[0] = nullptr;  // for bit 0
        children[1] = nullptr;  // for bit 1
    }
};

class Solution {
private:
    TrieNode* root;
    
    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }
    
    int findMaxXOR(int num) {
        TrieNode* node = root;
        int maxXOR = 0;
        
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            // Try to go opposite bit for maximum XOR
            if (node->children[1 - bit]) {
                maxXOR |= (1 << i);
                node = node->children[1 - bit];
            } else {
                node = node->children[bit];
            }
        }
        return maxXOR;
    }
    
public:
    int findMaximumXOR(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        
        root = new TrieNode();
        int maxResult = 0;
        
        // Insert first number
        insert(nums[0]);
        
        // For each subsequent number
        for (int i = 1; i < nums.size(); i++) {
            // Find max XOR with previously inserted numbers
            maxResult = max(maxResult, findMaxXOR(nums[i]));
            // Insert current number
            insert(nums[i]);
        }
        
        // Clean up memory (optional in this context)
        // deleteTrie(root);
        
        return maxResult;
    }
    
    // Optional: Memory cleanup
    void deleteTrie(TrieNode* node) {
        if (!node) return;
        deleteTrie(node->children[0]);
        deleteTrie(node->children[1]);
        delete node;
    }
};

// Test code
#include <iostream>
int main() {
    Solution solution;
    
    vector<int> nums1 = {3, 10, 5, 25, 2, 8};
    cout << solution.findMaximumXOR(nums1) << endl;  // Output: 28
    
    vector<int> nums2 = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
    cout << solution.findMaximumXOR(nums2) << endl;  // Output: 127
    
    return 0;
}
This solution uses a Trie (prefix tree) optimized for bits:

Approach:
Use a binary Trie to store numbers bit by bit
For each number, find maximum XOR with previously inserted numbers
XOR is maximized when bits differ
Key Components:
TrieNode: Each node has two children (0 and 1)
insert: Adds number to Trie bit by bit (MSB to LSB)
findMaxXOR: Finds maximum XOR possible with current Trie
Algorithm:
Insert first number into Trie
For each subsequent number:
Find max XOR with numbers in Trie
Insert current number
Return maximum XOR found
How it works:
For each bit position (31 down to 0):
Try to go opposite direction of current bit for max XOR
If not possible, follow current bit
Build result using bits where we could differ
Time Complexity: O(n * 32) ≈ O(n)
32 bits per number, n numbers
Space Complexity: O(n * 32) ≈ O(n)
Trie stores at most 32 nodes per number
Example for [3,10,5,25,2,8]:

3: 0011
10: 1010
5: 0101
25: 11001
XOR of 5 and 25 = 28 (00101 XOR 11001 = 11100)
The solution handles all constraints:

Works for array length 1 to 2 * 10^5
Handles numbers from 0 to 2^31 - 1
Finds maximum XOR between any two numbers efficiently
This Trie-based approach is much faster than the O(n²) brute force solution, making it suitable for large inputs.