#include<iostream>
#include<algorithm>
using namespace std;

// string converttoBinary(int n){

//     string res = "";
//     while(n!=1){
//         if(n%2 == 1){
//             res+="1";
//         }
//         else {
//             res+="0";
//         }
//         n = n/2;
//     }
//     res+="1";
//     reverse(res.begin(),res.end());
//     return res;
// }

int main(){
    int n;
    int k;
    cout<<"Enter n:";
    cin>>n;
    cout<<"Enter kth bit: ";
    cin>>k;
    // !Brute Force
    // string s = converttoBinary(n);
    //  can directly check whetheer the kth bit is set or not 
    // int idx = s.size() - 1 - k; // directly at kth bit(index)

    // if(idx >= 0 && idx < s.size() && s[idx] == '1'){
    //     cout << "Yes is a set";
    // }
    // else {
    //     cout<<"No";
    // }
// by left shift
    if((n & (1 << k)) != 0){
        cout << "Yes is a set";
    }
    else {
        cout<<"Not a set";
    }
}