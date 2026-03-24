#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:

    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect cycle
        while(fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {

                // Step 2: Find starting node of cycle
                slow = head;

                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        return NULL;
    }
};


int main() {

    // Creating nodes
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);

    // Linking nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Creating cycle
    fifth->next = third;   // cycle starts at node with value 3


    Solution obj;

    ListNode* result = obj.detectCycle(head);

    if(result != NULL)
        cout << "Cycle starts at node with value: " << result->val << endl;
    else
        cout << "No cycle detected" << endl;


    return 0;
}