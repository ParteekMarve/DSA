#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:

    // 🔹 Approach 1: Last Seen Array
    bool isIsomorphic_Array(const string& s, const string& t) {
        if (s.length() != t.length()) return false;

        int last_seen_s[256] = {0};
        int last_seen_t[256] = {0};

        for (int i = 0; i < s.length(); i++) {
            if (last_seen_s[s[i]] != last_seen_t[t[i]]) {
                return false;
            }

            last_seen_s[s[i]] = i + 1;
            last_seen_t[t[i]] = i + 1;
        }

        return true;
    }

    // 🔹 Approach 2: Two Hash Maps
    bool isIsomorphic_Map(const string& s, const string& t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> map_s_to_t;
        unordered_map<char, char> map_t_to_s;

        for (int i = 0; i < s.length(); i++) {

            if (map_s_to_t.count(s[i])) {
                if (map_s_to_t[s[i]] != t[i])
                    return false;
            }
            else {
                if (map_t_to_s.count(t[i]))
                    return false;

                map_s_to_t[s[i]] = t[i];
                map_t_to_s[t[i]] = s[i];
            }
        }

        return true;
    }
};

int main() {
    Solution obj;

    string test_s[] = {"egg", "foo", "paper", "ab", "badc"};
    string test_t[] = {"add", "bar", "title", "aa", "baba"};

    int n = 5;

    for (int i = 0; i < n; i++) {
        cout << "Test Case " << i + 1 << ":\n";
        cout << "s = " << test_s[i] << ", t = " << test_t[i] << "\n";

        cout << "Array Method: ";
        if (obj.isIsomorphic_Array(test_s[i], test_t[i]))
            cout << "Isomorphic\n";
        else
            cout << "Not Isomorphic\n";

        cout << "Map Method: ";
        if (obj.isIsomorphic_Map(test_s[i], test_t[i]))
            cout << "Isomorphic\n";
        else
            cout << "Not Isomorphic\n";

    }

    return 0;
}