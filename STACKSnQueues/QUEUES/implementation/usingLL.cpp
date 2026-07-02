#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class qImp {
    Node* start = nullptr;
    Node* end = nullptr;
    int size = 0;
    
public:
    void push(int x) {
        Node* newNode = new Node(x);
        if(start == nullptr){
            start = end = newNode;
        }
        else {
            end->next = newNode;
            end = newNode;
        }
        size++;

    }

    int pop() {
        if(start == nullptr) return -1;

        Node* temp = start;
        int ele = temp->data;
    
        start = start->next;
        delete temp;
        // if there's only 1 node and after moving start it reaches null the end will still be pointing towards the 
        if (start == nullptr) {
            end = nullptr;
        }

        size--;
        return ele;
    }

    int top() {
        if(start == nullptr) return -1;

        return start->data;
    }

    int sizee() {
        return size;
    }

};

int main() {
    qImp qu;

    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);

    cout << qu.top() << endl; 
    cout << qu.pop() << endl;     
    cout << qu.top() << endl;      
    cout << qu.pop() << endl;      
    cout << qu.pop() << endl;    
    cout << qu.sizee() << endl;
    cout << qu.top() << endl; 
    return 0;
}


