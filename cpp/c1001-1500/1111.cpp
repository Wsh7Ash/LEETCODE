class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> res(n);
        int depth = 0;
        for(int i = 0; i < n; i++){
            if(seq[i] == '('){
                depth++;
                res[i] = depth % 2;
            }else{
                res[i] = depth % 2;
                depth--;
            }
        }
        return res;
    }
};