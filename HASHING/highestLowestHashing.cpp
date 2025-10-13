#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    int n;
    cout<<"enter n: ";
    cin>>n;
    int arr[n];
    for(int i= 0;i<n;i++){
        cin>>arr[i];
    }
    // precompute
    unordered_map<int,int> mpp;
    for(int  i= 0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto it: mpp){
        cout<< it.first <<"->"<<it.second<<endl;
    }

    int max_fre = 0; int min_fre = n; //! bcz min frequecy of a number cant be greater than number of elements 
    int maxEle = -1; int minEle = -1; //! not = 0 bcz if there will be zero as element in array then there will be confusion

    for(auto &it: mpp){
        if(it.second > max_fre){
           max_fre = it.second;
            maxEle = it.first;
        }
        if(it.second < min_fre){
            min_fre = it.second;
            minEle = it.first;
        }
    }
    cout<<maxEle<< "has highest frequency "<<max_fre<<endl;
    cout<<minEle<< "has lowest frequency  "<<min_fre<<endl;
}

