class Solution {
    public:
        vector<int> pathInZigZagTree(int label) {
            vector<int> path;
            int level = 0;
            int temp = label;
    
            while(temp){
                level++;
                temp /= 2;
            }
    
            int cur = label;
            while(level > 0){
                path.push_back(cur);
                int lvl_min = 1 << (level - 1);
                int lvl_max = (1 << level) - 1;
                int symm = lvl_min + lvl_max - cur;
                cur = symm / 2;
                level--;
            }
            reverse(path.begin(), path.end());
            return path;
        }
    };