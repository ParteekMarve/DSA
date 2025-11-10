#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}

    // int removeDuplicates(vector<int>& nums) {
    //     set<int> s;    // as set contains only unique and sorted elements
    //     for(int i = 0;i<nums.size();i++){  // due to which no duplicates will be present here
    //         s.insert(nums[i]);
    //     }
    //     int idx = 0;
    //     for(auto it: s){
    //         nums[idx] = it;   // putting unique element vali array into nums(original array)
    //         idx++;
    //     }

    //     // let nums = [1, 1, 2, 2, 3]

    //     //After inserting into set: s = {1, 2, 3}
    //     return idx; //! returns no of unique elmts    //Then nums becomes: [1, 2, 3, 2, 3]  1st 3(no of unique elmts) elemnts ki jagah only set vale aage without changing order of further elemts 
        
    // }
};

int main() {
    Solution obj;  // create object of class

    vector<int> nums = {1, 1, 2, 2, 3};  // input array with duplicates

    int newLength = obj.removeDuplicates(nums);  // call function  

    cout << "Number of unique elements: " << newLength << endl;
    cout << "Array after removing duplicates: ";
    
    // print only first 'newLength' elements (unique ones)
    for(int i = 0; i < newLength; i++){
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
