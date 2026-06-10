#include<iostream>
using namespace std;
int main(){
    int n;
    int k;
    cout<<"Enter n:";
    cin>>n;
    cout<<"Enter kth bit: ";
    cin>>k;

    n = n | (1<<k);
    cout<<n;    
}