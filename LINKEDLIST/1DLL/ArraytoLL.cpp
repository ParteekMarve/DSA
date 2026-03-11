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

int main(){
    vector<int> arr = {1,2,3,4};
    Node* head = convertArr2LL(arr);
    cout<< head->next<<endl; //prints address 
    cout<< head->data;// prints curent node's value
}