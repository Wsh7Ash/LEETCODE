class Solution {
    public:
        int r,c,t;
        unordered_map<int, int> swapped;
        int rem;
        Solution(int m, int n) {
            r=m;
            c=n;
            t=m*n;
            rem = t;
            swapped.clear();
        }
        
        vector<int> flip() {
            int r = rand() % rem;
            rem--;
            int x = swapped.find(r) != swapped.end() ? swapped[r] : r;
            swapped[r] = swapped.find(rem) != swapped.end() ? swapped[rem] : rem;
            int i = x / c;        
            int j = x % c;
            return {i, j};        
        }
        
        void reset() {
            swapped.clear();
            rem = t;
        }
    };
    
    /**
     * Your Solution object will be instantiated and called as such:
     * Solution* obj = new Solution(m, n);
     * vector<int> param_1 = obj->flip();
     * obj->reset();
     */