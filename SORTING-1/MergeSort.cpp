#include <iostream>
using namespace std;
void merge(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int mid = low + (high - low) / 2; //! int overflow safety method**
    merge(arr, low, mid);
    merge(arr, mid + 1, high);

    int size_arr = high - low + 1;
    int temp_arr[size_arr];
    int ptr_1 = low;
    int ptr_2 = mid + 1;
    int start_index = 0;
    while(ptr_1 <= mid and ptr_2 <= high){
        if(arr[ptr_1]<= arr[ptr_2]){
            temp_arr[start_index] = arr[ptr_1];
            ptr_1++;

        }
        else{
            temp_arr[start_index] =arr[ptr_2];
            ptr_2++;
        }


        start_index++;
    }

    while(ptr_1 <= mid){
        temp_arr[start_index] = arr[ptr_1];
        start_index++;
        ptr_1++;
    } 

    
    while(ptr_2 <= high){
        temp_arr[start_index] = arr[ptr_2];
        start_index++;
        ptr_2++;
    }
    start_index = 0;

    for(int idx = low;idx<=high;idx++){
        arr[idx] = temp_arr[start_index];
        start_index++;
    }

}

int main()
{
    int n = 5;
    // cin>>n;
    int arr[] = {10,5,11,3,1};
    // for(int i = 0;i < n;i++){
    //     cin>>arr[i];
    // }

    for(int x : arr){
        cout<<x<<endl;
    }

    merge(arr, 0, n - 1);

    for(int x : arr){
        cout<<x<<endl;
    }

}

