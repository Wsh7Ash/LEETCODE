class Solution {
    public:
        int countStudents(vector<int>& students, vector<int>& sandwiches) {
            int count[2] = {0, 0};
            for(int s : students){
                count[s]++;
            }
            int i = 0; 
            while(i < sandwiches.size()){
                if(count[sandwiches[i]] == 0){
                    break;
                }
                count[sandwiches[i]]--;
                i++;
            }
            return sandwiches.size() - i;
        }
    };