#include<iostream>
using namespace std;

string toBinary(int n) {
    if(n == 0) return "0";
    string binary = "";
    while(n > 0) {
        binary = char('0' + (n % 2)) + binary;
        n = n / 2;
    }
    return binary;
}

int countSetBits(string binary) {
    int count = 0;
    for(char bit : binary) {
        if(bit == '1') count++;
    }
    return count;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    string binary = toBinary(n);
    int count = countSetBits(binary);

    cout << "Binary: " << binary << endl;
    cout << "Set bits: " << count << endl;
}