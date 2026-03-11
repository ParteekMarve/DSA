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

int main(){
    vector<int> arr = {1,2,3,4};

    //* Creating 1st Node
    Node* y = new Node(arr[2]);
    
    //* Print memory location of node
    cout<< y<<endl;

    //* Print Data stored in the node
    cout<< y->data;
}