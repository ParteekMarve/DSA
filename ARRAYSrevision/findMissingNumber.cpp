#include<iostream>
using namespace std;
int main(){
    int n = 5;
    int arr[n];
    cout<<"enter array";
    for(int i= 0;i<n;i++){
        cin>>arr[i];
    }
    for(int i = 1;i<=n;i++){
        int flag = 0;
        for(int j = 0;j<n;j++){
            if(arr[j] == i){
                flag = 1;
                break;
            }
        }
        if(flag == 0) cout<< i;
    }
    
}