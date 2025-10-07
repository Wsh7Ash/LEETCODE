class Solution {
    public:
        bool isPossible(vector<int>& target) {
            priority_queue<long long> pq;
            long long sum = 0;
    
            for(int num : target){
                pq.push(num);
                sum += num;
            }
    
            while(pq.top() != 1){
                long long maxVal = pq.top();
                pq.pop();
    
                long long restSum = sum - maxVal;
    
                if(restSum <= 0) return false;
                if(restSum == 1) return true;
                if(maxVal <= restSum) return false;
            
                long long prevVal = maxVal % restSum;
    
                if(prevVal == 0 && restSum != 1)  return false;
    
                sum = restSum + prevVal;
                pq.push(prevVal);
            }
    
            return true;
        }
    };