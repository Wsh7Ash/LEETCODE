class Solution {
    public:
        double getMinDistSum(vector<vector<int>>& positions) {
            double x = 0, y = 0;
            int n = positions.size();
            for(auto& pos : positions){
                x += pos[0];
                y += pos[1];
            }
            x/=n;
            y/=n;
    
            double alpha = 1.0;
            double precision = 1e-7;
            double prevDist = ctd(positions, x, y);
    
            while(alpha > precision){
                double gradX = 0, gradY = 0;
    
                for(auto& pos : positions){
                    double dx = x - pos[0];
                    double dy = y - pos[1];
                    double dist = sqrt(dx * dx + dy * dy);
                    if(dist > precision){
                        gradX += dx / dist;
                        gradY += dy / dist;
                    }
                }
    
                double newX = x - alpha * gradX;
                double newY = y - alpha * gradY;
                double newDist = ctd(positions, newX, newY);
                if(newDist < prevDist){
                    x = newX;
                    y = newY;
                    prevDist = newDist;
                }else{
                    alpha *= 0.5;
                }
            }
            return prevDist;
    
        }
    
    private:
        double ctd(vector<vector<int>>& positions, double x, double y){
            double total = 0;
            for(auto& pos : positions){
                double dx = x - pos[0];
                double dy = y - pos[1];
                total += sqrt(dx * dx + dy * dy);
            }
            return total;
        }
    };