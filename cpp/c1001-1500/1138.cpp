class Solution {
    public:
        string alphabetBoardPath(string target) {
            unordered_map<char, pair<int, int>> pos;
            string board = "abcdefghijklmnopqrstuvwxyz";
            for(int i = 0; i < board.size(); i++){
                int row = i / 5;
                int col = i % 5;
                pos[board[i]] = {row, col};
            }
    
            int x0 = 0, y0 = 0;
            string res;
            for(char c : target){
                int x = pos[c].first, y = pos[c].second;
                if(y <y0) res += string(y0 - y, 'L');
                if(x <x0) res += string(x0 - x, 'U');
                if(x >x0) res += string(x - x0, 'D');
                if(y >y0) res += string(y - y0, 'R');
                res +='!';
                x0 = x;
                y0 = y;
    
            }
    
            return res;
        }
    };