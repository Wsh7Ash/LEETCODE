class Solution {
    public:
        double radius, x_center, y_center;
        Solution(double radius, double x_center, double y_center) {
            this->radius = radius;
            this->x_center = x_center;
            this->y_center = y_center;
            srand(time(0));
        }
        
        vector<double> randPoint() {
            double theta = 2 * M_PI * (double)rand() / RAND_MAX;
            double r = radius * sqrt((double)rand() / RAND_MAX);
            double x = x_center + r * cos(theta);
            double y = y_center + r * sin(theta);
            return {x,y};
        }
    };
    
    /**
     * Your Solution object will be instantiated and called as such:
     * Solution* obj = new Solution(radius, x_center, y_center);
     * vector<double> param_1 = obj->randPoint();
     */