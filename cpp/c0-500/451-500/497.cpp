class Solution {
    public:
        vector<vector<int>> rectangles;
        vector<int> prefixPoints;
        int totalPoints;
        mt19937 gen;
        Solution(vector<vector<int>>& rects) {
            rectangles = rects;
            totalPoints = 0;
            prefixPoints.push_back(0);
    
            for(auto& rect : rectangles){
                int a = rect[0], b = rect[1];
                int x = rect[2], y = rect[3];
    
                int points = (x - a + 1) * (y - b + 1);
                totalPoints += points;
                prefixPoints.push_back(totalPoints);
            }
    
            random_device rd;
            gen = mt19937(rd());
        }
        
        vector<int> pick() {
            uniform_int_distribution<> dis(0, totalPoints - 1);
            int pointNum = dis(gen);
    
            int l = 0, r = rectangles.size();
            while(l < r){
                int m = l + (r - l) / 2;
                if(prefixPoints[m] > pointNum){
                    r = m;
                }else{
                    l = m + 1;
                }
            }
    
            int rectIndex = l - 1;
            auto& rect = rectangles[rectIndex];
            int a = rect[0], b = rect[1];
            int x = rect[2], y = rect[3];
        
            int w = x - a + 1;
            int h = y - b + 1;
            int offset = pointNum - prefixPoints[rectIndex];
    
            int dx = offset % w;
            int dy = offset / w;
    
            return {a + dx, b + dy};
        }
    };
    
    /**
     * Your Solution object will be instantiated and called as such:
     * Solution* obj = new Solution(rects);
     * vector<int> param_1 = obj->pick();
     */