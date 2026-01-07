#include<iostream>
#include<vector>
using namespace std;
vector<int> generaterows(int row){ // For Variety 3: Optimized Solution
    vector<int> rowlist;
    long long ans = 1;
    rowlist.push_back(1); // 1st elmnt is always 1
    for(int colmm = 1;colmm<row;colmm++){
        ans = ans*(row-colmm);
        ans = ans/(colmm);
        rowlist.push_back(ans);
    }
    return rowlist;

}

// int functionnCr(int r,int c){ // For variety 3 brute force
//     int n = r-1;
//     int k = c-1;
//      Comute c(n,k) 
//     long long position = 1;
//     for(int i = 0;i<k;i++){
//         position = position * (n-i); // getting the numerater
//         position = position/ (i+1);  // for numerater/denomi
//     }
//     return position;
// }

int main(){
    //! Variety 1: Retrun the element at (r,c) position
    //int r = 7, c = 3;
    // Main Idea- to compute (R-1)C(N-1) 
    // element to find is C(r-1,c-1)
    //cout<< "Element at (r,c) = " << functionnCr(r,c);
    
    //! Variety 2 : Print the nth row
    // Main Idea- nth Row has n elemnts means n colms to be traveresed in that row
    //? Brute Force
    // int r = 6;
    // for(int colm = 1;colm<=r;colm++){ // transversing each index through that row and find that elmnt using nCr
    //     cout << functionnCr(r,colm);
    // }
    //? Optimal Method{Observation Based}
    // int ans = 1;
    //start from the 1st index as we stored the result for idx = 0 as 1 
    // for(int colm = 1;colm<=r;colm++){
    //     cout<<ans<< " ";
    //     ans = ans*(r-colm);
    //     ans = ans/ colm;
    // }
    //! Variety 3: Print all N or r rows and return each row as a list in a major list or vector conataining each row as a vector
    vector<vector<int>> result;
    int numrow = 6;
    // **BRUTE FORCE**
    // for(int row = 1;row<numrow;row++){
    //     vector<int> templist;
    //     for(int colm = 1;colm<=row;colm++){
    //         templist.push_back(functionnCr(row,colm));
    //     }
    //     result.push_back(templist);
    // }
    //*OPTIMIZED SOLN */
    
     for(int i = 1; i <= numrow; i++){
        result.push_back(generaterows(i));
    }
    
    cout << "Pascal's Triangle:\n";
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}  