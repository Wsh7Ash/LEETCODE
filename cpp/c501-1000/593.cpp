class Solution {
    public:
        bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
            auto dist = [](vector<int>& a, vector<int>& b){
                return (a[0] - b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
            };
            vector<vector<int>> points = {p1,p2,p3,p4};
    
            set<int> dists;
            for(int i =0; i < 4; i++){
                for(int j = i + 1; j < 4; j++){
                    dists.insert(dist(points[i], points[j]));
                }
            }
            return dists.size() == 2 && *dists.begin()>0;
        }
    };