#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n =8;
    int arr[n] = { 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1};
    //! OPTIMAL {O(n),O(1)}
    // int pos = 0;
    // for(int i = 0;i<n;i++){
    //     if(arr[i] != 0){
    //          arr[pos] = arr[i];
    //         pos++;
    //     }
    // }
    // for(int i = pos;i<n;i++){
    //     arr[i] = 0;
    // }

    //! Brute Force {high T.C & S.C.}

    vector<int> temp;
    for(int i =0;i<n;i++){
        if(arr[i]!= 0){
            temp.push_back(arr[i]);
        }
    }
    for(int i = 0;i<temp.size();i++){
        arr[i] = temp[i];
    }
    int nzero = temp.size();
    for(int i = nzero;i<n;i++){
        arr[i] = 0;
    }

    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    
}