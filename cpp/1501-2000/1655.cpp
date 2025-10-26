class Solution {
    public:
        bool canDistribute(vector<int>& nums, vector<int>& quantity) {
            unordered_map<int, int> freq;
            for(int num : nums){
                freq[num]++;
            }
            vector<int> counts;
            for(auto& [num, count] : freq){
                counts.push_back(count);
            }
            sort(quantity.rbegin(), quantity.rend());
            sort(counts.rbegin(), counts.rend());
    
            return backtrack(counts, quantity, 0);
        }
    
    private:
        bool backtrack(vector<int>& counts, vector<int>& quantity, int idx){
            if(idx == quantity.size()) return true;
            for(int i = 0; i < counts.size(); i++){
                if(i > 0 && counts[i] == counts[i - 1]) continue;
                if(counts[i] >= quantity[idx]){
                    counts[i] -= quantity[idx];
                    if(backtrack(counts, quantity, idx + 1)) return true;
                    counts[i] += quantity[idx];
                }
            }
            return false;
        }
    };