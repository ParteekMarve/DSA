#include<iostream>
#include<queue>
using namespace std;

class StImp{
    queue<int> q;

    int top = -1;

public:
    void push(int x){
        // when push a new ele take all the elments before it place after the current element keeeping the order same
         // if there are already some elements 
            // can do it directly by rotataion method
            q.push(x);
            for(int i = 1;i<q.size();i++){
                q.push(q.front());
                q.pop();
            }
    }

    int pop() {
        if(q.empty()) {
            throw runtime_error("Stack is empty");
        }
        int val = q.front();
        q.pop();
        return val;
    }

    int peek() {
        if(q.empty()) {
            throw runtime_error("Stack is empty");
        }
        return q.front();
    }

    int size(){
        return q.size();
    }
};

int main(){
    StImp s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.peek() << "\n";  // 30
    cout<< s.pop();
    cout << "Top after pop: " << s.peek() << "\n";  // 20
    cout << "Size: " << s.size() << "\n";  // 2

    return 0;
}