class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0;
        int dir = 0;

        vector<vector<int>> dirs = {{0,1}, {1,0}, {0, -1}, {-1, 0}};

        for(char i : instructions){
            if(i == 'G'){
                x += dirs[dir][0];
                y += dirs[dir][1];
            }else if(i == 'L'){
                dir = (dir + 3) % 4;
            }else if(i == 'R'){
                dir = (dir + 1) % 4;
            }
        }
        return (x == 0 && y == 0) || (dir != 0);
    }
};