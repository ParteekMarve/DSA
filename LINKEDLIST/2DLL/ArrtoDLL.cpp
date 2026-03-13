#include<iostream>
#include<vector>
using namespace std;
//? Node class representing a Node of a Linked List
class Node {
    public:
        int data; // data value
        Node* next; // pointer to next node
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
    // traverse across rest of the array
    for (int i = 1;i<arr.size();i++){
        Node* temp = new Node(arr[i]); // !Creates new node for each array element
        prev->next = temp; //? Links current last node to new node
                            //? mover is just a COPY of head's address      
        prev = temp;
    }
    return head; // bcz in linked list we are asked to return head of the LL not the whole LL
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
    print(head);
}