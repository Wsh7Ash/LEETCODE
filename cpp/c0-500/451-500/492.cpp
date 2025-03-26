class Solution {
    public:
        vector<int> constructRectangle(int area) {
            int w = static_cast<int>(sqrt(area));
    
            while(w > 0 && area % w != 0) w--;
    
            if(w == 0) return {area, 1};
    
            int l = area / w;
            if(l < w) return {w, l};
    
            return {l, w};
        }
    };