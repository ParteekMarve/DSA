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

void deletNode(Node* temp){
    Node* back = temp->prev;
    Node* front = temp->next;
    if(front== NULL){
        back->next = nullptr;
        temp->next = nullptr;
        free(temp);
        return;
    }
    back->next = front;
    front->prev = back;

    temp->next = temp->prev = nullptr;
    free(temp);
    return;
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
    deletNode(head->next->next);
    print(head);
}