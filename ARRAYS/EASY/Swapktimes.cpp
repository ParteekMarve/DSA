#include<iostream>
using namespace std;
void reverse(int arr[],int start, int end){     
            while(start<=end){
                int temp = arr[start];
                arr[start] = arr[end];
                arr[end] = temp;
                start++;
                end--;
            }
}
int main(){
    int n =7;
    int k;
    cout<<"enter k: ";
    cin>>k;
    k = k%n;
    int arr[7] = {1,2,3,4,5,6,7};
    // for(int time = 0;time<k;time++){    //! T.C. = O(n*k) much for larger arrays
    //     for(int i = 0;i<=n-2;i++){
    //     swap(arr[i],arr[i+1]);
    // }
    // }
    
    //?     OR 
    //! Optimal and best

    reverse(arr,0,n-k-1);
    reverse(arr,n-k,n-1);
    reverse(arr,0,n-1); 

    
    //?     OR
    //! BRUTE Force 
    // int temp[k];
    // for(int i = 0;i<k;i++){
    //     temp[i] = arr[i];
    // }
    
    // for(int  i = k;i<n;i++){
    //     arr[i-k] = arr[i];
    // }
     
    // for(int i=n-k;i<n;i++){
    //     arr[i] = temp[i-(n-k)]; // or = temp[i-k-1] both are same
    // }
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}