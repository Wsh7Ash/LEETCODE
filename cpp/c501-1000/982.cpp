class Solution {
    public:
        int countTriplets(vector<int>& nums) {
            unordered_map<int, int> freq;
            for(int num : nums){
                freq[num]++;
            }
    
            unordered_map<int, int> and_counts;
            for(auto it1 = freq.begin(); it1 != freq.end(); it1++){
                for(auto it2 = freq.begin(); it2 != freq.end(); it2++){
                    int ab = it1->first & it2->first;
                    and_counts[ab] += it1->second * it2->second;
                }
            }
    
            int total = 0;
            for(auto it = and_counts.begin(); it != and_counts.end(); it++){
                int ab = it->first;
                int count_ab = it->second;
                for(auto num_it = freq.begin(); num_it != freq.end(); num_it++){
                    if((ab & num_it->first) == 0){
                        total += count_ab * num_it->second;
                    }
                }
            }
            return total;
        }
    };