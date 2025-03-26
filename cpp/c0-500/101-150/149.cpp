#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n; // If there are 2 or fewer points, all lie on the same line

        int maxPointsOnLine = 0;

        for (int i = 0; i < n; ++i) {
            unordered_map<string, int> slopeCount;
            int duplicate = 1; // Count the current point itself

            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    duplicate++; // Same point
                    continue;
                }

                int gcd = computeGCD(dx, dy);
                string slope = to_string(dy / gcd) + "/" + to_string(dx / gcd);

                slopeCount[slope]++;
            }

            int currentMax = duplicate; // Start with the count of duplicate points
            for (const auto& count : slopeCount) {
                currentMax = max(currentMax, count.second + duplicate);
            }

            maxPointsOnLine = max(maxPointsOnLine, currentMax);
        }

        return maxPointsOnLine;
    }

private:
    int computeGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};