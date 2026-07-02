#include <iostream>
#include <stack>
using namespace std;

class QImpSt {
    
// main idea: instead of pushing in s1 and s2 push in s1 to s2 or vice versa when either of one is empty and requires top or pop
    stack<int> s1;
    stack<int> s2;

public:
    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s1.empty() && s2.empty())
            return -1;

        if (!s2.empty()) {
            int ele = s2.top();
            s2.pop();
            return ele;
        }
        else {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }

            int ele = s2.top();
            s2.pop();
            return ele;
        }
    }

    int top() {
        if (s1.empty() && s2.empty())
            return -1;

        if (!s2.empty()) {
            return s2.top();
        }
        else {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }

    int sizee() {
        return s1.size() + s2.size();
    }

    bool empty() {
        return s1.empty() && s2.empty();
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