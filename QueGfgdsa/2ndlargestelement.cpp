#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n = 5;
    int arr[n] = {99,19,2,98,32};
    
    // sort(arr, arr + n);

    // for(int i = 0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // cout<<arr[n-2];//! not a god approach as T.C.= O(n*logn)

    //? Better method => Two pass search
    int mx = -1;  // for alargest no
    int smx = -1;
    for(int i = 0;i<n;i++){
        if(arr[i]> mx){
            mx = arr[i];
        }
    }
      cout<<mx<<endl; // max element found

    for(int i = 0;i<n;i++){
        
        if(arr[i] != mx && arr[i]> smx){  //! checks only if current elmt is less than max elemnt amd > smx(current)
            smx = arr[i];
        }
        
    }
    
cout<<smx; //! O(n) **
     
}