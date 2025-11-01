#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    int a1[6] = {1,2,3,4,5,6};
    int a2[6] = {3,4,5,6,7,8};
    vector<int> iarr;
    int i = 0;
    int j = 0;
    while(i<6 and j<6){
        if(a1[i]==a2[j]){
            if(iarr.size() == 0 || iarr.back() != a1[i]){   // prevents from duplicate items
                iarr.push_back(a1[i]);
                i++;
                j++;  
            }      
        }
        else if(a1[i]>a2[j]){
            j++;
        }
        else{
            i++;
        }
    }

    for(auto &it: iarr){
        cout<<it<<" ";
    }
    
    
    // unordered_map<int,int> freq;
    // for(int i =0;i<6;i++){
    //     freq[a1[i]]++;
    // }
    // for(int j =0;j<6;j++){
    //     if(freq[a2[j]]>0){
    //         cout<<a2[j]<<" ";
    //         freq[a2[j]]--;   //! If current elmt exists in the map, print it and decrease its count
    //     }
    // }
}