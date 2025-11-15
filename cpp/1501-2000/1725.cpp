class Solution {
    public:
        int countGoodRectangles(vector<vector<int>>& rectangles) {
            int maxLen = 0;
            for(const auto& rect : rectangles){
                int squareSide = min(rect[0], rect[1]);
                maxLen = max(maxLen, squareSide);
            }
            int count = 0;
            for(const auto& rect : rectangles){
                int squareSide = min(rect[0], rect[1]);
                if(squareSide == maxLen){
                    count++;
                }
            }
            return count;
        }
    };