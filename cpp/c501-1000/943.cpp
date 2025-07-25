class Solution {
    public:
        string shortestSuperstring(vector<string>& words) {
            int n = words.size();
    
            vector<vector<int>> overlap(n, vector<int>(n, 0));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    int max_possible = min(words[i].size(), words[j].size());
                    for (int l = max_possible; l >= 0; l--) {
                        if (words[i].substr(words[i].size() - l) == words[j].substr(0, l)) {
                            overlap[i][j] = l;
                            break;
                        }
                    }
                }
            }
    
            vector<vector<pair<int, int>>> dp(1 << n, vector<pair<int, int>>(n, {-1, -1}));
    
            for (int i = 0; i < n; i++) {
                dp[1 << i][i] = {0, -1};
            }
    
    
            for (int mask = 1; mask < (1 << n); mask++) {
                for (int last = 0; last < n; last++) {
                    if (!(mask & (1 << last))) continue;
                    int prev_mask = mask ^ (1 << last);
                    if (prev_mask == 0) continue;
                    for (int prev_last = 0; prev_last < n; prev_last++) {
                        if (!(prev_mask & (1 << prev_last))) continue;
                        if (dp[prev_mask][prev_last].first == -1) continue;
                        int cur_overlap = dp[prev_mask][prev_last].first + overlap[prev_last][last];
                        if (cur_overlap > dp[mask][last].first) {
                            dp[mask][last] = {cur_overlap, prev_last};
                        }
                    }
                }
            }
    
            int max_overlap = -1;
            int last_word = -1;
            int full_mask = (1 << n) - 1;
            for (int i = 0; i < n; i++) {
                if (dp[full_mask][i].first > max_overlap) {
                    max_overlap = dp[full_mask][i].first;
                    last_word = i;
                }
            }
    
            vector<int> order;
            int cur_mask = full_mask;
            int cur_last = last_word;
            while (cur_last != -1) {
                order.push_back(cur_last);
                int prev_last = dp[cur_mask][cur_last].second;
                if (prev_last == -1) break;
                cur_mask ^= (1 << cur_last);
                cur_last = prev_last;
            }
            reverse(order.begin(), order.end());
    
            string res = words[order[0]];
            for (int i = 1; i < order.size(); i++) {
                int prev = order[i - 1];
                int cur = order[i];
                int overlap_len = overlap[prev][cur];
                res += words[cur].substr(overlap_len);
            }
    
            return res;
        }
    };