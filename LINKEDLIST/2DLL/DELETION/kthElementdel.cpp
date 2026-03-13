#include<iostream>
#include<vector>
using namespace std;

class Node {
    public:
        int data; // data value
        Node* next; // pointer to next node
        Node* prev;

        Node(int data1,Node* next1,Node* prev1){
            data = data1;
            next = next1;
            prev = prev1;
        }

        Node(int data1){
            data = data1;
            next = nullptr;
            prev = nullptr;
        }
};
Node* convertArr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (int i = 1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev); 
        prev->next = temp;  
        prev = temp;
    }
    return head; 
}

Node* delete_Head(Node* head){
    if(head==NULL || head->next == NULL) return NULL;
    Node* prev = head;
    head = head->next;
    head->prev = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

Node* delete_tail(Node* head) {

    Node* tail = head;

    while (tail->next != NULL) {
        tail = tail->next;
    }

    Node* newTail = tail->prev;
    newTail->next = nullptr;
    tail->prev = nullptr;

    delete tail;
    return head;
}

Node* delete_kth(Node* head,int k) {
    if(head == NULL) return head;
    int cnt = 0;
    Node* knode = head;
    while(knode!= NULL){
        cnt++;
        if(cnt==k) break; 
        knode = knode->next;
    }
    Node* back = knode->prev; 
    Node* front = knode->next;
    if(back == NULL and front == NULL){
        return NULL;
    }
    else if(back == NULL){ // measn it is at head
        return delete_Head(head); //  return head
    }
    else if(front == NULL){ // means it is at end
        return delete_tail(head); // remove tail
    }
    back->next = front; // linking both to each other
    front->prev = back;

    knode->next = nullptr; // removing the knode
    knode->prev = nullptr;
    
    delete knode;

    return head;
}

void print(Node* head){
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
    Node* head = convertArr2DLL(arr);
    head = delete_kth(head,2);
    print(head);
}