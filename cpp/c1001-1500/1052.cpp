class Solution {
    public:
        int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
           int n = customers.size();
           int already_satisfied = 0;
           for(int i = 0; i < n; i++){
            if(grumpy[i] == 0){
                already_satisfied += customers[i];
            }
           } 
    
           int max_gain = 0;
           int cur_gain = 0;
    
           for(int i = 0;i <minutes; i++){
            if(grumpy[i] == 1){
                cur_gain += customers[i];
            }
           }
           max_gain = cur_gain;
    
           for(int i = minutes; i < n; i++){
            if(grumpy[i - minutes] == 1){
                cur_gain -= customers[i - minutes];
            }
            if(grumpy[i] == 1){
                cur_gain += customers[i];
            }
            max_gain = max(max_gain, cur_gain);
           }
           return already_satisfied + max_gain;
        }
    };