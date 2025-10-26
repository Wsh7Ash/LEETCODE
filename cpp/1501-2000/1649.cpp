class BIT{
    public:
        vector<int> tree;
        int n;
        BIT(int size) : n(size + 1), tree(size + 2, 0) {}
        void update(int i, int delta){
            i++;
            while(i <= n){
                tree[i] += delta;
                i += i & -i;
            }
        }
    
        int query(int i){
            i++;
            int sum = 0;
            while(i > 0){
                sum += tree[i];
                i -= i & - i;
            }
            return sum;
        }
    };
    
    class Solution {
    public:
        int createSortedArray(vector<int>& instructions) {
            int MOD = 1e9+7;
            int max_val = *max_element(instructions.begin(), instructions.end());
            BIT bit(max_val);
            long long cost = 0;
            int n = instructions.size();
            for(int i = 0; i < n; i++){
                int x = instructions[i];
                int less = bit.query(x - 1);
                int greater = i - bit.query(x);
                cost += min(less, greater);
                cost %= MOD;
                bit.update(x, 1);
            }
            return cost;
        }
    };