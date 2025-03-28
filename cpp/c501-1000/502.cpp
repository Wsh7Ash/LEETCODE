class Solution {
    public:
        int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
            int n = profits.size();
            vector<pair<int, int>> proje-cts;
            for(int i = 0; i < n; i++){
                projects.emplace_back(capital[i], profits[i]);
            }
    
            sort(projects.begin(), projects.end());
    
            priority_queue<int> maxHeap;
            int cur = 0;
    
            for(int i = 0; i < k; i++){
                while(cur < n && projects[cur].first <= w){
                    maxHeap.push(projects[cur].second);
                    cur++;
                }
                if(maxHeap.empty()) break;
    
                w += maxHeap.top();
                maxHeap.pop();
            }
            return w;
        }
    };