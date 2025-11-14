class Solution {
    public:
        vector<int> decode(vector<int>& encoded, int first) {
            int n = encoded.size() + 1;
            vector<int> res(n);
            res[0] = first;
            for(int i = 0; i < n - 1; i++) res[i + 1] = encoded[i] ^ res[i];
            return res;
        }
    };