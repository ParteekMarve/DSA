#include<iostream>
using namespace std;
int main(){
    int n =5;
    int k;
    cout<<"enter k: ";
    cin>>k;
    int arr[5] = {1,2,3,4,5};
       //! T.C. = O(n) 
        for(int i = 0;i<=n-2;i++){
        swap(arr[i],arr[i+1]);
    }
    
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}