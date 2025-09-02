class Solution {
    private:
        vector<string> split(const string& s, char deli) {
            vector<string> tokens;
            string token;
            istringstream tokenStream(s);
            
            while (getline(tokenStream, token, deli)) {
                tokens.push_back(token);
            }
            return tokens;
        }
        
    public:
        vector<string> invalidTransactions(vector<string>& transactions) {
            vector<string> res;
            unordered_map<string, vector<vector<string>>> byName;
            unordered_set<int> invalidIndices;
            
            for (int i = 0; i < transactions.size(); i++) {
                const string& tr = transactions[i];
                vector<string> parts = split(tr, ',');
                string name = parts[0];
                int time = stoi(parts[1]);
                int amount = stoi(parts[2]);
                string city = parts[3];
                
                if (amount > 1000) {
                    invalidIndices.insert(i);
                }
                
                vector<string> transactionWithIndex = parts;
                transactionWithIndex.push_back(to_string(i)); 
                byName[name].push_back(transactionWithIndex);
            }
            
            for (auto& [name, transList] : byName) {
                for (int i = 0; i < transList.size(); i++) {
                    int time1 = stoi(transList[i][1]);
                    string city1 = transList[i][3];
                    int idx1 = stoi(transList[i][4]);
                    
                    for (int j = i + 1; j < transList.size(); j++) {
                        int time2 = stoi(transList[j][1]);
                        string city2 = transList[j][3];
                        int idx2 = stoi(transList[j][4]);
                        
                        if (city1 != city2 && abs(time1 - time2) <= 60) {
                            invalidIndices.insert(idx1);
                            invalidIndices.insert(idx2);
                        }
                    }
                }
            }
            
            for (int idx : invalidIndices) {
                res.push_back(transactions[idx]);
            }
            
            return res;
        }
    };