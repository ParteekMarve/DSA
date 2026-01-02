#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    
    vector<int> arr(n);  // 
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    // Store original array
    vector<int> original = arr;
    
    //? BRUTE FORCE - Generate all permutations
    vector<vector<int>> all;
    sort(arr.begin(), arr.end());
    
    do {
        all.push_back(arr);  // ✅ Push entire vector
    } while(next_permutation(arr.begin(), arr.end()));
    
    //? Now search for next permutation
    for(int i = 0; i < all.size(); i++){
        if(all[i] == original){  //  Comparing vectors
            if(i == all.size() - 1){  // Checking Last permutation
                // Print first permutation 
                for(int num : all[0]) cout << num << " ";
            } else {
                // Print next permutation
                for(int num : all[i+1]) cout << num << " ";
            }
            break;  // ✅ Exit after finding
        }
    }
    
    return 0;

    // int brk_idx = -1;
    // //! 1st we need to find the breaking at which we got dip
    // for(int i = n-2;i >=0;i--){
    //     if(arr[i] < arr[i+1]){
    //         brk_idx = i;
    //         break;
    //     }
    // }

    //  //! now for the edge vase if we doesn't find any brk_idx {edge case}
    //  //* that means the array is already at its last permutation therefore we will return its 1st permutation which will be reverse of current array
    //  if(brk_idx == -1){
    //     reverse(arr, arr + n);
    //  }
    //  //* now we have got the breaking index and the longest prfix part of next permutation
    // //! Now we have to find the element just  greater than the element at brk_idx bcz then only we will gwt closer to the just next permutation
    //  for(int i = n-1;i>brk_idx;i--){
    //     if(arr[i] > arr[brk_idx]){
    //         swap(arr[i],arr[brk_idx]);
    //         break;   // bcz we know the rest of array after brk_idx is sorted form right to idxleft therefoore right most elmnt must bw smallest but larger than arr[brk_]
    //     }
    //  }
    //  //* now we have got the correct starting elements of next array 
    //  //* NOw the reamaing array will like that they have no dip if starting from last idx this means we just have to reverse that portion
    
    // reverse(arr + brk_idx, arr+ n);

}    