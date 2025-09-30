class Solution {
    public:
        int tilingRectangle(int n, int m) {
            if(n > m) swap(n, m);
            if(n == 1) return m;
            if(n == m) return 1;
    
            this->n  = n;
            this->m  = m;
            minSqrs = INT_MAX;
    
            vector<int> skyline(n, 0);
            backtrack(skyline, 0);
    
            return minSqrs;
        }
    private:
        int n, m, minSqrs;
    
        void backtrack(vector<int>& skyline, int sqrs){
            if(sqrs >= minSqrs) return;
    
            int minHeight = *min_element(skyline.begin(), skyline.end());
    
            if(minHeight == m){
                minSqrs = min(minSqrs, sqrs);
                return;
            }
    
            int pos = 0;
            while(skyline[pos] != minHeight) pos++;
    
            for(int size = 1; size <= min(n - pos, m - minHeight); size++){
                bool canPlace = true;
                for(int i = pos; i < pos + size; i++){
                    if(skyline[i] != minHeight){
                        canPlace = false;
                        break;
                    }
                }
    
                if(!canPlace) break;
    
                for(int i = pos; i < pos + size; i++){
                    skyline[i] += size;
                }
    
                backtrack(skyline, sqrs + 1);
    
                for(int i = pos; i < pos + size; i++){
                    skyline[i] -= size;
                }
            }
        }
      
    };