class Solution {
    public:
        bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
            stack<int> s;
            int popIndex = 0;
            for(int num : pushed){
                s.push(num);
                while(!s.empty() && popIndex < popped.size() && s.top() == popped[popIndex]){
                    s.pop();
                    popIndex++;
                }
            }
            return popIndex == popped.size();
        }
    };