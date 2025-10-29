#include<iostream>
using namespace std;
int main(){
    int n =5;
    int arr[5] = {1,2,3,4,5};
       //! T.C. = O(n) 
    //     for(int i = 0;i<=n-2;i++){
    //     swap(arr[i],arr[i+1]);
    // }
    //?     OR

    int temp = arr[0];
    for(int i =1;i<n;i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
    
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}