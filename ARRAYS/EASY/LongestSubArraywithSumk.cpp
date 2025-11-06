#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    int n = 5;
    int arr[n] = {2,3,5,1,9};
    long long k;
    cout<<"Enter k: ";
    cin>>k;
    //! BRUTE FORCE {T.C. = O(n*n), S.C. = O(1)}
    // int maxlen = 0;
    // for(int i = 0;i<n;i++){ // starting index of the subarray.
    //     int sum = 0;
    //     for(int j = i;j<n;j++){  // ending index of the subarray.
    //         sum+= arr[j];
    //         if(sum == k)
    //             int len = j-i+1;
    //             if(len>maxlen){
    //                 maxlen = len;
    //             }
    //             if(sum>k){
    //                 break;
    //             }
    //         }
    //     }
    // } 
    // cout<<maxlen;
    //! BETTER {HASHMAP}   T.C. = O(n), S.C. = O(n)
    // unordered_map<long long,int> preSumMap;
    // long long prefixSum = 0;
    // int maxlen = 0;
    // for(int i = 0;i<n;i++){
    //     //* calculate the prefix sum till index i:
    //     prefixSum += arr[i];  //x = sum till index i
    //     if(prefixSum == k){      
    //         maxlen = max(maxlen,i+1);
    //     }
    //     //*  calculate the sum of remaining part i.e. x-k: 
    //     long long remSum = prefixSum - k;   
    //     if(preSumMap.find(remSum) != preSumMap.end()){    //* “If rem is found in the map.”
    //         int len = i - preSumMap[remSum];    //* length of x-k subaray
    //         maxlen = max(maxlen,len);
    //     }
    //     if(preSumMap.find(prefixSum) == preSumMap.end()){  // We haven’t seen this prefix sum before, so let’s store it now || if sum element is not found in map
    //         preSumMap[prefixSum] = i;   // update the index of map as current i
    //     } 
    //     /*We want to remember the first time we saw each prefix sum.
    //     Because the earlier it appears,
    //     ➡️ the longer the subarray we can form later.*/
    // }
    // cout<<maxlen;

    //! OPTIMSL APPROACH - 2 Pointer {  }
    int left = 0;
    int right = 0;
    long long sum = arr[0]; 
    int maxlen = 1;
    while(right < n){
        while(left<= right && sum > k){
            sum -= arr[left];
            left++;
        }
        if(sum == k){
            maxlen = max(maxlen,right - left + 1);
        }

        right++;
        if(right < n){
            sum += arr[right];
        }
    }
    cout<<maxlen;
}
