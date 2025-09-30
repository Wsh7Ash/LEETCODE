class Solution {
    public:
        vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
            sort(products.begin(), products.end());
    
            vector<vector<string>> res;
            string prefix = "";
    
            for(char c : searchWord){
                prefix += c;
                vector<string> suggestions;
    
                for(const string& product : products){
                    if(product.size() >= prefix.size() &&
                        product.substr(0, prefix.size()) == prefix){
                            suggestions.push_back(product);
                             if(suggestions.size() == 3) break;
                    }
                }
                res.push_back(suggestions);
            }
            return res;
        }
    };