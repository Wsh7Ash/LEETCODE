class Solution {
    public:
        int oddEvenJumps(vector<int>& arr) {
            int n =arr.size();
            if(n == 0) return 0;
    
            vector<bool> odd(n, false);
            vector<bool> even(n, false);
            odd[n-1]= even[n-1] = true;
    
            map<int, int> vti;
            vti[arr[n-1]] = n-1;
    
            int res = 1;
    
            for(int i = n-2; i>=0; i--){
                auto it = vti.lower_bound(arr[i]);
                if(it != vti.end()){
                    int j = it->second;
                    odd[i] = even[j];
                }
                it = vti.upper_bound(arr[i]);
                if(it != vti.begin()){
                    it--;
                    int j = it->second;
                    even[i] = odd[j];
                }
                vti[arr[i]] = i;
                if(odd[i]) res++;
            }
            return res;
        }
    };