#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool linearSearch(vector<int>& a , int tarnum){
    int n = a.size();
    for(int i = 0;i<n;i++){
        if(a[i] == tarnum){
            return true;
        }
    }
    return false;  //! when this false occurs while loop exits/stops 
            
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int > arr(n); 
    for(int i= 0;i<n;i++){
        cin>>arr[i];
    }

    //! {LOGIC} -> ye hai ki ek elment uthao or uske aage vale elements ko dhundo agar milta hai to continue karenge nhi to searcing band  and move to next element
    int maxlen = 1;
    for(int i = 0;i<n;i++){
        int x = arr[i];
        int len = 1;
        while(linearSearch(arr, x+1) == true){   //! **this while loop runs till we are getting x+1 elmnt{means we are getting true} but when it is not found it directly exists
            x++;  //* look for next consecutive elemnt
            len++;   //* keep updating the length till we are getting next consecutive element
        }
        maxlen = max(len, maxlen);
    }
    cout<< maxlen;

    //! BETTER {SORTING}
    
    
}