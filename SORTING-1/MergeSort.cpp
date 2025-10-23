#include <iostream>
using namespace std;
void merge(int arr[], int low, int high)
{
    if (low >= high) //* Base case >> to know when to stop dividing array(hypothetical) into left and right arr
        return;

    int mid = low + (high - low) / 2; //! int overflow safety method**
    merge(arr, low, mid);//* for left array
    merge(arr, mid + 1, high);//* for right array

    // TODO: Merge Sort
    int size_arr = high - low + 1; // *! if we don't know size        
    int temp_arr[size_arr]; //* created a temporary array that contains sorted arr[hypo]
    int ptr_1 = low;//! starting pinter of left arr
    int ptr_2 = mid + 1;//! starting pinter of left arr
    int start_index = 0;//* seted temporary array's index to 0
    while(ptr_1 <= mid and ptr_2 <= high){
        if(arr[ptr_1]<= arr[ptr_2]){   // if left's idx < right's idx means left element is smaller and must be before
            temp_arr[start_index] = arr[ptr_1];  //* temp arr ke currnt idx pe snalleer to bigger element are being placed
            ptr_1++;

        }
        else{  // if right idx element < left idx element
            temp_arr[start_index] =arr[ptr_2];
            ptr_2++;
        }


        start_index++;
    }

    while(ptr_1 <= mid){ //! if the left array finishes first 
        temp_arr[start_index] = arr[ptr_1];
        start_index++;
        ptr_1++;
    } 

    
    while(ptr_2 <= high){  //! if the right array finishes first 
        temp_arr[start_index] = arr[ptr_2]; //! then take all ements of left array(already sorted ) and put to full array
        start_index++; 
        ptr_2++;
    }

    start_index = 0;//! just repositioned the indicies of temp arr to 0
    for(int idx = low;idx<=high;idx++){   //! to add Sorted array(hupothetical) into Original Array 
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
        cout<<x<<" ";
    }
    cout<<endl;

    merge(arr, 0, n - 1);

    for(int x : arr){
        cout<<x<<" ";
    }

}

