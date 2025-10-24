#include<iostream>
#include<unordered_map>
using namespace std;
int main(){

    unordered_map<int,int> freq;

    int a1[6] = {2, 5, 6, 2, 8, 10};
    int a2[6] = {1, 2, 8, 2, 9, 10};
    
    for(int  i=0;i<6;i++){
        freq[a1[i]]++;
    }

    for(int i= 0;i<6;i++){
        if(freq[a2[i]]>0){  //! checks the presence of current elmt in map through its freq => if freq >0 means elnt exists and need to print
            cout<<a2[i]<<" ";
            freq[a2[i]]--;   //! If current elmt exists in the map, print it and decrease its count
        }
    }
}