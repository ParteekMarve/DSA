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

class StImp {
    Node* topNode = nullptr;
    int currsize = 0;

public:
    void push(int x) {
        Node* newNode = new Node(x);

        newNode->next = topNode;
        topNode = newNode;

        currsize++;
    }

    int pop() {
        if (currsize == 0)
            return -1;

        Node* temp = topNode;
        int ele = temp->data;

        topNode = topNode->next;

        delete temp;
        currsize--;

        return ele;
    }

    int peek() {
        if (currsize == 0)
            return -1;

        return topNode->data;
    }

    int size() {
        return currsize;
    }

    bool isEmpty() {
        return currsize == 0;
    }
};

int main() {
    StImp s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.peek() << "\n";
    s.pop();
    cout << "Top after pop: " << s.peek() << "\n";
    cout << "Size: " << s.size() << "\n";
    cout << "isEmpty: " << s.isEmpty() << "\n";

    return 0;
}