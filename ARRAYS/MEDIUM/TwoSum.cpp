#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
// bool found(int arr[],int n,int tarnum){
//     bool pairfound = false;
//     for (int i =0;i<n-1;i++){
//         for(int j = i+1;j<n;j++){
//             if(arr[i] + arr[j] == tarnum){
//                 cout << "Pair found: " << arr[i] << " + " << arr[j] << " = " << tarnum << endl;
//                 pairfound  = true;
//                 break;
//             }
//         }
//         if(!pairfound){
//             cout<< "no pair found";
//         }
//     }
//     return pairfound;
// }

//bool found_2nd(int arr[], int n, int tarnum) {
//     unordered_map<int, int> mpp;
//     for (int i = 0; i < n; i++) {
//         int temp = tarnum - arr[i];  //!its like a = b + c where b is known and a - c gives b
//         if (mpp.count(temp)) {   //!   mpp.count(temp) returns the number of times temp appears as a key in the map
                                        /*For unordered_map, it returns either:
                                            1 if the key exists
                                            0 if the key doesn't exist */
               //! Alternates ways to check presence of temp {key}
              /*mpp.count(temp) != 0
                mpp.find(temp) != mpp.end()
                mpp.contains(temp) (C++20 and later)*/
//             cout << temp << " " << arr[i] << endl;
//             return true;
//         }
//         mpp[arr[i]] = i;  // if that element{} is not 
//     }
//     return false;
// }
    

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int tarnum;
    cout<<"Enter num: ";
    cin>>tarnum;
    int arr[n];
    for(int i= 0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    // found(arr,n,tarnum);
    // found_2nd(arr,n,tarnum);  // ! Brute Force - nested for loops 
    // found_3rd(arr,n,tarnum); //! Better - Hashing
    //! Optimal - 2 Pointer approach
    int left  = 0;
    int right = n-1;
    while(left< right){
        int sum = arr[left] + arr[right];
        if(sum == tarnum){
            cout<< arr[left] << arr[right];
            return 0;  //! if we use [break] here then we have to add another flag like bool found = true || by using return 0 it directly exits and goes to the main function
                       /*Use break → if you want to continue after the loop.
                         Use return → if you want to exit the function/program immediately. */
        }
        else if(sum < tarnum) left++;
        else right--;
    }
    cout<< "Not found!";   
}