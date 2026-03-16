#include<iostream>
#include<vector>
using namespace std;
class Node {
    public:
        int data; 
        Node* next; 
        Node* prev;

        //! Constructor for data and next(pointer){Initialization}
        Node(int data1,Node* next1,Node* prev1){
            data = data1;
            next = next1;
            prev = prev1;
        }
        //! Constructor for data only(representing Null(end)){Initialization}
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

Node* insert_new_tail(Node* head,int val){
    Node* back = head;
    while(back->next != NULL){
        back = back->next;
    }
    Node* newTail = new Node(val,nullptr,back);
    back->next = newTail;
    
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
    head = insert_new_tail(head,5);
    print(head);
}