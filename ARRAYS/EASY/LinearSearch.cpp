#include<iostream>
using namespace std;
int lsearch(int arr[],int num){
    for(int idx = 0;idx<5;idx++){
        if(arr[idx]== num){
            return idx;
        }
    }
    return -1;
}
int main(){
    int trgt;
    cout<<"Enter number: ";
    cin>>trgt;
    int arr[5] = {1,2,3,5,4};
    int result  = lsearch(arr,trgt);
    cout<<result;
}