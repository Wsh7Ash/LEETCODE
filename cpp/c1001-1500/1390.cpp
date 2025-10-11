class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;

        for(int num : nums){
            vector<int> divisors;

            for(int i  = 1; i * i <= num; i++){
                if(num % i == 0){
                    divisors.push_back(i);
                    if(i != num / i){
                        divisors.push_back(num / i);
                    }
                }

                if(divisors.size() > 4) break;
            }
            if(divisors.size() == 4){
                for(int divisor : divisors){
                    res += divisor;
                }
            }
        }
        return res;
    }
};