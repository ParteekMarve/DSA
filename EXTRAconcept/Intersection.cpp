
//2, 2, 1, 4, 5, 6, 2

//2, 1, 2, 3, 4, 6
//result => 2, 2, 1 , 4, 6
#include<iostream>
using namespace std;
int main(){
    int a1[6] = {2, 2, 1, 4, 5, 6};
    int a2[6] = {2, 1, 2, 3, 4, 6};
    for(int i = 0;i<6;i++){
        for(int j = 0;j<6;j++){
            if(a2[j] == a1[i]){
             cout<<a2[j]<<" ";
              break;
                
            }
        }
    }

}