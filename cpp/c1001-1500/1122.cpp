class Solution {
    public:
        vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
            map<int, int> freq;
            for(int num : arr1){
                freq[num]++;
            }
    
            vector<int> res;
            for(int num : arr2){
                while(freq[num] > 0){
                    res.push_back(num);
                    freq[num]--;
                }
            }
    
            vector<int> rem;
            for(auto& [num, count] : freq){
                while(count > 0){
                    rem.push_back(num);
                    count--;
                }
            }
            sort(rem.begin(), rem.end());
            res.insert(res.end(), rem.begin(), rem.end());
    
            return res;
        }
    };