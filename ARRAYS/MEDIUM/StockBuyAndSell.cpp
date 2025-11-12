#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int arr[n];
    for(int i= 0;i<n;i++){
        cin>>arr[i];
    }
    int mini = arr[0];
    int profit = 0;
    int cp = 0;
    for(int i = 1;i<n;i++){
        cp = arr[i] - mini;    //  arr[i] will be sp  and mini will be temporary cost price
        profit = max(cp,arr[i]); 
        mini = min(mini,arr[i]);  // 
    }
    cout<< profit;
    
}    
