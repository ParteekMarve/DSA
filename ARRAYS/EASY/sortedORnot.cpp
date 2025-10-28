#include<iostream>
#include<vector>
using namespace std;
class Solution{	
	public:
		bool isSorted(vector<int>& nums){
			for(int i=0;i<nums.size()-1;i++){
                    if(nums[i]>nums[i+1]){
                        return false;
                    }
                }
                return true;
            }
};

int main(){
    vector<int> nums;
    Solution arr;
    vector<int> nums1 = {1, 2, 3, 4, 5};

    cout << "Array 1 sorted? " << (arr.isSorted(nums1) ? "Yes" : "No") << endl; //! ternary operator in C++ — it’s a short way to write an if–else | Speacial cout for bool function
}                               //!   (condition) ?    (value_if_true) : (value_if_false);