class Solution {
    public:
        int minSwapsCouples(vector<int>& row) {
           int n = row.size();
           unordered_map<int, int> pos;
           for(int i = 0; i < n; i++){
            pos[row[i]] = i;
           } 
    
           int swaps = 0;
    
           for(int i = 0; i < n; i+=2){
            int cur = row[i];
            int partner = cur ^ 1;
            if(row[i + 1] != partner){
                int ppos = pos[partner];
                swap(row[i+1], row[ppos]);
                pos[row[ppos]] = ppos;
                pos[row[i+1]] = i + 1;
                swaps++;
            }
           }
           return swaps;
        }
    };