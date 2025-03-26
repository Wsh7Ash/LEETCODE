#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Custom comparison function for sorting
bool compare(string a, string b) {
    return a + b > b + a; // We want the largest concatenated value
}

string largestNumber(vector<int>& nums) {
    // Convert the integers to strings
    vector<string> strNums;
    for (int num : nums) {
        strNums.push_back(to_string(num));
    }

    // Sort the strings using the custom comparison function
    sort(strNums.begin(), strNums.end(), compare);

    // If the largest number is '0', return just "0"
    if (strNums[0] == "0") {
        return "0";
    }

    // Concatenate all the numbers to form the largest number
    string result = "";
    for (string num : strNums) {
        result += num;
    }

    return result;
}

int main() {
    vector<int> nums1 = {10, 2};
    vector<int> nums2 = {3, 30, 34, 5, 9};

    cout << "Largest Number (Example 1): " << largestNumber(nums1) << endl;
    cout << "Largest Number (Example 2): " << largestNumber(nums2) << endl;

    return 0;
}
