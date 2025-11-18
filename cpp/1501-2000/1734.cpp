class Solution {
    public:
        vector<int> decode(vector<int>& encoded) {
            int n = encoded.size() + 1;
            int totalXOR = 0;
            for(int i = 1; i <= n; i++){
                totalXOR ^= i;
            }      
            int xorExceptFirst = 0;
            for(int i = 1; i < n; i+= 2){
                xorExceptFirst ^= encoded[i];
            }
            int firstElement = totalXOR ^ xorExceptFirst;
    
            vector<int> perm(n);
            perm[0] = firstElement;
            for(int i = 0; i < n - 1; i++){
                perm[i + 1] = perm[i] ^ encoded[i];
            }
            return perm;
        }
    };