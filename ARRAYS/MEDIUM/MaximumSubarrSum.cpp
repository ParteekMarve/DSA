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

    // int maxi = INT16_MIN;
    // for (int i = 0;i<n;i++){
    //     for(int j = i;j<n;j++){
    //         int sum = 0;
    //         for(int k = i ;k<j;k++){
    //             sum+= arr[k];  //* Here k will be consisting 
    //         }
    //         maxi = max(sum,maxi);
    //     } 
    // }
    // cout<<maxi;
   
    //! 2. BETTER
    // int maxi = INT16_MIN;
    // for(int i = 0;i<n;i++){
    //     int sum = 0;
    //     for(int j = i;j<n;j++){
             // current subarray = arr[i.....j]
             //add the current element arr[j]
             // to the sum 
    //         sum+= arr[j];
    //         maxi = max(sum,maxi);
    //     }
    // }
    // cout<<maxi;
    //! 3. OPTIMAL {Kadane's Algorithm} 
    /*Intuition of the algorithm is "not to consider the subarray as a part of the answer
      if its sum is less than 0." A subarray with a sum less than 0 will always reduce our answer and
      so this type of subarray cannot be a part of the subarray with maximum sum.*/  

      //? HERE WE ARE ALSO PRINTING SUBARRAY WITH MAX SUM
    int maxi = INT16_MIN;
    int sum = 0;
    int ans_start_idx = 0;
    int ans_end_idx = 0;
    int current_start_idx = 0;
    
    for(int i = 0;i<n;i++){
        if(sum == 0) {
            current_start_idx = i;
        }

        sum+= arr[i];

        if(sum > maxi){
            maxi =  sum;
            ans_start_idx = current_start_idx;  //* vo index jisse +ve sum vali aubarray start hui
            ans_end_idx = i;   //* vo index(its element) jisko add karne se sum becomes > maxi
        }
         
        if(sum <0){   //! bcz if we will add -ve integer it will only reduce our sum
        sum = 0;
        current_start_idx = i+1;   //* The next potential subarray starts *after* this element
        }
        }

// Print after loop
        if (maxi < 0 ){ //* if we won't find any subarray with sum >0 then just say maxi = 0
            maxi = 0;
            cout<< maxi<<endl;
            cout<<" No Subarray found!";
        }
        else {          //* maxi > 0
            for(int i = ans_start_idx;i<= ans_end_idx;i++){
            cout<<arr[i]<< " ";
            }
        }
        cout << endl;
        cout << maxi << endl;
}
    
    
    
   