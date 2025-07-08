class Solution {
    public:
        vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
            int n = nums1.size();
            vector<pair<int, int>> nums2WithIndex;
            for(int i = 0; i < n; i++){
                nums2WithIndex.emplace_back(nums2[i], i);
            }
            sort(nums1.begin(), nums1.end());
            sort(nums2WithIndex.begin(), nums2WithIndex.end());
    
            vector<int> res(n, -1);
            vector<int> rem;
            int i = 0, j= 0;
            while(i < n && j < n){
                if(nums1[i] > nums2WithIndex[j].first){
                    res[nums2WithIndex[j].second] = nums1[i];
                    i++;
                    j++;
                }else{
                    rem.push_back(nums1[i]);
                    i++;
                }
            }
    
            for(int k = 0; k < n; k++){
                if(res[k] == -1){
                    res[k] = rem.back();
                    rem.pop_back();
                }
            }
            return res;
        }
    };