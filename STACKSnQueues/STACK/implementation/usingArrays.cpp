#include<iostream>
using namespace std;

class StImp{
    int top = -1;
    int st[10];

public:
    void push(int x){
        if(top >= 9){
            cout << "Stack Overflow\n";
            return;
        }
        st[++top] = x;
    }

    void pop(){
        if(top == -1){
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    int peek(){  // .top()
        if(top == -1){
            cout << "Stack is empty\n";
            return -1;
        }
        return st[top];
    }

    bool isEmpty(){
        return top == -1;
    }

    int size(){
        return top + 1;
    }
};

int main(){
    StImp s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.peek() << "\n";  // 30
    s.pop();
    cout << "Top after pop: " << s.peek() << "\n";  // 20
    cout << "Size: " << s.size() << "\n";  // 2
    cout << "isEmpty: " << s.isEmpty() << "\n";  // 0

    return 0;
}