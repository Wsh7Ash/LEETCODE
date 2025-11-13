class Solution {
    public:
        int lenOfLIS(vector<int>& nums){
            if(nums.empty()) return 0;
            vector<int> tails;
            for(int num : nums){
                int left = 0, right = tails.size();
                while(left < right){
                    int mid = (left + right) / 2;
                    if(tails[mid] < num){
                        left = mid + 1;
                    }else{
                        right = mid;
                    }
                }
                if(left == tails.size()){
                    tails.push_back(num);
                }else{
                    tails[left] = num;
                }
            }
            return tails.size();
        }
    
        int minOperations(vector<int>& target, vector<int>& arr) {
            int n = target.size();
            map<int, int> pos;
            for(int i = 0; i < n; i++){
                pos[target[i]] = i;
            }     
            vector<int> indices;
            for(int num : arr){
                if(pos.count(num)){
                    indices.push_back(pos[num]);
                }
            }
            int listLen = lenOfLIS(indices);
            return n - listLen;
        }
    
        
    };