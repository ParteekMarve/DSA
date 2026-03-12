#include<iostream>
#include<vector>
using namespace std;
//? Node class representing a Node of a Linked List
class Node {
    public:
        int data; // data value
        Node* next; // pointer to next node

        //! Constructor for data and next(pointer){Initialization}
        Node(int data1,Node* next1){
            data = data1;
            next = next1;
        }
        //! Constructor for data only(representing Null(end)){Initialization}
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};
Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    // traverse across rest of the array
    for (int i = 1;i<arr.size();i++){
        Node* temp = new Node(arr[i]); // !Creates new node for each array element
        mover->next = temp; //? Links current last node to new node
                            //? mover is just a COPY of head's address      
        mover = temp;
    }
    return head; // bcz in linked list we are asked to return head of the LL not the whole LL
}

// Deletion of head or getting new head
Node* removeHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

int main(){
    vector<int> arr = {1,2,3,4};
    Node* head = convertArr2LL(arr);
    head = removeHead(head);
    cout << head->data;
    
}