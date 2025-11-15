#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int arr[n];
    for(int i= 0;i<n;i++){
        cin>>arr[i];
    }
    //! 1. BRUTE FORCE 
    // for(int i = 0;i<n;i++){
    //     int count = 0;
    //     for(int j = 0;j<n;j++){
    //         if(arr[j] == arr[i]){
    //             count++;
    //         }
             
    //     }
    //    if(count > n/2) cout<< arr[i];
    //     return 0;  //! **Always remember this** when to not futher do anything with loop and want to exit from loop 
    // }
    // cout<< -1;   // No majority elmt found
    
    //! 2. BETTER {HASHING}

//     unordered_map<int,int> freq;
//     for(int i = 0;i<n;i++){
//         freq[arr[i]]++;
//     }
//     for(auto it: freq){
//         if(it.second > n/2){    //! 0checks frequency
//             cout<< it.first;   // Gives the key{element}
//             return 0;
//         }
//     }
//     cout<<-1;
// }

    //! 2. OPTIMAL { Moore’s Voting Algorithm:}
    int count = 0; // no significance at all just to keep track on  curret answer's(assumed) count
    int elmnt;
    for(int i =0;i<n;i++){
        if(count == 0){   // becomes true immediately on the first iteration.
            count = 1;  // starts checking for new section 
            elmnt = arr[i];   // elmnt gets its first valid value (elmnt = arr[i];) before any comparison ever happens.
        }
        else if(arr[i] == elmnt){
            count++;     //! **Analogy:** "My candidate appeared again! +1 point"
        }  
        else{
            count--;
        }
    }
    //! After this loop ends we have almost got the Majority elemnet
    int cnt1 = 0;
    for(int i = 0;i<n;i++){
        if(arr[i] == elmnt) cnt1++;
    }
    if(cnt1 > n/2) cout << elmnt;
    else cout<<-1;
}    
