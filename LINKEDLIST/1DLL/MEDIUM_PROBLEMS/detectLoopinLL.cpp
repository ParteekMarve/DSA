#include <iostream>
#include <unordered_map>
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

    // ✅ Approach 1: Floyd's Cycle Detection (Optimal)
    bool hasCycle_Floyd(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                return true;
            }
        }

        return false;
    }


    // ✅ Approach 2: Using unordered_map (Brute Force)
    bool hasCycle_Map(ListNode *head) {

        unordered_map<ListNode*, int> node_map;

        ListNode* pos = head;

        while(pos != NULL) {

            if(node_map.find(pos) != node_map.end()) {
                return true;
            }

            node_map[pos] = 1;

            pos = pos->next;
        }

        return false;
    }
};


int main() {

    // Creating linked list
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);

    head->next = second;
    second->next = third;
    third->next = fourth;

    fourth->next = second; // creating a loop
    Solution obj;


    // Testing Floyd Approach
    if(obj.hasCycle_Floyd(head))
        cout << "Cycle detected (Floyd method)\n";
    else
        cout << "No cycle detected (Floyd method)\n";


    // Testing Hashmap Approach
    if(obj.hasCycle_Map(head))
        cout << "Cycle detected (Map method)\n";
    else
        cout << "No cycle detected (Map method)\n";


    return 0;
}