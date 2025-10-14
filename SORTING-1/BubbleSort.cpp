#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
  
    for(int i = n-1;i>=0;i--){ //! bcz array constain n-1 elements but don't have to check n-1th element
        int didSwap = 0;
        for(int j = 0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                didSwap = 1;
            }
        }
        if(didSwap == 0){
            break;
        }
        cout<<"how many times it runs\n"; // when array is already sorted -> best case this line will not be printed bcz there was no swapping at all

        
    }
     for(int i = 0;i<n;i++){
            cout<<arr[i]<<" ";
        }
    
    
}
