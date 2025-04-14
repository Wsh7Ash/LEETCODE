class Solution {
    public:
        int nextGreaterElement(int n) {
            string s = to_string(n);
            int pivot = -1;
    
            for(int i = s.size() - 2; i >= 0; i--){
                if(s[i] < s[i+1]){
                    pivot = i;
                    break;
                }
            }
            if(pivot == -1){
                return -1;
            }
            int successor = -1;
            for(int i = s.size() - 1; i > pivot; i--){
                if(s[i] > s[pivot]){
                    successor = i;
                    break;
                }
            }
            swap(s[pivot], s[successor]);
            reverse(s.begin() + pivot + 1, s.end());
    
            long long res = stoll(s);
            if(res > INT_MAX){
                return -1;
            }
            return res;
        }
    };