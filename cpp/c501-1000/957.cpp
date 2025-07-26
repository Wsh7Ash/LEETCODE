class Solution {
    public:
        vector<int> prisonAfterNDays(vector<int>& cells, int n) {
            unordered_map<string, int> seen;
            for(int day = 0; day < n; day++){
                string key;
                for(int cell : cells){
                    key += to_string(cell);
                }
                if(seen.find(key) != seen.end()){
                    int cl = day - seen[key];
                    int rd = (n - day) % cl;
                    return prisonAfterNDays(cells, rd);
                }
                seen[key] = day;
                vector<int> next_cells(8, 0);
                for(int i = 1; i < 7; i++){
                    if(cells[i - 1] == cells[i + 1]){
                        next_cells[i] = 1;
                    }else{
                        next_cells[i] = 0;
                    }
                }
                cells = next_cells;
            }
            return cells;
        }
    };