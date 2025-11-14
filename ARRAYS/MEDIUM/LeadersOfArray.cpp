#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int arr[n];
    for(int i= 0;i<n;i++){
        cin>>arr[i];
    }
    //! BRUTE FORCE
    // vector<int> ans;
    // for(int i = 0;i<n;i++){
    //     int crnt_leader = arr[i];
    //     int j;
    //     for(j = i+1;j<n;j++){
    //         if(arr[j] > crnt_leader){
    //             break;

    //         }
    //     }
    //     if(j == n){  //! means we dinn't found any element greater than the cureent leader 
    //         ans.push_back(crnt_leader);  //! then store it our answer vector
    //     }
    // }

    // for(int i = 0;i< ans.size();i++){
    //     cout<< ans[i] << " ";
    // }

    //! OPTIMAL 
    vector<int> ans;
    ans.push_back(arr[n-1]);
    int max_elmnt = arr[n-1];  //! bcz last elmnt always considered as leader and there fore it will be considered max if we start form right

    for(int i = n-2; i>=0;i--){  // bcz (n-1)th is already leader 
        if(arr[i] > max_elmnt){
            ans.push_back(arr[i]);
            max_elmnt = arr[i];
        }
    }
    for(int i = 0;i< ans.size();i++){
        cout<< ans[i] << " ";
    }
}    