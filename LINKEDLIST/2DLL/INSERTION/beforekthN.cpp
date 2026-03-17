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

Node* insert_before_kthNode(Node* head,int k,int val){
    if(k == 1){
        return insert_before_kthNode(head,k,val);
    }

    Node* knode = head;
    int count = 0;
    while(knode->next != NULL){
        count++;
        if(count==k) break;
        knode = knode->next;
    }
    Node* back = knode->prev;
    Node* newNode = new Node(val,knode,back);
    back->next = newNode;
    knode->prev  = newNode;
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
    head = insert_before_kthNode(head,3,5);
    print(head);
}