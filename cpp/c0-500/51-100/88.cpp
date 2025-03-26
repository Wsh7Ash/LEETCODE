#include <iostream>
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int i = m - 1;  // Pointer to the last element of nums1 (initial part)
        int j = n - 1;  // Pointer to the last element of nums2
        int k = m + n - 1;  // Pointer to the last position of nums1

        // Merge the arrays from the back to the front
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // If there are remaining elements in nums2, copy them to nums1
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }

        // No need to worry about remaining elements in nums1 because they're already in the right place
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

    sol.merge(nums1, m, nums2, n);

    // Output the merged array
    for (int num : nums1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
