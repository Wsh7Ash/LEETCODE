
class Solution {
    public:
        int distributeCandies(vector<int>& candyType) {
            unordered_set<int> uT(candyType.begin(), candyType.end());
            int maxEat = candyType.size() / 2;
            return min(static_cast<int>(uT.size()), maxEat);
        }
    };