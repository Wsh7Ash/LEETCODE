class Solution {
    public:
        vector<int> movesToStamp(string stamp, string target) {
           int stamp_len = stamp.size();
           int target_len = target.size();
           vector<int> res;
           vector<bool> stamped(target_len, false);
           int total_stamped = 0;
    
           while(total_stamped < target_len){
            bool stamped_in_round = false;
            for(int i = 0; i <= target_len - stamp_len; i++){
                if(stamped[i]) continue;
                bool match = true;
                int temp_stamped = 0;
                for(int j = 0; j < stamp_len; j++){
                    if(target[i+j] != '?' && target[i+j] != stamp[j]){
                        match = false;
                        break;
                    }
                }
                if(match){
                    for(int j = 0; j < stamp_len; j++){
                        if(target[i+j] != '?'){
                            target[i+j] = '?';
                            temp_stamped++;
                        }
                    }
    
                    if(temp_stamped > 0){
                        res.push_back(i);
                        total_stamped += temp_stamped;
                        stamped_in_round = true;
                        break;
                    }
                }
            }
            if(!stamped_in_round) return {};
           }
           reverse(res.begin(), res.end());
           return res;
    
    
        }
    };