class Solution {
    public:
        int minimumBoxes(int n) {
            long long k = 0;
            while(k * (k + 1) * (k + 2) / 6 <= n) k++;
            k--;
            long long placed = k * (k + 1) * (k + 2) / 6;
            long long on_floor = k * (k + 1) / 2;
            long long rem = n - placed;
            if(rem == 0){
                return (int)on_floor;
            }
            long long i = 0;
            while(i * (i + 1) / 2 < rem){
                i++;
            }
            return (int)(on_floor + i);
        }
    };