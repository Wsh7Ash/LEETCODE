class Solution {
    public:
        int totalFruit(vector<int>& fruits) {
            unordered_map<int, int> fruitCount;
            int l = 0, maxFruits = 0;
    
            for(int r = 0; r < fruits.size(); r++){
                fruitCount[fruits[r]]++;
    
                while(fruitCount.size() > 2){
                    fruitCount[fruits[l]]--;
                    if(fruitCount[fruits[l]] == 0){
                        fruitCount.erase(fruits[l]);
                    }
                    l++;
                }
                maxFruits = max(maxFruits, r - l + 1);
            }
            return maxFruits;
            
        }
    };