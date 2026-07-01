#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Helper: insert at end
void insertAtEnd(Node** head_ref, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    Node* curr = *head_ref;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = newNode;
    newNode->prev = curr;
}

// Helper: print list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL) cout << " <-> ";
        head = head->next;
    }
    cout << " -> NULL" << endl;
}

//! =================== OPTIMAL ===================

Node* deleteAllOccurOfX_Optimal(Node* head, int x) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == x) {
            if (head == temp) {       
                head = temp->next;     // just update local head
            }
            Node* nextNode = temp->next;
            Node* prevNode = temp->prev;
            if (nextNode != NULL) nextNode->prev = prevNode;
            if (prevNode != NULL) prevNode->next = nextNode;
            free(temp);
            temp = nextNode;
        } else {
            temp = temp->next;
        }
    }
    return head;                       
}

// =================== BRUTE FORCE ===================
Node* deleteAllOccurOfX_Brute(Node* head, int x) {
    // Step 1: Collect non-x values
    vector<int> list;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data != x)
            list.push_back(temp->data);
        temp = temp->next;
    }
    // Step 2: Delete entire list
    temp = head;
    while (temp != NULL) {
        Node* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
    head = NULL;                       
    // Step 3: Rebuild
    for (int i = 0; i < list.size(); i++) {
        Node* newNode = new Node();
        newNode->data = list[i];
        newNode->next = NULL;
        newNode->prev = NULL;
        if (head == NULL) {          
            head = newNode;
        } else {
            Node* curr = head;
            while (curr->next != NULL)
                curr = curr->next;
            curr->next = newNode;
            newNode->prev = curr;
        }
    }
    return head;                       //  return updated head
}

int main() {
    // ---- Test Optimal ----
    cout << "=== OPTIMAL ===" << endl;
    Node* head1 = NULL;
    insertAtEnd(&head1, 2);
    insertAtEnd(&head1, 3);
    insertAtEnd(&head1, 2);
    insertAtEnd(&head1, 4);
    insertAtEnd(&head1, 2);

    cout << "Before: "; printList(head1);
    head1 = deleteAllOccurOfX_Optimal(head1, 2);  //  capture returned head
    cout << "After:  "; printList(head1);

    // ---- Test Brute Force ----
    cout << "\n=== BRUTE FORCE ===" << endl;
    Node* head2 = NULL;
    insertAtEnd(&head2, 2);
    insertAtEnd(&head2, 3);
    insertAtEnd(&head2, 2);
    insertAtEnd(&head2, 4);
    insertAtEnd(&head2, 2);

    cout << "Before: "; printList(head2);
    head2 = deleteAllOccurOfX_Brute(head2, 2);    //  capture returned head
    cout << "After:  "; printList(head2);

    return 0;
}