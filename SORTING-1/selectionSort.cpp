#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
  
    for(int i = 0;i<=n-2;i++){ //! bcz array constain n-1 elements but don't have to check n-1th element
        int min = i;
        for(int j = i;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }

        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
     for(int i = 0;i<n;i++){
            cout<<arr[i]<<" ";
        }
    
    
}
// #include <iostream>
// using namespace std;

// int main() {
//     int arr[100], n;
//     cin >> n;

//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     for (int i = 0; i < n - 1; i++) {
//         int min = i;
//         for (int j = i + 1; j < n; j++) {
//             if (arr[j] < arr[min]) {
//                 min = j;
//             }
//         }

//         // Swap
//         int temp = arr[min];
//         arr[min] = arr[i];
//         arr[i] = temp;
//     }

//     // Print sorted array
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }
