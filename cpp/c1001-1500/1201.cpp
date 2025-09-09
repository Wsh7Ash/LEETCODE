class Solution {
    private:
        long long gcd(long long a, long long b){
            if(b == 0) return a;
            return gcd(b, a % b);
        }
        long long lcm(long long a, long long b){
            return a * b / gcd(a, b);
        }
    
        long long countUgly(long long num, long long a, long long b, long long c, long long ab, long long ac, long long bc, long long abc){
            return num / a + num / b + num / c
            - num / ab - num / ac - num / bc 
            + num / abc;
        }
    public:
        int nthUglyNumber(int n, int a, int b, int c) {
            long long low = 1, high = 2e9;
            long long ab = lcm((long long)a, (long long)b);
            long long ac = lcm((long long)a, (long long)c);
            long long bc = lcm((long long)b, (long long)c);
            long long abc = lcm(ab, (long long )c);
    
            while(low < high){
                long long mid = low + (high - low) / 2;
                long long count = countUgly(mid, a, b, c, ab, ac, bc, abc);
    
                if(count < n) low = mid + 1;
                else high = mid;
            }
            return low;
        }
    };