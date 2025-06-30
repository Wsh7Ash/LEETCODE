class Solution {
    public:
        vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
          int n = arr.size();
          auto cmp = [&](const pair<int, int>& a, const pair<int, int>& b) {
            return arr[a.first] * arr[b.second] > arr[a.second] * arr[b.first];
          };
          priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    
          for(int i = 0; i < n - 1; i++) pq.push({i, n - 1});
    
          for(int i = 1; i < k; i++){
            auto cur = pq.top();
            pq.pop();
            int n = cur.first;
            int d = cur.second;
            if(d - 1 > n){
                pq.push({n, d - 1});
            }
          }
          auto res = pq.top();
          return {arr[res.first], arr[res.second]};
        }
    };