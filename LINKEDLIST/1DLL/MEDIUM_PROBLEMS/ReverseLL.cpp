#include <iostream>
#include <stack>
using namespace std;
 
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* buildList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}
 
// Helper: free list memory
void freeList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}
 
//! Approach 1: Recursive
ListNode* reverseRecursive(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
 
    ListNode* newHead = reverseRecursive(head->next);
    ListNode* front = head->next;
    front->next = head;   // reverse the link
    head->next = nullptr; // break forward link
    return newHead;
}
 
//! Approach 2: Iterative (Optimal) — O(n) time, O(1) space
ListNode* reverseIterative(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* temp = head;
    while (temp != nullptr) {
        ListNode* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
 
//! Approach 3: Stack-based — O(n) time, O(n) space
ListNode* reverseStack(ListNode* head) {
    ListNode* temp = head;
    stack<int> st;
 
    while (temp != nullptr) {
        st.push(temp->val);
        temp = temp->next;
    }
 
    temp = head;
    while (temp != nullptr) {
        temp->val = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
 
    // ── Approach 1: Recursive ──
    ListNode* list1 = buildList(arr, n);
    cout << "Original:            ";
    printList(list1);
    list1 = reverseRecursive(list1);
    cout << "Recursive Reversed:  ";
    printList(list1);
    freeList(list1);
 
    cout << endl;
 
    // ── Approach 2: Iterative ──
    ListNode* list2 = buildList(arr, n);
    cout << "Original:            ";
    printList(list2);
    list2 = reverseIterative(list2);
    cout << "Iterative Reversed:  ";
    printList(list2);
    freeList(list2);
 
    cout << endl;
 
    // ── Approach 3: Stack ──
    ListNode* list3 = buildList(arr, n);
    cout << "Original:            ";
    printList(list3);
    list3 = reverseStack(list3);
    cout << "Stack Reversed:      ";
    printList(list3);
    freeList(list3);
 
    return 0;
}