class Solution {
    public:
        double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
           int n = quality.size();
           vector<pair<double, int>> workers;
           for(int i = 0; i <  n; i++){
            workers.emplace_back(static_cast<double>(wage[i]) / quality[i], quality[i]);
           } 
           sort(workers.begin(), workers.end());
    
           priority_queue<int> max_heap;
           int sum_heap = 0;
           double res = numeric_limits<double>::max();
    
           for(const auto& worker : workers){
            double ratio = worker.first;
            int q = worker.second;
    
            sum_heap += q;
            max_heap.push(q);
    
            if(max_heap.size() > k){
                sum_heap -= max_heap.top();
                max_heap.pop();
            }
            if(max_heap.size() == k){
                res = min(res, ratio * sum_heap);
            }
           }
           return res;
        }
    };