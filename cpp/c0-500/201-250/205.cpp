#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> s_to_t;
        unordered_map<char, char> t_to_s;

        for (int i = 0; i < s.length(); ++i) {
            char c1 = s[i], c2 = t[i];

            if (s_to_t.count(c1) && s_to_t[c1] != c2) return false;
            if (t_to_s.count(c2) && t_to_s[c2] != c1) return false;

            s_to_t[c1] = c2;
            t_to_s[c2] = c1;
        }
        
        return true;
    }
};

// Example usage
int main() {
    Solution solution;
    cout << solution.isIsomorphic("egg", "add") << endl;  // Output: true
    cout << solution.isIsomorphic("foo", "bar") << endl;  // Output: false
    cout << solution.isIsomorphic("paper", "title") << endl; // Output: true
    return 0;
}
