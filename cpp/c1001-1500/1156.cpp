class Solution {
    public:
        int maxRepOpt1(string text) {
            int n = text.size();
            vector<int> freq(26, 0);
            for(char c : text) freq[c - 'a']++;
    
            vector<pair<char, int>> groups;
            int i = 0;
            while(i < n){
                char c = text[i];
                int count = 0;
                while(i < n && text[i] == c){
                    count++;
                    i++;
                }
                groups.push_back({c, count});
            }
    
            int res = 0;
            int m = groups.size();
            for(int i = 0; i < m; i++){
                res = max(res, groups[i].second);
                if(freq[groups[i].first - 'a'] > groups[i].second){
                    res = max(res, groups[i].second + 1);
                }
            }
    
            for(int i = 0; i < m - 2; i++){
                if(groups[i].first == groups[i+2].first && groups[i+1].second == 1){
                    int total = groups[i].second + groups[i+2].second;
                    if(freq[groups[i].first - 'a'] > total){
                        res = max(res, total + 1);
                    }else{
                        res = max(res, total);
                    }
                }
            }
            return res;
        }
    };