class Solution {
    public:
        vector<int> pancakeSort(vector<int>& arr) {
            vector<int> res;
            int n = arr.size();
            for(int i = n; i > 0; i--){
                int pos = find(arr, i);
                if(pos == i - 1){
                    continue;
                }
                if(pos != 0){
                    res.push_back(pos + 1);
                    reverse(arr.begin(), arr.begin() + pos + 1);
                }
                res.push_back(i);
                reverse(arr.begin(), arr.begin() + i);
            }
        return res;
        }
    private:
        int find(const vector<int>& arr, int t){
            for(int i = 0; i < arr.size(); i++){
                if(arr[i] == t){
                    return i;
                }
            }
            return -1;
        }
    };