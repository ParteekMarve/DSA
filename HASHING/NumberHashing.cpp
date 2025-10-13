#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter no. of elements: ";
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    //! PRECOMPUTATION

    int hash[n+1] = {0};
    for(int i = 0; i<n;i++){
        hash[arr[i]] += 1;
    }
    int q;
    cout<<"Enter no. of Queries: ";
    cin>>q;
    while(q--){      //! Initial: q = 3   LOOPS EXACTLY runs q times 
                            /*Step 1: Check q (3) → True → Execute loop → q becomes 2
                            Step 2: Check q (2) → True → Execute loop → q becomes 1  
                            Step 3: Check q (1) → True → Execute loop → q becomes 0
                            Step 4: Check q (0) → False → EXIT LOOP*/
        int number;
        // cout<<"enter num: ";
        cin>>number;

        //! FETCH
        cout<<hash[number]<<endl;
    }
    return 0;
}