#include<iostream>
#include<stack>
using namespace std;

class MinStack {
public:
    stack<int> s1;
    stack<int> minSt; // contains min values till current point
    MinStack() {
        
    }
    
    void push(int val) {
        //each time push the minumum value among st.top and x so when we need the minimum among the current stack we just call the minSt.top which contains minimum element among current combination 
        s1.push(val);
        if(minSt.empty() || val <= minSt.top()) minSt.push(val);
    }
    
    void pop() {
        if(s1.top() == minSt.top()) minSt.pop();
        s1.pop();
    }
    
    int top() {
        return s1.empty() ? -1 : s1.top();
    }
    
    int getMin() {
        return minSt.empty() ? -1 : minSt.top();
    }
};


int main(){
    MinStack st;
    
    st.push(5);
    st.push(3);
    st.push(7);
    cout << "Min: " << st.getMin() << endl; // 3
    
    st.pop(); // removes 7
    cout << "Top: " << st.top() << endl;    // 3
    cout << "Min: " << st.getMin() << endl; // 3
    
    st.pop(); // removes 3
    cout << "Min: " << st.getMin() << endl; // 5
}

