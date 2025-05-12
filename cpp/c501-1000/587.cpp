class Solution {
    public:
        int cross(vector<int>& a, vector<int>& b, vector<int>& c){
            return (b[0] - a[0])*(c[1]- a[1])-(b[1]-a[1])*(c[0]-a[0]);
        }
    
        bool isBetween(vector<int>& a, vector<int>& c, vector<int>& b){
            int crossProduct = (c[0] - a[0])* (b[1]-a[1])-(c[1]-a[1])*(b[0]-a[0]);
            if(crossProduct != 0) return false;
            int minX = min(a[0], c[0]), maxX = max(a[0], c[0]);
            int minY = min(a[1], c[1]), maxY = max(a[1], c[1]);
            return b[0] >= minX && b[0] <= maxX && b[1] >= minY && b[1] <= maxY;
        }
    
        vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
            int n = trees.size();
            if(n <= 1) return trees;
            sort(trees.begin(), trees.end(), [](vector<int>& a, vector<int>& b){
                return a[0] < b[0] || ( a[0] == b[0] && a[1] < b[1]);
            });
    
            vector<vector<int>> hull;
    
            for(int i = 0; i < n; i++){
                while(hull.size() >= 2 && cross(hull[hull.size()-2], hull.back(), trees[i]) < 0){
                    hull.pop_back();
                }
                hull.push_back(trees[i]);
            }
    
            for(int i = n-2; i >= 0; i--){
                while(hull.size() >= 2 && cross(hull[hull.size()-2], hull.back(), trees[i]) < 0){
                    hull.pop_back();
                }
                hull.push_back(trees[i]);
            }
    
            sort(hull.begin(), hull.end());
            hull.erase(unique(hull.begin(), hull.end()), hull.end());
    
            if(hull.size() <= 2) return hull;
    
            set<vector<int>> hullSet(hull.begin(), hull.end());
    
            for(int i = 0; i < hull.size(); i++){
                vector<int> p1 = hull[i];
                vector<int> p2 = hull[(i+1) % hull.size()];
                for(auto& tree : trees){
                    if(isBetween(p1, tree, p2)){
                        hullSet.insert(tree);
                    }
                }
            }
            return vector<vector<int>>(hullSet.begin(), hullSet.end());
        }
    };