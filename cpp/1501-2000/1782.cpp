class Solution {
    public:
        vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
            vector<int> degree(n + 1, 0);
            map<pair<int, int>, int> edgeCount;
    
            for(auto& edge : edges){
                int u = edge[0], v = edge[1];
                degree[u]++;
                degree[v]++;
                if(u > v){
                    swap(u, v);
                }
                edgeCount[{u, v}]++;
            } 
    
            vector<int> sorted_degree = degree;
            sorted_degree.erase(sorted_degree.begin());
            sort(sorted_degree.begin(), sorted_degree.end());
            
            vector<int> res;
    
            for(int query : queries){
                int count = 0;
                int left = 0, right = n - 1;
                while(left < right){
                    if(sorted_degree[left] + sorted_degree[right] > query){
                        count += right - left;
                        right--;
                    }else{
                        left++;
                    }
                }
    
                for(auto& p : edgeCount){
                    int u = p.first.first, v = p.first.second;
                    int common = p.second;
                    if(degree[u] + degree[v] > query && degree[u] + degree[v] - common <= query){
                        count--;
                    }
                    else if(degree[u] + degree[v] <= query && degree[u] + degree[v] - common > query){
                        count++;
                    }
                }
                res.push_back(count);
            }
    
            
    
            return res;
        }
    };