#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n = 5;
    int arr[n] = {9,9,9,9,9};
    int mx = INT16_MIN;  // set to min int value
    int smx = INT16_MIN; // set to min int value
    
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
    if(smx == INT16_MIN){
        cout<<-1;
    }
    else{
        cout<<smx;
    }
    
 //! O(n) **
     
}