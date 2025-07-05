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
    public:
        int numComponents(ListNode* head, vector<int>& nums) {
            unordered_set<int> numSet(nums.begin(), nums.end());
            int cs = 0;
            ListNode* cur = head;
            bool inC = false;
    
            while(cur != nullptr){
                if(numSet.find(cur->val) != numSet.end()){
                    if(!inC){
                        cs++;
                        inC = true;
                    }
                }else{
                    inC = false;
                }
                cur = cur->next;
            }
            return cs;
        }
    };