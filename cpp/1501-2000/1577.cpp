class Solution {
    public:
        int numTriplets(vector<int>& nums1, vector<int>& nums2) {
            return helper(nums1, nums2) + helper(nums2, nums1);
        }
    
    private:
        int helper(vector<int>& arr1, vector<int>& arr2){
            int count  = 0;
            unordered_map<long long, int> productCount;
            int n = arr2.size();
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    long long product = (long long)arr2[i] * arr2[j];
                    productCount[product]++;
                }
            }
    
            for(long long num : arr1){
                long long square = num * num;
                if(productCount.count(square)){
                    count += productCount[square];
                }
            }
            return count;
    
        }
    };