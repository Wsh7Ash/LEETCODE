class Solution {
    public:
        int maxProfit(vector<int>& inventory, int orders) {
            const int MOD = 1e9+7;
            sort(inventory.begin(), inventory.end(), greater<int>());
            inventory.push_back(0);
            long long res = 0;
            int k = 1;
            for(int i = 0; i < inventory.size() - 1; i++){
                if(inventory[i] > inventory[i+1]){
                    if((long long)k * (inventory[i] - inventory[i+1]) <= orders){
                        long long total = (long long)(inventory[i] + inventory[i+1] + 1) * (inventory[i] - inventory[i+1])/2*k;
                        res = (res + total) % MOD;
                        orders -= k * (inventory[i] - inventory[i+1]);
                    }else{
                        int count = orders / k;
                        int rem = orders % k;
                        long long total = (long long)(inventory[i] + inventory[i] - count + 1) * count / 2 * k;
                        total += (long long)rem * (inventory[i] - count);
                        res = (res + total) % MOD;
                        break;
                    }
                }
                k++;
            }
            return res;
        }
    };