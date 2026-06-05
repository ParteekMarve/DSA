#include<iostream>
using namespace std;
int main(){
    int a = 3;
    int b = 2;

    a = a^b; 
    b = a^b; // b = (a^b)^b = a
    // now b = a updated
    a = a^b; // a = (a^b)^a

    cout<<a<<" "<<b;
    
}