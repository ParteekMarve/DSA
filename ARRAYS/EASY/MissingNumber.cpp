#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    // int arr[n];
    // for(int i = 0;i<n;i++){
    //     cin>>arr[i];
    // }
    //! Brute Force(O(n*n)could vary)
    // bool found;
    // for(int mnum = 1;mnum<=n;mnum++){  //* bcz the number can be between 1 to n-1 but also the missing num can be n itself
    //     found = false;     //* Resets flag(a mark for us) for each new number
    //     for(int i = 0;i<=n-2;i++){
    //         if(arr[i] == mnum){
    //             found = true;
    //             break;
    //         }
    //     }
    //     if(!found){
    //         cout<<mnum;
    //     }
    // }
    //! BETTER 
    // int hasharr[n+1] = {0};
    // for(int i = 0;i<n;i++){
    //     hasharr[arr[i]]++;   // we counted frequency of each element 
    // }
    // for(int mnum = 1;mnum<=n-1;mnum++){
    //     if(hasharr[mnum] == 0){  // if frequency of mnum idx is 0 this means that is the missing number
    //         cout<<mnum;
    //     }
    // }
    //! OPTIMAL-1 {T.C. = O(n),S.C. = O(1)}                               Risk of overflow
                                    /*❌ Possible if n is large (since n*(n+1)/2 can exceed int range)*/
    // int arr[n-1];
    // for(int i = 0;i<n-1;i++){
    //     cin>>arr[i];
    // }
    // int sN = n*(n+1)/2;
    // int sE = 0;
    // for(int i = 0;i<n-1;i++){
    //     sE = sE + arr[i];
    // }
    // int mnum =  sN - sE;
    // cout<<mnum;
    //! OPTIMAL-2 {**XOR** method}  New concept    NO RISK OF OVERFLOW
    int arr[n-1];
    for(int i = 0;i<n-1;i++){     //? this one is slightly better
        cin>>arr[i];
    }
    int xorall = 0;
    for(int i = 0;i<=n-2;i++){
        xorall = xorall^arr[i]^(i+1);
    }
    xorall = xorall^n;
    cout<<xorall;
}