#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Create new nodes and interweave them with original nodes
        Node* curr = head;
        while (curr) {
            Node* newNode = new Node(curr->val); // Create a new node
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next; // Move to the next original node
        }

        // Step 2: Set the random pointers for the copied nodes
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next; // Set the random pointer
            }
            curr = curr->next->next; // Move to the next original node
        }

        // Step 3: Separate the original and copied lists
        Node* newHead = head->next;
        curr = head;
        while (curr) {
            Node* copiedNode = curr->next;
            curr->next = copiedNode->next; // Restore the original list
            if (copiedNode->next) {
                copiedNode->next = copiedNode->next->next; // Set the next pointer for the copied list
            }
            curr = curr->next;
        }

        return newHead;
    }
};

// Helper function to print the list
void printList(Node* head) {
    while (head) {
        cout << "[" << head->val << ", ";
        if (head->random) {
            cout << head->random->val;
        } else {
            cout << "null";
        }
        cout << "] ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example 1
    Node* head1 = new Node(7);
    head1->next = new Node(13);
    head1->next->next = new Node(11);
    head1->next->next->next = new Node(10);
    head1->next->next->next->next = new Node(1);
    
    head1->random = nullptr;
    head1->next->random = head1;
    head1->next->next->random = head1->next->next->next->next;
    head1->next->next->next->random = head1->next->next;
    head1->next->next->next->next->random = head1;

    Solution sol;
    Node* copiedHead1 = sol.copyRandomList(head1);
    printList(copiedHead1);

    // Example 2
    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->random = head2;
    
    Node* copiedHead2 = sol.copyRandomList(head2);
    printList(copiedHead2);

    return 0;
}
