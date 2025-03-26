#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        
        int minNum = INT_MAX, maxNum = INT_MIN;
        for (int num : nums) {
            minNum = min(minNum, num);
            maxNum = max(maxNum, num);
        }

        int n = nums.size();
        int bucketSize = max(1, (maxNum - minNum) / (n - 1));
        int bucketCount = (maxNum - minNum) / bucketSize + 1;

        vector<int> minBucket(bucketCount, INT_MAX);
        vector<int> maxBucket(bucketCount, INT_MIN);
        vector<bool> used(bucketCount, false);

        for (int num : nums) {
            int bucketIndex = (num - minNum) / bucketSize;
            minBucket[bucketIndex] = min(minBucket[bucketIndex], num);
            maxBucket[bucketIndex] = max(maxBucket[bucketIndex], num);
            used[bucketIndex] = true;
        }

        int maxGap = 0, prevMax = minNum;
        for (int i = 0; i < bucketCount; i++) {
            if (!used[i]) continue;
            maxGap = max(maxGap, minBucket[i] - prevMax);
            prevMax = maxBucket[i];
        }

        return maxGap;
    }
};
