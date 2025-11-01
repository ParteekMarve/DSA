#include<iostream>
using namespace std;

int main(){
    int arr[6] = {1,1,0,1,1,1};
    int count1 = 0;
    int maxCount = 0;
    for(int i=0;i<6;i++){
        if(arr[i] == 1){
            count1++;
        }
        else{
            count1 = 0;
        }
        maxCount = max(count1,maxCount);
    }
    cout<<maxCount;
}