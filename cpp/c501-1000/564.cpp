class Solution {
    public:
        string nearestPalindromic(string n) {
            long num = stol(n);
            if (num == 1) return "0";
    
            vector<long> candidates;
            int len = n.length();
    
            candidates.push_back(static_cast<long>(pow(10, len)) + 1);
            candidates.push_back(static_cast<long>(pow(10, len - 1)) - 1);
    
            string half = n.substr(0, (len + 1) / 2);
            long halfNum = stol(half);
    
            for(long delta : {-1, 0, 1}){
                string newHalf = to_string(halfNum + delta);
                string candidate;
                if(len % 2 == 0){
                    candidate = newHalf + string(newHalf.rbegin(), newHalf.rend());
                }else{
                    candidate = newHalf + string(newHalf.rbegin() + 1, newHalf.rend());
                }
                candidates.push_back(stol(candidate));
            }
    
            long minDiff = LONG_MAX;
            long result = 0;
    
            for(long candidate : candidates){
                if(candidate == num) continue;
                long diff = abs(candidate - num);
                if(diff < minDiff){
                    minDiff = diff;
                    result = candidate;
                }else if(diff == minDiff && candidate < result){
                    result = candidate;
                }
            }
            return to_string(result);
        }
    };