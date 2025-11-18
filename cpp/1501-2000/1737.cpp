class Solution {
    public:
        int minCharacters(string a, string b) {
            vector<int> count_a(26, 0);
            vector<int> count_b(26, 0);
    
            for(char ch : a){
                count_a[ch - 'a']++;
            }
    
            for(char ch : b){
                count_b[ch - 'a']++;
            }
            int len_a = a.length();
            int len_b = b.length();
    
            int min_ops_cond3 = len_a + len_b;
            for(int i = 0; i < 26; i++){
                int ops = (len_a - count_a[i]) + (len_b - count_b[i]);
                min_ops_cond3 = min(min_ops_cond3, ops);
            }
            int min_ops_cond1 = len_a + len_b;
            int min_ops_cond2 = len_a + len_b;
    
            for(int threshold = 1; threshold < 26; threshold++){
                int ops_a = 0;
                for(int i = threshold; i < 26; i++){
                    ops_a += count_a[i];
                }
                int ops_b = 0;
                for(int i = 0; i < threshold; i++){
                    ops_b += count_b[i];
                }
                min_ops_cond1 = min(min_ops_cond1, ops_a + ops_b);
                int ops_b2 = 0;
                for(int i = threshold; i < 26; i++){
                    ops_b2 += count_b[i];
                }
                int ops_a2 = 0;
                for(int i = 0; i < threshold; i++){
                    ops_a2 += count_a[i];
                }
                min_ops_cond2 = min(min_ops_cond2, ops_a2 + ops_b2);
            }
            return min({min_ops_cond1, min_ops_cond2, min_ops_cond3});
        }
    };