class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
            unordered_map<char, int> freq;
            int max_freq = 0;
            for(char task : tasks){
                freq[task]++;
                max_freq = max(max_freq, freq[task]);
            }
            int num_max_tasks = 0;
            for(auto it : freq){
                if(it.second == max_freq){
                    num_max_tasks++;
                }
            }
            int required = (max_freq - 1) * (n+1) + num_max_tasks;
            return max(required, (int)tasks.size());
        }
    };