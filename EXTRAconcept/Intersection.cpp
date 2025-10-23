
//2, 2, 1, 4, 5, 6, 2

//2, 1, 2, 3, 4, 6
//result => 2, 2, 1 , 4, 6
#include<iostream>
#include<set>
using namespace std;
int main(){

    set<int> s;

    int a1[6] = {2, 2, 1, 4, 5, 6};
    int a2[6] = {2, 2, 2, 3, 4, 6};
    for(int i = 0;i<6;i++){
        if(a1[i]!=a1[i+1])
        s.insert(a1[i]);
    }
    for(int i = 0;i<6;i++){
        s.insert(a2[i]);
    }
    for(auto &x: s){
        cout<<x<<" ";
        
    }
    

}