class Solution {
public:
    string maximumBinaryString(string binary) {
        int n = binary.size();
        int zeros = 0;
        int firstZero = -1;

        for(int i = 0; i < n; i++){
            if(binary[i] == '0'){
                if(firstZero == -1){
                    firstZero = i;
                }
                zeros++;
            }
        }
        if(zeros <= 1){
            return binary;
        }
        string res(n, '1');
        res[firstZero + zeros - 1] = '0';
        return res;
    }
};