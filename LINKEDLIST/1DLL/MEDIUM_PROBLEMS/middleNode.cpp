#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//! Optimal{Tortoise(Slow)-Heir(Fast) Pointer Theorem}{}
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         if (head == NULL || head->next == NULL) {
//             return head;
//         }
//         ListNode* slow = head;
//         ListNode* fast = head;
//         while( fast != NULL && fast->next!= NULL){
//             slow = slow->next;
//             fast = fast->next->next;
//             // after these moves the *slow* pointer will be at the middle

//         }
//         return slow;
//     }
// };
//! Brute Force
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        int count = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        int mid = (count / 2) + 1;
        temp = head;
        while (temp != NULL) {
            mid = mid - 1;
            if (mid == 0) {
                break;
            }
            temp = temp->next;
        }
        return temp;
    }
};

int main() {
    // Build list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next     = new ListNode(2);
    head->next->next         = new ListNode(3);
    head->next->next->next   = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode* mid = sol.middleNode(head);

    cout << "Middle node value: " << mid->val << endl;
    cout << "From middle to end: ";
    while (mid != NULL) {
        cout << mid->val << " ";
        mid = mid->next;
    }
    cout << endl;

    return 0;
}