class Solution {
    public:
        int countLargestGroup(int n) {
            unordered_map<int, int> groupSizes;
            int maxSize = 0;
    
            for(int i = 1; i <= n; i++){
                int num = i;
                int digitSum = 0;
    
                while(num > 0){
                    digitSum += num % 10;
                    num /= 10;
                }
    
                groupSizes[digitSum]++;
                maxSize = max(maxSize, groupSizes[digitSum]);
            }   
    
            int count = 0;
            for(auto& [sum, size] : groupSizes){
                if(size == maxSize){
                    count++;
                }
            }
    
            return count;
        }
    };