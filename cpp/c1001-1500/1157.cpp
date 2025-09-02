class MajorityChecker {
    private:
        unordered_map<int, vector<int>> indicesMap;
        vector<int> arr;
        int n;
    public:
        MajorityChecker(vector<int>& arr) : arr(arr) {
            n = arr.size();
            for(int i = 0; i < n; i++){
                indicesMap[arr[i]].push_back(i);
            }
            srand(time(0));
        }
        
        int query(int left, int right, int threshold) {
            if(left < 0) left = 0;
            if(right >= n) right = n - 1;
            if(left > right) return -1;
            
            int len = right - left + 1;
            if(threshold > len) return -1;
            
            for(int i = 0; i < 20; i++){
                int randIndex = left + rand() % len;
                int candidate = arr[randIndex];
                const vector<int>& indices = indicesMap[candidate];
                
                auto leftIt = lower_bound(indices.begin(), indices.end(), left);
                auto rightIt = upper_bound(indices.begin(), indices.end(), right);
                int count = distance(leftIt, rightIt);
                
                if(count >= threshold){
                    return candidate;
                }
            }
            return -1;
        }
    };