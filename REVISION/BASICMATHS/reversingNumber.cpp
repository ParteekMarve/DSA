#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n = 123;
    int rev_num = 0;
    while(n>0){
        int last_num = n % 10;
        
        rev_num = (rev_num * 10) + n;
        n = n/10;  
    }
}