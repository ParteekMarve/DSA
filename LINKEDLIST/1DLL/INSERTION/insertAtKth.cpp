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
//! New Node at kth position
Node* Insert_at_Kth(Node* head,int k,int ele){
    if(head == NULL){
        if(k==1){
            return new Node(ele);
        }
        else { // not possible
            return NULL;
        }
    }
    // case1. if k==1
    if(k==1){
        // the new node will be new head which will be pointing to initial head
        Node* newNode = new Node(ele,head);
        return newNode;
    }
    int count = 0;
    Node* temp = head;
    while(temp!= NULL){
        count++;
        if(count == (k-1)){ //! main check 
            Node* newNode = new Node(ele,temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;

    
}
//! New Node before value x
Node* Insert_before_x(Node* head,int x,int ele){
    if(head == NULL){
        return NULL;
    }
    
    if(head->data == x){
        return new Node(ele,head);
    }
    Node* temp = head;
    while(temp->next != NULL){
        if(temp->next->data == x){
            Node* newNode = new Node(ele,temp->next);
            temp->next = newNode;
            break;
        }
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
    head = Insert_before_x(head,3,100);
    printLL(head);
    
}