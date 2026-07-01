#include <iostream>
using namespace std;

class qImp {
    int start = -1;
    int end = -1;
    int q[5];
    int currsize = 0;

public:
    void push(int x) {
        if (currsize == 5) {
            cout << "Overflow\n";
            return;
        }

        if (currsize == 0) {
            start = end = 0;
        }
        else {
            end = (end + 1) % 5;
        }

        q[end] = x;
        currsize++;
    }

    int pop() {
        if (currsize == 0) {
            cout << "Queue Underflow\n";
            return -1;
        }

        int ele = q[start];

        if (currsize == 1) {
            start = end = -1;
        }
        else {
            start = (start + 1) % 5;
        }

        currsize--;
        return ele;
    }

    int top() {
        if (currsize == 0) {
            cout << "Queue Empty\n";
            return -1;
        }

        return q[start];
    }

    int sizee() {
        return currsize;
    }

    bool empty() {
        return currsize == 0;
    }
};

int main() {
    qImp qu;

    qu.push(1);
    qu.push(2);
    qu.push(3);

    cout << qu.top() << endl;      // 1
    cout << qu.pop() << endl;      // 1
    cout << qu.top() << endl;      // 2
    cout << qu.sizee() << endl;    // 2

    return 0;
}