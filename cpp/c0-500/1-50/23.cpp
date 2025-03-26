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

 struct Compare{
    bool operator()(ListNode*a, ListNode* b){
        return a->val > b->val;
    }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> ln;

        for(auto list : lists){
            if(list){
                ln.push(list);
            }
        }
        ListNode head;
        ListNode* current = &head;

        while(!ln.empty()){
            ListNode* smallest = ln.top();
            ln.pop();

            current->next = smallest;
            current = current->next;

            if(smallest->next){
                ln.push(smallest->next);
            }
        }
        return head.next;
    }
};