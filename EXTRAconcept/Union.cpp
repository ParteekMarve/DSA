
//2, 2, 1, 4, 5, 6

//2, 1, 2, 3, 4, 6
//result => 2,1,4,5,6,3
#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    int a1[6] = {2, 2, 1, 4, 5, 6};
    int a2[6] = {2, 1, 2, 3, 4, 6};
    
    unordered_set<int> s; //! bcz unorderded set contaions only unique elements therefore we iterated through both arrays and stored there elements in UN set which only stores unique elle ts therefore same elemensts can't be repeated 
    for(int i = 0;i<6;i++){
        s.insert(a1[i]);
    }
    for(int i = 0;i<6;i++){
        s.insert(a2[i]);
    }
    for(auto &x: s){
        cout<<x<<" ";
    }
}