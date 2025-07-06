class Solution {
    public:
        int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
            vector<pair<int, int>> ones1, ones2;
            int n = img1.size();
    
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(img1[i][j] == 1){
                        ones1.emplace_back(i, j);
                    }
                    if(img2[i][j] == 1){
                        ones2.emplace_back(i, j);
                    }
                }
            }
    
            unordered_map<string, int> translation_counts;
            int max_overlap = 0;
            for(const auto& [x1, y1] : ones1){
                for(const auto& [x2, y2] : ones2){
                    int dx = x2 - x1;
                    int dy = y2 - y1;
                    string key = to_string(dx) + "," + to_string(dy);
                    translation_counts[key]++;
                    max_overlap = max(max_overlap, translation_counts[key]);
                }
            }
            return max_overlap;
        }
    };