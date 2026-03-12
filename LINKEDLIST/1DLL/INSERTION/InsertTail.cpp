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
//! New Node In Front of Head making it as new head
Node* InsertTail(Node* head,int val){
    if(head == NULL) return new Node(val);
    Node* temp = head;
    
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* newNode = new Node(val); // last pointing towards NULL
    temp->next = newNode;
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
    head = InsertTail(head,0);
    printLL(head);
    
    
}