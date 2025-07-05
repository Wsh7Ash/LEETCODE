class Solution {
    public:
        int numFriendRequests(vector<int>& ages) {
            vector<int> count(121, 0);
            for(int age : ages){
                count[age]++;
            }
            int res = 0;
            for(int x = 1; x <= 120; x++){
                if(count[x] == 0)continue;
                for(int y = 1; y <= 120; y++){
                    if(count[y] == 0)continue;
                    if(y <= 0.5 * x + 7)continue;
                    if(y > x) continue;
                    if(y > 100 && x < 100)continue;
                    res += count[x] * count[y];
                    if(x == y){
                        res -= count[x];
                    }
                }
            }
            return res;
        }
    };