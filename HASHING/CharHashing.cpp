#include<iostream>
using namespace std;
int main(){
    string s;
    cout<<"Enter text: ";
    cin>>s;

    //! PRECOMPUTATION
    int hash[26] = {0}; // for alphabets only
                        // hash[256] for any character
    for(int i = 0; i<s.size();i++){
        hash[s[i]- 'a'] += 1; // for small leters only
                                // arr[i]-'A' for capital letters only
                                // arr[i] for any characters
    }
    int q;
    cout<<"Enter no. of Queries: ";
    cin>>q;
    while(q--){     
        char c;
        cin>>c;

        //! FETCH
        cout<<hash[c - 'a']<<endl;
    }
    return 0;
}