#include<iostream>
using namespace std;
int main(){
    int n, k;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter kth bit (0-indexed): ";
    cin >> k;

    n = n & ~(1 << k);  // clears the k-th bit
    cout << "Result: " << n << endl;
}