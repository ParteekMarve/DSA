#include <iostream>
using namespace std;

// ─────────────────────────────────────────────
//  Node definition
// ─────────────────────────────────────────────
struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// ─────────────────────────────────────────────
//  Helper utilities
// ─────────────────────────────────────────────
Node* createList(int arr[], int n) {
    if (n == 0) return NULL;
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

void freeList(Node* head) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

// 
//  APPROACH 1 — Recursive (Optimal) {trying opposite of the better approach}
//  Time: O(n)  |  Space: O(n) call stack
class SolutionRecursive {
public:
    // Returns the carry that propagates backwards
    int addOneUtil(Node* node) {
        if (node == NULL) return 1;  // seed carry at the tail
//* traversing till the end via recursion
        int carry = addOneUtil(node->next);
        int sum   = node->data + carry; // 
        node->data = sum % 10; // what the curr node's data will carry {if sum is 10 then it will conatain 0 and pass 1 to previous node}
        //! pass carry to the previous node
        return sum / 10;                
    }

    Node* addOne(Node* head) {
        int carry = addOneUtil(head);

        if (carry) {                      // leftmost digit also overflowed
            Node* newHead = new Node(carry);
            newHead->next = head;
            head = newHead;
        }
        return head;
    }
};

//  APPROACH 2 — Iterative with reversal (Better)
//  Time: O(n)  |  Space: O(1)
class SolutionIterative {
public:
    Node* reverseLL(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        while (curr != NULL) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;  // new head after reversal
    }

    Node* addOne(Node* head) {
        // 1st reverse the whole list 
        Node* rev_head = reverseLL(head);   // reverse: units digit first
        Node* curr = rev_head;
        int carry = 1;                      // we're adding 1

        while (curr != NULL) {
            curr->data += carry;
            if (curr->data < 10) {
                carry = 0;
                break;                      // no more carry, we're done
            }
            curr->data = 0;
            if (curr->next == NULL) {
                curr->next = new Node(1);   // new MSB node
                carry = 0;
                break;
            }
            curr = curr->next;
        }

        return reverseLL(rev_head);         // restore original order
    }
};

// ─────────────────────────────────────────────
//  main — test both approaches
// ─────────────────────────────────────────────
int main() {
    // Test cases: {digits of the number}
    int t1[] = {1, 9, 9};   // 199 + 1 = 200
    int t2[] = {9, 9, 9};   // 999 + 1 = 1000 (new node needed)
    int t3[] = {1, 2, 3};   // 123 + 1 = 124
    int t4[] = {9};          //   9 + 1 =  10
    cout << "======================================" << endl;
    cout << "  RECURSIVE APPROACH (Optimal - O(n) time, O(n) space)" << endl;
    {
        SolutionRecursive sol;

        Node* head1 = createList(t1, 3);
        cout << "Input : "; printList(head1);
        head1 = sol.addOne(head1);
        cout << "Output: "; printList(head1);
        freeList(head1);

        Node* head2 = createList(t2, 3);
        cout << "\nInput : "; printList(head2);
        head2 = sol.addOne(head2);
        cout << "Output: "; printList(head2);
        freeList(head2);

        Node* head3 = createList(t3, 3);
        cout << "\nInput : "; printList(head3);
        head3 = sol.addOne(head3);
        cout << "Output: "; printList(head3);
        freeList(head3);

        Node* head4 = createList(t4, 1);
        cout << "\nInput : "; printList(head4);
        head4 = sol.addOne(head4);
        cout << "Output: "; printList(head4);
        freeList(head4);
    }

    cout << "\n======================================" << endl;
    cout << "  ITERATIVE APPROACH (Better - O(n) time, O(1) space)" << endl;
    {
        SolutionIterative sol;

        Node* head1 = createList(t1, 3);
        cout << "Input : "; printList(head1);
        head1 = sol.addOne(head1);
        cout << "Output: "; printList(head1);
        freeList(head1);

        Node* head2 = createList(t2, 3);
        cout << "\nInput : "; printList(head2);
        head2 = sol.addOne(head2);
        cout << "Output: "; printList(head2);
        freeList(head2);

        Node* head3 = createList(t3, 3);
        cout << "\nInput : "; printList(head3);
        head3 = sol.addOne(head3);
        cout << "Output: "; printList(head3);
        freeList(head3);

        Node* head4 = createList(t4, 1);
        cout << "\nInput : "; printList(head4);
        head4 = sol.addOne(head4);
        cout << "Output: "; printList(head4);
        freeList(head4);
    }

    return 0;
}