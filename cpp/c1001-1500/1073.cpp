class Solution {
    public:
        vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
            vector<int> res;
            int i = arr1.size() - 1;
            int j = arr2.size() - 1;
            int carry = 0;
    
            while(i >= 0 || j >= 0 || carry != 0){
                int bit1 = (i >= 0) ? arr1[i--] : 0;
                int bit2 = (j >= 0) ? arr2[j--] : 0;
                int sum = bit1 + bit2 + carry;
    
                int res_bit = sum & 1;
                carry = -(sum >> 1);
    
                // if(res_bit < 0){
                //     res_bit += 2;
                //     carry += 1;
                // }
                // if(res_bit >= 2){
                //     res_bit -= 2;
                //     carry -= 1;
                // }
                res.push_back(res_bit);
            }
    
            while(res.size() > 1 && res.back() == 0) res.pop_back();
            reverse(res.begin(), res.end());
            return res;
        }
    };