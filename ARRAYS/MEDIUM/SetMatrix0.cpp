/*1. Brute Force (commented): Mark rows/columns with -1, then convert to 0
   - Time: O(n*m*(n+m)), Space: O(1)
   - Issue: Doesn't work if matrix contains -1

2. Better Solution (commented): Use auxiliary(extra) arrays to track zero positions
   - Time: O(2*n*m), Space: O(n+m)
   - Track rows and columns containing zeros separately

3. Optimal Solution (active): Use first row/column as markers
   - Time: O(n*m), Space: O(1)
   - Store first row/column state in separate flags
   - Use matrix's first row/column as marker space
   - Process from (1,1) to avoid overwriting markers
   - Handle first row/column separately at the end*/

#include<iostream>
using namespace std;
// void markRow(int arr[][100],int i,int m){   /*First dimension (empty): Can be omitted because the function doesn't need it for address calculation
//                                               Second dimension (100): MUST be specified so C++ knows how many columns to skip when moving between rows*/ 
//     for(int j = 0;j<m;j++){
//         if(arr[i][j] != 0){
//             arr[i][j] = -1;   //! marking whole index of the row in which crnt elmnt = 0 is present
//         }
//     }
// }
// void markColm(int arr[][100], int j, int n){
//     for(int i = 0; i < n; i++){
//         if(arr[i][j] != 0){
//             arr[i][j] = -1;  //! marking whole index of the column in which crnt elmnt = 0 is present
//         }
//     }
// }

int main(){
    int n,m;
    cout<< "Enter n: "<<endl;
    cin>>n;
    cout<< "Enter m: "<<endl;
    cin>>m;
    int arr[100][100]; //! always good bcz fixed size of array must be known at compile time | also can use n and m(but complexities will inc)
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl;

    // for(int  i = 0;i<n;i++){
    //     for(int j = 0;j<m;j++){
    //         if(arr[i][j] == 0){
    //             markRow(arr,i,m);   //* at each time here we have gotten current row and colm so that we can access particular elemnt's row and column
    //             markColm(arr,j,n);
    //         }

    //     }
    // }
    // for(int i = 0; i < n; i++){
    //         for(int j = 0; j < m; j++){
    //             if(arr[i][j] == -1){
    //                 arr[i][j] = 0;
    //             }
    //         }
    // }
    //  for(int i = 0; i < n; i++){
    //         for(int j = 0; j < m; j++){
    //             cout<< arr[i][j] <<" ";
    //             }
    //              cout << endl;
    //  }
       
    //   //! BETTER APPROACH{LOGIC -- Mark those rows and cells in which 0 appeared atleast once}
    //   int row[n] = {0};
    //   int colm[m] = {0};                 //? T.C.- O(2*n*m){best} | S.C - O(n+m)
    //   bool postion_found = false;
    // for(int i = 0;i<n;i++){
    //     for(int j = 0;j<m;j++){
    //         if(arr[i][j] == 0){    //! if the entire Row or Entire Column has atleast of 1 zero then whule row and colm will be zero
    //             row[i] = true;   //* means at this index we need to print 0 at this row {just marked}
    //             colm[j] = true;
    //             postion_found = true;
    //         }
    //     }
    // }
    
    // for(int i = 0;i<n;i++){
    //     for(int j = 0;j<m;j++){
    //         if(row[i] == true || colm[j] == true){
    //             arr[i][j] = 0;
    //         }
    //     }
    // }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout<< arr[i][j] <<" ";
    //     }
    //      cout << endl;
    // }

    //! OPTIMAL SOLUTION{LOGIC- optimize space complexity || Here we used the 1st inner arrays  }
    bool firstRow_0 = false;
    bool firstColm_0 = false;
    for(int j = 0;j<m;j++){
        if(arr[0][j] == 0){   //* checking for the 1st row only
            firstRow_0 = true;
        }
    }
    for(int i = 0;i<n;i++){ 
        if(arr[i][0] == 0){
            firstColm_0 = true;
        }
    }

    for(int i = 1;i<n;i++){
        for(int j = 1;j<m;j++){
            if(arr[i][j] == 0){
                arr[i][0] = 0;  //! here we did not convereted whole current row(i) elmnts as 0 just we just marked that this row to be converted into 0
                arr[0][j] = 0;  //! same here
            }
        }
    }

    for(int i = 1;i<n;i++){
        for(int j = 1;j<m;j++){
            if(arr[i][0] == 0 || arr[0][j] == 0){
                arr[i][j] = 0;
            }
        }
    }
    // now i have to set the 1st row and 1st colm as zero if they consists of zero baki kaam to hogeya hai

    for(int j = 0;j<m;j++){
        if(firstRow_0 == true){
            arr[0][j] = 0;
        }
    }

    for(int i = 0;i<n;i++){
        if(firstColm_0 == true){
            arr[i][0] = 0;
        }
    }

    // and all set just print
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<< arr[i][j] <<" ";
        }
         cout << endl;
    }
}

  
