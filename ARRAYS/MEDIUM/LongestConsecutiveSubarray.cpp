#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
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
    // vector<int > arr(n); 
    int arr[n];
    for(int i= 0;i<n;i++){
        cin>>arr[i];
    }

    //! {LOGIC} -> ye hai ki ek elment uthao or uske aage vale elements ko dhundo agar milta hai to continue karenge nhi to searcing band  and move to next element
    // int maxlen = 1;
    // for(int i = 0;i<n;i++){
    //     int x = arr[i];
    //     int len = 1;
    //     while(linearSearch(arr, x+1) == true){   //! **this while loop runs till we are getting x+1 elmnt{means we are getting true} but when it is not found it directly exists
    //         x++;  //* look for next consecutive elemnt
    //         len++;   //* keep updating the length till we are getting next consecutive element
    //     }
    //     maxlen = max(len, maxlen);
    // }
    // cout<< maxlen;

    //! BETTER {SORTING}
    //!  {LOGIC} -- agar to crnt smallest elmnt crnt elmnt -1 ke = hai to aage continue karte jaenge nhi to last elmnt se new start karenge
    // int current_smallest = INT16_MIN;
    // int len = 0;
    // int maxlen = 1;
    // for(int i = 0;i<n;i++){
    //     if(arr[i] - 1 == current_smallest){
    //         len++;
    //         current_smallest = arr[i];
    //     }
    //     else {
    //         len = 0;
    //         current_smallest = arr[i];
    //     }
    // }
    // maxlen = max(len, maxlen);
    // cout<<maxlen;
    
    //! OPTIMAL {Almost same as brute force just searching for x +1, x+2n etc. for x only if x could be a starting number for a sequence}
    unordered_set<int> temp;
    int len = 0;
    int maxlen = 1;
    for(int i = 0;i<n;i++){
        temp.insert(arr[i]);
    }
    for(auto it: temp){
        if(temp.find(it - 1) == temp.end()){   //! it checks for each elmnt wheather it can be the starting of a consecutive sequesce or not | if yes start sequence from current iterator and search for its next elements
            len = 1;                          //!  //!Checks if (it - 1) exists in the set. If it doesn't exist (returns temp.end()), then it is the start of a new consecutive sequence
            int x = it;                                                                                                //! **end is the NULL or NOT FOUND marker for iterators**
            while(temp.find(x) != temp.end()){    //* while consecutive numbers exists in map, keep counting
                x = x + 1;      // search for the next consecutive elmnt for x 
                len++;
            }
            maxlen = max(len, maxlen);
        }
        
    }
    cout<<maxlen;
}