#include<iostream>
using namespace std;
int main(){
    int n, k;
    cout << "Enter n: ";
    cin >> n;

    n = n & (n-1);
    cout << "Result: " << n << endl;
}