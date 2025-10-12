class Solution {
    public:
        vector<vector<string>> displayTable(vector<vector<string>>& orders) {
            set<string> foodItems;
            set<int> tableNumbers;
    
            map<int, unordered_map<string, int>> tableOrders;
    
            for(auto& order : orders){
                string tableStr = order[1];
                string foodItem = order[2];
            
                int tableNum = stoi(tableStr);
    
                foodItems.insert(foodItem);
                tableNumbers.insert(tableNum);
                tableOrders[tableNum][foodItem]++;
            }
    
            vector<vector<string>> res;
    
            vector<string> header;
            header.push_back("Table");
            for(auto& food : foodItems){
                header.push_back(food);
            }
            res.push_back(header);
    
            for(int tableNum : tableNumbers){
                vector<string> row;
                row.push_back(to_string(tableNum));
    
                auto& tableOrder = tableOrders[tableNum];
                for(auto& food : foodItems){
                    row.push_back(to_string(tableOrder[food]));
                }
                res.push_back(row);
            }
            return res;
        }
    };