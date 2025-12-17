#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n = 89;
    //! BRUTE FORCE
    // int count = 0;
    // while(n>0){
    //     count++;
    //     n = n/10;
    // }
    // cout<<count;

    //! OPTIMAL
    int countt = (int)(log10(n)+ 1);
    cout<<countt;
}