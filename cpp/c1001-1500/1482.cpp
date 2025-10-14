class Solution {
    public:
        int minDays(vector<int>& bloomDay, int m, int k) {
            long long t = (long long)m * k;
            int n = bloomDay.size();
    
            if(t > n) return -1;
    
            int left = *min_element(bloomDay.begin(), bloomDay.end());
            int right = *max_element(bloomDay.begin(), bloomDay.end());
            int res = -1;
    
            while(left <= right){
                int mid = left + (right - left) / 2;
                if(canMakeBouquets(bloomDay, m, k, mid)){
                    res = mid;
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            return res;
        }
    
    private:
        bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int day){
            int b = 0;
            int c = 0;
            for(int i = 0; i < bloomDay.size(); i++){
                if(bloomDay[i] <= day){
                    c++;
                    if(c == k){
                        b++;
                        c = 0;
                    }
                }else{
                    c = 0;
                }
                if(b >= m) return true;
            }
            return b >= m;
        }
    };