#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n; // In case k is larger than n

    // Reverse entire array
    reverse(nums.begin(), nums.end());

    // Reverse first k elements
    reverse(nums.begin(), nums.begin() + k);

    // Reverse the rest
    reverse(nums.begin() + k, nums.end());
}

// Example usage
int main() {
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    rotate(nums1, 3);
    for (int num : nums1) cout << num << " "; // Output: 5 6 7 1 2 3 4
    cout << endl;

    vector<int> nums2 = {-1, -100, 3, 99};
    rotate(nums2, 2);
    for (int num : nums2) cout << num << " "; // Output: 3 99 -1 -100
    cout << endl;

    return 0;
}
