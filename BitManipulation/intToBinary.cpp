#include<iostream>
#include<algorithm>
using namespace std;

string converttoBinary(int n){

    string res = "";
    while(n!=1){
        // store remainders
        if(n%2 == 1){
            // then store the remainder as 1
            res+="1";
        }
        else {
            res+="0";
        }
        n = n/2;
    }
    // now done just reverse the res and return 
    res+="1";
    reverse(res.begin(),res.end());
    cout<<res;
}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    converttoBinary(n);
}