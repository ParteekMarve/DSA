#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n = 111;
    int org_num = n;
    int rev_num = 0;
    while(n>0){
        int last_num = n % 10;
        rev_num = (rev_num * 10) + last_num;
        n = n/10;  
    }
    if(org_num == rev_num){
        cout<<"Palindrome";
    }
    else {
        cout<<"Not Palindrome";
    }
}