#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<string, int> sequenceCount;
    vector<string> result;
    
    if (s.length() < 10) return result; // No possible 10-letter sequences

    for (int i = 0; i <= s.length() - 10; i++) {
        string sub = s.substr(i, 10);
        sequenceCount[sub]++;
        if (sequenceCount[sub] == 2) { // Add only when seen exactly twice
            result.push_back(sub);
        }
    }
    
    return result;
}

// Example usage
int main() {
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> output = findRepeatedDnaSequences(s);

    for (const string& seq : output) {
        cout << seq << endl;
    }

    return 0;
}
