
#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main(){
    int a1[6] = {1,2,3,4,5,6};
    int a2[6] = {3,4,5,6,7,8};
    //! OPTIMAL Method {T.C. = O(n1 + n2), S.C.= O(n1+n2)}

    vector<int> uarr;
    int i =0;
    int j=0;
    while(i<6 and j<6){
        if(a1[i]<= a2[j]){ //* If the current element of a1 is smaller (or equal) than that of a2: did this bcz we want union in sorted order
            if(uarr.size() == 0 || uarr.back() != a1[i]){
            uarr.push_back(a1[i]);
        }
        i++;
        }
        else{
            if(uarr.size() == 0 || uarr.back() != a2[j]){
            uarr.push_back(a2[j]);
        }
        j++;
        }
    }
    while (j<6){   // if 1st array finishes first 
        if(uarr.size() == 0 || uarr.back() != a2[j]){
            uarr.push_back(a2[j]);
        }
        j++;
    }    
    while (i<6){  // if 2nd array finishes 1st
        if(uarr.size() == 0 || uarr.back() != a1[i]){
            uarr.push_back(a1[i]);
        }
        i++;
    }
    
    for(auto &it: uarr){
        cout<<it<<" ";
    }
    

    
    //! BRUTE FORCE {T.C.,S.c. - very high }
    // set<int> s; //! bcz set contaions only unique,Sorted elements therefore we iterated through both arrays and stored there elements in UN set which only stores unique elle ts therefore same elemensts can't be repeated 
    // for(int i = 0;i<6;i++){
    //     s.insert(a1[i]);
    // }
    // for(int i = 0;i<6;i++){
    //     s.insert(a2[i]);
    // }
    // for(auto &x: s){
    //     cout<<x<<" ";
    // }
}