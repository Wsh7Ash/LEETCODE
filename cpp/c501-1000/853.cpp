class Solution {
    public:
        int carFleet(int target, vector<int>& position, vector<int>& speed) {
            int n = position.size();
            if(n == 0) return 0;
    
            vector<pair<int, double>> cars;
            for(int i = 0; i < n; i++){
                double time = (double)(target - position[i]) / speed[i];
                cars.emplace_back(position[i], time);
            }
    
            sort(cars.begin(), cars.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
                return a.first > b.first;
            });
    
            stack<double> fleets;
            for(const auto& car : cars){
                if(fleets.empty() || car.second > fleets.top()){
                    fleets.push(car.second);
                }
            }
            return fleets.size();
        }
    };