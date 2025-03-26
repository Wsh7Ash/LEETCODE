#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1; // Initialize three pointers

    // Traverse the array until mid crosses high
    while (mid <= high) {
        if (nums[mid] == 0) { 
            // If the current element is 0, swap it with the element at 'low'
            swap(nums[low], nums[mid]);
            low++;   // Move 'low' forward as 0s should be at the beginning
            mid++;   // Move 'mid' forward to check the next element
        } 
        else if (nums[mid] == 1) { 
            // If the current element is 1, just move 'mid' forward
            mid++;
        } 
        else { 
            // If the current element is 2, swap it with the element at 'high'
            swap(nums[mid], nums[high]);
            high--;  // Move 'high' backward as 2s should be at the end
            // Do NOT move 'mid' forward here, as the swapped value needs to be checked
        }
    }
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0}; // Input array
    sortColors(nums); // Sort the colors in-place

    // Print the sorted array
    cout << "Sorted Colors: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl; // Expected Output: 0 0 1 1 2 2

    return 0;
}
