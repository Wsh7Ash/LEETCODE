class Solution {
public:
    int clumsy(int n) {
        stack<int> nums;
        // stack<char> ops;
        vector<char> operations = {'*', '/', '+', '-'};
        int index = 0;

        nums.push(n);
        for(int i = n - 1; i >= 1; i--){
            char op = operations[(n - i - 1) % 4];
            if(op == '*' || op == '/'){
                int top = nums.top();
                nums.pop();
                if(op == '*'){
                    nums.push(top * i);
                }else{
                    nums.push(top / i);
                }
            }else{
                nums.push((op == '+') ? i : -i);
            }
        }

        int res = 0;
        while(!nums.empty()){
            res += nums.top();
            nums.pop();
        }
        return res;
    }
};