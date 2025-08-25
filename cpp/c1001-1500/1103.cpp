class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        int round = 0;

        while(true){
            long long total_round = (long long)num_people * (num_people + 1) / 2 + (long long)round * num_people * num_people;
            if(total_round <= candies){
                round++;
                candies -= total_round;
            }else{
                break;
            }
        }
        for(int i = 0; i < num_people; i++){
            long long total_i = (long long)round * (2 * (i+1) + (round - 1) * num_people) / 2;
            res[i] = total_i; 
        }

        int start = round * num_people;
        for(int i = 0; i < num_people; i++){
            int give = start + i + 1;
            if(candies >= give){
                res[i] += give;
                candies -= give;
            }else{
                res[i] += candies;
                candies = 0;
                break;
            }
        }
        return res;

    }
};