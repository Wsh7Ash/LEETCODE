class Solution {
    public:
        int longestDecomposition(string text) {
           int n = text.size();
           int left = 0, right = n - 1;
           int count = 0;
           string prefix = "";
           string suffix = "";
    
           while(left <= right){
                prefix += text[left];
                suffix = text[right] + suffix;
    
                if(prefix == suffix){
                    count += (left == right) ? 1 : 2;
                    prefix = "";
                    suffix = "";
                }
                left++;
                right--;
           } 
    
           if(!prefix.empty() || !suffix.empty()) count++;
           return count;
        }
    };