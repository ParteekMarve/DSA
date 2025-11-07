#include<iostream>
using namespace std;
int main(){
    //! Brute Force - using merge or quick sort
    
    //! Better  T.C. = O(n+n+n) = O(n) 🤞
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int arr[n];
    for(int i= 0;i<n;i++){
        cin>>arr[i];
    }
    // int cnt1 = 0;
    // int cnt2 = 0;
    // int cnt0 = 0;
    // for(int i = 0;i<n;i++){
    //     if(arr[i] == 0) cnt0++;
    //     else if(arr[i] == 1) cnt1++;
    //     else cnt2++;
    // }
    // int index = 0;
    // for (int i = 0; i < cnt0; i++) arr[index++] = 0;//! NEW THING**
    // for (int i = 0; i < cnt1; i++) arr[index++] = 1;
    // for (int i = 0; i < cnt2; i++) arr[index++] = 2;
    // for(int i = 0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }

    //!OPTIMAL APPROACH
    int low = 0;
    int high = n-1;
    int mid = 0;
    while(mid<=high){
        if(arr[mid] == 0){
           swap(arr[mid],arr[low]);
           mid++;
           low++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
}