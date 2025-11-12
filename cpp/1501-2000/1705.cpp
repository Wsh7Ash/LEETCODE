class Solution {
    public:
        int eatenApples(vector<int>& apples, vector<int>& days) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            int eaten = 0;
            int n = apples.size();
            int day = 0;
    
            while(day < n || !pq.empty()){
                if(day < n && apples[day] > 0){
                    pq.push({day + days[day], apples[day]});
                }
                while(!pq.empty() && pq.top().first <= day){
                    pq.pop();
                }
                if(!pq.empty()){
                    auto [expire_day, count] = pq.top();
                    pq.pop();
                    eaten++;
                    if(count > 1){
                        pq.push({expire_day, count - 1});
                    }
                }
                day++;
            }
            return eaten;
        }
    };