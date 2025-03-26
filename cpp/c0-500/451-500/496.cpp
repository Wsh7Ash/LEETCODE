class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int, int> nextGreater;
            stack<int> stack;
            for(int num : nums2){
                while(!stack.empty() && num > stack.top()){
                    nextGreater[stack.top()] = num;
                    stack.pop();
                }
                stack.push(num);
            }
    
            while(!stack.empty()){
                nextGreater[stack.top()] = -1;
                stack.pop();
            }
            vector<int> result(nums1.size());
            for(int i = 0; i < nums1.size();i++){
                result[i] = nextGreater[nums1[i]];
            }
            return result;
        }
    };