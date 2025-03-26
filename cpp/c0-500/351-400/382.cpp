/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    private:
        ListNode* head;
        
    public:
        /** @param head The linked list's head.
            Note that the head is guaranteed to be not null, so it contains at least one node. */
        Solution(ListNode* head) {
            this->head = head;
        }
        
        /** Returns a random node's value. */
        int getRandom() {
            ListNode* curr = head;
            int result = curr->val;
            int count = 1;
            
            // Traverse the linked list
            while (curr != nullptr) {
                // With probability 1/count, choose the current node
                if (rand() % count == 0) {
                    result = curr->val;
                }
                count++;
                curr = curr->next;
            }
            
            return result;
        }
    };
    
    /**
     * Your Solution object will be instantiated and called as such:
     * Solution* obj = new Solution(head);
     * int param_1 = obj->getRandom();
     */
    Let's break down how this solution works:
    
    Constructor:
    Takes the head of the linked list as input
    Stores it in a private member variable
    Time complexity: O(1)
    Space complexity: O(1)
    getRandom() Method:
    Uses Reservoir Sampling algorithm
    Time complexity: O(n) where n is the number of nodes
    Space complexity: O(1)
    Algorithm Explanation:
    Start with the first node's value as the initial result
    For each subsequent node i:
    With probability 1/i, keep the current node's value
    With probability (i-1)/i, keep the previous selection
    This ensures each node has an equal 1/n probability of being chosen
    Why it works:
    For a list of n nodes:
    First node has 1/1 chance of being chosen initially
    At second node, first node has 1/2 chance of being replaced (keeping 1/2 probability)
    At third node, current selection has 2/3 chance of staying (overall 1/3 for each)
    This continues, maintaining equal probability
    Implementation Details:
    Uses rand() % count == 0 to generate the 1/count probability
    Keeps track of count to adjust probability at each step
    Only stores one value at a time, not the entire list
    Note: In a production environment, you might want to:
    
    Use a better random number generator than rand() (like <random> library)
    Seed the random number generator properly
    Consider thread safety if needed
    The solution meets all the constraints:
    
    Works for lists of size 1 to 10^4
    Handles node values from -10^4 to 10^4
    Can handle up to 10^4 calls to getRandom()
    Provides equal probability for each node
    This is an efficient solution as it requires only O(1) extra space and makes just one pass through the list for each call to getRandom().