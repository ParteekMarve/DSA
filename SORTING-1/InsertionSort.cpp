#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    for(int i = 0;i<=n-1;i++){ //! if we do only i<n-1 then it will not go till last element or last index
        int j = i; //! 
        while(j>0 && arr[j-1]>arr[j]){
              int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
                j--;
        }
    }
    for(int i = 0;i<n;i++){
            cout<<arr[i]<<" ";
        }
}