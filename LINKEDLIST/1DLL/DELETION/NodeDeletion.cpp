#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Helper: array to linked list
ListNode* convertArr2LL(int arr[], int n){
    ListNode* head = new ListNode(arr[0]);
    ListNode* mover = head;
    for(int i = 1; i < n; i++){
        ListNode* temp = new ListNode(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// Helper: print linked list
void printLL(ListNode* head){
    ListNode* temp = head;
    while(temp != nullptr){
        cout << temp->val;
        if(temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << "\n";
}

// Solution
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main(){
    int arr[] = {1, 2, 3, 4};
    ListNode* head = convertArr2LL(arr, 4);

    cout << "Before: ";
    printLL(head);  // 1 -> 2 -> 3 -> 4

    // Let's delete node with value 2 (2nd node)
    ListNode* nodeToDelete = head->next; // points to node 2

    Solution sol;
    sol.deleteNode(nodeToDelete);

    cout << "After:  ";
    printLL(head);  // 1 -> 3 -> 4

    return 0;
}