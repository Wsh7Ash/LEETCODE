class Solution {
    public:
        int minSetSize(vector<int>& arr) {
            unordered_map<int, int> freq;
            for(int num : arr) freq[num]++;
    
            priority_queue<int> maxHeap;
            for(auto& pair : freq){
                maxHeap.push(pair.second);
            }
    
            int target = arr.size() / 2;
            int removed = 0;
            int setSize = 0;
    
            while(removed < target){
                removed += maxHeap.top();
                maxHeap.pop();
                setSize++;
            }
    
            return setSize;
        }
    };