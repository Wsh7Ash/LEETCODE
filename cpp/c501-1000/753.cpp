class Solution {
    public:
        string crackSafe(int n, int k) {
            if(n == 1){
                string res;
                for(int i = 0; i < k; i++){
                    res += to_string(i);
                }
                return res;
            }
    
            unordered_set<string> visited;
            string start(n - 1, '0');
            string res;
    
            dfs(start, k, visited, res);
            res += start;
            reverse(res.begin(), res.end());
    
            return res;
        }
    
        void dfs(const string& node, int k, unordered_set<string>& visited, string& res){
            for(int i = 0; i < k; i++){
                string next_node =node + to_string(i);
                if(visited.find(next_node) == visited.end()){
                    visited.insert(next_node);
                    dfs(next_node.substr(1), k, visited, res);
                    res += to_string(i);
                }
            }
        }
    };