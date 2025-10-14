class SubrectangleQueries {
    private:
        vector<vector<int>> r;
        vector<tuple<int ,int, int, int, int>> updates;
    
    public:
        SubrectangleQueries(vector<vector<int>>& rectangle) {
            r = rectangle;    
        }
        
        void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
            updates.emplace_back(row1, col1, row2, col2, newValue);
        }
        
        int getValue(int row, int col) {
            
            for(auto it = updates.rbegin(); it != updates.rend(); it++){
                auto [r1,c1,r2,c2,newValue] = *it;
                if(row >= r1 && row <= r2 && col >= c1 && col <= c2){
                    return newValue;
                }
            }
    
            return r[row][col];
        }
    };
    
    /**
     * Your SubrectangleQueries object will be instantiated and called as such:
     * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
     * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
     * int param_2 = obj->getValue(row,col);
     */