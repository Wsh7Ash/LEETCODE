class Solution {
    public:
        vector<int> rearrangeBarcodes(vector<int>& barcodes) {
            unordered_map<int, int> freq;
            for(int num : barcodes){
                freq[num]++;
            }
    
            priority_queue<pair<int, int>> max_heap;
            for(auto& [num, count] : freq){
                max_heap.push({count, num});
            }
    
            vector<int> res;
            while(!max_heap.empty()){
                auto [count1, num1] = max_heap.top();
                max_heap.pop();
    
                if(res.empty() || res.back() != num1){
                    res.push_back(num1);
                    if(--count1 > 0){
                        max_heap.push({count1, num1});
                    }
                }else{
                    if(max_heap.empty()){
                        break;
                    }
    
                    auto [count2, num2] = max_heap.top();
                    max_heap.pop();
                    res.push_back(num2);
                    if(--count2 > 0){
                        max_heap.push({count2, num2});
                    }
                    max_heap.push({count1, num1});
                }
            }
            return res;
        }
    };