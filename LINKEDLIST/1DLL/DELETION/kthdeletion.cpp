#include<iostream>
#include<vector>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int data1, Node* next1){
            data = data1;
            next = next1;
        }
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
//! remove kth node/element
Node* removekth(Node* head,int k){
    if(head == NULL) return head;
    if(k==1) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int count = 0;
    Node* temp = head;
    Node* prev = NULL; // to track previous elmnt of target to link it with the next one
    while(temp != NULL){
        count++;
        // now check if count== k then link previous with next.next
        if(count==k){
            prev->next = prev->next->next; // link the previous with the elmnt just after target elmnt
            free(temp);
            break;
        }
        prev = temp; // remember previous before moving
        // move temp ahead
        temp = temp->next;
    }
    return head;
}
//! remove element
Node* removeElement(Node* head,int ele){
    if(head == NULL) return head;
    if(head->data == ele) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    Node* prev = NULL; // to track previous elmnt of target to link it with the next one
    while(temp != NULL){
        // now check if count== k then link previous with next.next
        if(temp->data == ele){
            prev->next = prev->next->next; // link the previous with the elmnt just after target elmnt
            free(temp);
            break;
        }
        prev = temp; // remember previous before moving
        // move temp ahead
        temp = temp->next;
    }
    return head;
}

//  Helper to print entire linked list
void printLL(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data;
        if(temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    vector<int> arr = {1,2,3,4};
    Node* head = convertArr2LL(arr);
    // head = removekth(head,5);
    head = removeElement(head,2);
    printLL(head);
    
}