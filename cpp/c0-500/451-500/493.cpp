class Solution {
    public:
        long long mergeAndCount(vector<long long>& nums, int l, int mid, int r){
            long long count = 0;
            int j = mid + 1;
    
            for(int i = l; i <= mid; i++){
                while(j <= r&& nums[i] > 2 * nums[j]){
                    j++;
                }
                count += (j - (mid + 1));
            }
    
            vector<long long> temp;
            int i = l;
            j = mid + 1;
    
            while(i <= mid && j <= r){
                if(nums[i] <= nums[j]){
                    temp.push_back(nums[i++]);
                }else{
                    temp.push_back(nums[j++]);
                }
            }
    
            while(i <= mid) temp.push_back(nums[i++]);
            while(j <= r) temp.push_back(nums[j++]);
    
            for(int k = 0; k < temp.size(); k++){
                nums[l + k] = temp[k];
            }
            return count;
        }
    
        long long mergeSort(vector<long long>& nums, int l, int r){
            if (l >= r) return 0;
    
            int mid = l + (r - l) / 2;
            long long count = 0;
    
            count += mergeSort(nums, l, mid); 
            count += mergeSort(nums, mid + 1, r); 
            count += mergeAndCount(nums, l, mid, r); 
    
            return count;
        }
        int reversePairs(vector<int>& nums) {
            vector<long long> numsLong(nums.begin(), nums.end());
            return static_cast<int>(mergeSort(numsLong, 0, numsLong.size() - 1));
        }
    };