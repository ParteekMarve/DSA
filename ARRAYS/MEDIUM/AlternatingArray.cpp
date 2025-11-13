#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int arr[n];
    for(int i= 0;i<n;i++){
        cin>>arr[i];
    }
    //! 1. BRUTE FORCE
    // vector<int> pos;
    // vector<int> neg;
    // int final_arr[n];
    // for(int i = 0;i<n;i++){
    //     if(arr[i] > 0){
    //         pos.push_back(arr[i]);
    //     }
    //     else {
    //         neg.push_back(arr[i]);
    //     }
    // }
    // int postn_ptr1 = 0;   // position pointer for positive vector
    // int postn_ptr2 = 0;  //  position pointer for negative vector
    // for(int i = 0;i<n;i++){
    //     if(i%2==0){
    //         final_arr[i] = pos[postn_ptr1++];
    //     }
    //     else{
    //          final_arr[i] = neg[postn_ptr2++];
    //     }
    // }
    // for(int i= 0;i<n;i++){
    //     cout<< final_arr[i] << " ";
    // }

    //! 2. OPTIMAL
    int pos_idx = 0;
    int neg_idx = 1;
    int final_arr[n];
    for(int i = 0;i<n;i++){
        if(arr[i] > 0){
            final_arr[pos_idx] = arr[i];   //! ***NEW CONCEPT***
            pos_idx+= 2;
        }
        else {
            final_arr[neg_idx] = arr[i];
            neg_idx+= 2;
        }
    }
    for(int i= 0;i<n;i++){
        cout<< final_arr[i] << " ";
    }
}