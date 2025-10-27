#include<iostream>
using namespace std;
int partition(int arr[],int low,int high){
        int pivot  = arr[low];
        int i = low;
        int j = high;

        while(i<j){  // keep repeating untill both don't cross each other
            while(arr[i] <= pivot and i <= high -1){  //it keeps on going until a greater element is found while going towards right                i++;
                i++;                      //! FINDS 1st Element greater than pivot
            }
            while(arr[j] > pivot and j >= low + 1){  //it keeps on going until a smaller element is found while going towards left               i++;
                j--;                      //! FINDS 1st Element smaller than pivot
            }
            if(i<j){
                swap(arr[i],arr[j]); // by swapping we are getting closer to get index of pivot
            }
            //* untill now we have got position of pivot and have arranged elements as smaller on left and bigger on right
            
        }
        swap(arr[low],arr[j]); //! we swap low by j bcz when j just crosses i j is before the bigger and after the smaller elements  
        return j;  //! here  we got the partition index
            
}
void qs(int arr[],int low, int high){
    if(low<=high){
        int part_idx = partition( arr, low, high);
        qs(arr,low,part_idx - 1);
        qs(arr,part_idx + 1,high);
    }
       
}
void quickSort(int arr[],int n){
    qs(arr,0, n-1);
}

int main(){
    int n = 5;
    int arr[n] = {10,5,11,3,1};
    for(int x : arr){
        cout<<x<<" ";
    }
    cout<<endl;
    quickSort(arr, n);
    for(int x : arr){
        cout<<x<<" ";
    }

}
