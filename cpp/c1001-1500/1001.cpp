class Solution {
    public:
        vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
            unordered_map<int, int> row_counts, col_counts, diag1_counts, diag2_counts;
            unordered_set<long long> lamp_set;
    
            for(const auto& lamp : lamps){
                int r = lamp[0];
                int c = lamp[1];
                long long key = (long long)r * n + c;
                if(lamp_set.find(key) == lamp_set.end()){
                    lamp_set.insert(key);
                    row_counts[r]++;
                    col_counts[c]++;
                    diag1_counts[r-c]++;
                    diag2_counts[r+c]++;
                }
            }
    
            vector<int> res;
            for(const auto& query : queries){
                int r = query[0];
                int c = query[1];
    
                bool illuminated = (row_counts[r] > 0) || (col_counts[c] > 0) || (diag1_counts[r - c] > 0) ||
                                    (diag2_counts[r+c] > 0);
                
                res.push_back(illuminated ? 1 : 0);
    
                for(int dr = -1; dr <= 1; dr++){
                    for(int dc = -1; dc <= 1; dc++){
                        int nr = r + dr;
                        int nc = c + dc;
                        if(nr >= 0 && nr < n && nc >= 0 && nc < n){
                            long long key = (long long)nr * n + nc;
                            if(lamp_set.find(key) != lamp_set.end()){
                                lamp_set.erase(key);
                                row_counts[nr]--;
                                col_counts[nc]--;
                                diag1_counts[nr-nc]--;
                                diag2_counts[nr+nc]--;
                            }
                        }
                    }
                }
            }
            return res;
        }
    };