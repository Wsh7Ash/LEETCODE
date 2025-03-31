class Solution {
    public:
        vector<int> prefixSums;
        int totalSum;
        mt19937 gen;
        uniform_int_distribution<int> dis;
        Solution(vector<int>& w) {
            prefixSums.resize(w.size());
            prefixSums[0] = w[0];
            for(int i = 1; i < w.size(); i++){
                prefixSums[i] = prefixSums[i-1] + w[i];
            }
            totalSum = prefixSums.back();
            random_device rd;
            gen = mt19937(rd());
            dis = uniform_int_distribution<int>(1, totalSum);
        }
        
        int pickIndex() {
            int randomNum = dis(gen);
            int left = 0, right = prefixSums.size() - 1;
            while(left < right){
                int mid = left + (right - left) / 2;
                if(prefixSums[mid] < randomNum){
                    left = mid + 1;
                }else{
                    right = mid;
                }
            }
            return left;
        }
    };
    
    /**
     * Your Solution object will be instantiated and called as such:
     * Solution* obj = new Solution(w);
     * int param_1 = obj->pickIndex();
     */