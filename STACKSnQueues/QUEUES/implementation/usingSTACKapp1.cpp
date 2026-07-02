#include <iostream>
#include<stack>
using namespace std;

class QImpSt {
    
// main idea: put into s1 store and pop it and push to s2 then untill s1 becomes empty then push new element and push all s2 elemts to s1 again
    stack<int> s1;
    stack<int> s2;

public:
    void push(int x) {

        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);

        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
              
    }

    int pop() {
        if(s1.size() == 0) return -1;
        else {
            int ele = s1.top();
            s1.pop();
            return ele;
        }
    }

    int top() {
        if(s1.empty()) return -1;
        return s1.top();
    }

    int sizee() {
        return s1.size();
    }

};

int main() {
    QImpSt qu;

    qu.push(1);
    qu.push(2);
    qu.push(3);

    cout << qu.top() << endl;      
    cout << qu.pop() << endl;   
    cout << qu.top() << endl;    
    cout << qu.sizee() << endl;    

    return 0;
}