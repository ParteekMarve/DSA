#include<iostream>
#include<algorithm>
using namespace std;

int converttoDecimal(string num){

    int n = 0;
    int p2 = 1;
    int len = num.size();
    for(int i = len-1;i>=0;i--){

        if(num[i] % 2 == 1){
            n = n + p2;
        }
        p2*=2;
    }
    cout<< n;
}
int main(){
    string  num;
    cout<<"Enter string: ";
    cin>>num;
    converttoDecimal(num);
}