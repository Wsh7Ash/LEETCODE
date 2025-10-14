class Solution {
    public:
        int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
            unordered_map<int, int> freq;
            for(int num : arr){
                freq[num]++;
            }
    
            vector<int> counts;
            for(auto& p : freq){
                counts.push_back(p.second);
            }    
            sort(counts.begin(), counts.end());
    
            int res = counts.size();
            for(int count : counts){
                if(k >= count){
                    k -= count;
                    res--;
                }else{
                    break;
                }
            }
            return res;
        }
    };