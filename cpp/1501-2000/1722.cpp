class UnionFind{
    public:
        vector<int> parent, rank;
        UnionFind(int n){
            parent.resize(n);
            rank.resize(n, 0);
            for(int i = 0; i < n; i++){
                parent[i] = i;
            }
        }
        int find(int x){
            if(parent[x] != x){
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        void unite(int x, int y){
            int rootX = find(x);
            int rootY = find(y);
            if(rootX != rootY){
                if(rank[rootX] < rank[rootY]){
                    swap(rootX, rootY);
                }
                parent[rootY] = rootX;
                if(rank[rootX] == rank[rootY]){
                    rank[rootX]++;
                }
            }
        }
    };
    
    class Solution {
    public:
        int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
            int n = source.size();
            UnionFind uf(n);
            for(const auto& swap : allowedSwaps){
                uf.unite(swap[0], swap[1]);
            }
    
            map<int, vector<int>> groups;
            for(int i = 0; i < n; i++){
                int root = uf.find(i);
                groups[root].push_back(i);
            }
            int hammingDist = 0;
            for(const auto& pair : groups){
                map<int, int> sourceCount, targetCount;
                const vector<int>& indices = pair.second;
                for(int idx : indices){
                    sourceCount[source[idx]]++;
                    targetCount[target[idx]]++;
                }
                for(const auto& elemPair : sourceCount){
                    int e = elemPair.first;
                    int sourceFreq = elemPair.second;
                    int targetFreq = targetCount[e];
                    if(sourceFreq > targetFreq){
                        hammingDist += sourceFreq - targetFreq;
                    }
                }
            }
            return hammingDist;
        }
    };