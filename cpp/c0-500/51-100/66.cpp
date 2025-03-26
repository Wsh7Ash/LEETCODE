#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();

    // Traverse the array from the last digit
    for (int i = n - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++; // No carry needed
            return digits;
        }
        
        // If digit is 9, it becomes 0 and carry propagates
        digits[i] = 0;
    }

    // If all digits were 9, we need an extra digit at the start
    digits.insert(digits.begin(), 1);
    return digits;
}

int main() {
    vector<int> digits1 = {1, 2, 3};
    vector<int> digits2 = {4, 3, 2, 1};
    vector<int> digits3 = {9, 9, 9};

    vector<int> res1 = plusOne(digits1);
    vector<int> res2 = plusOne(digits2);
    vector<int> res3 = plusOne(digits3);

    // Print results
    for (int num : res1) cout << num;
    cout << endl;
    
    for (int num : res2) cout << num;
    cout << endl;

    for (int num : res3) cout << num;
    cout << endl;

    return 0;
}
