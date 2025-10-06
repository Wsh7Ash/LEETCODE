class Solution {
    public:
        vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
            
            vector<vector<int>> filtered;
    
            for(auto& restaurant : restaurants){
                int id = restaurant[0];
                int rating = restaurant[1];
                int isVegan = restaurant[2];
                int price = restaurant[3];
                int distance = restaurant[4];
            
                if(price <= maxPrice && distance <= maxDistance){
                    if(veganFriendly == 0 || isVegan == 1){
                        filtered.push_back({rating, id});
                    }
                }
            }
            
            sort(filtered.begin(), filtered.end(), [](const vector<int>& a, const vector<int>& b){
                if(a[0] != b[0]) return a[0] > b[0];
    
                return a[1] > b[1];
            });
    
    
            vector<int> res;
            for(auto& rest : filtered){
                res.push_back(rest[1]);
            }
    
            return res;
        }
    };