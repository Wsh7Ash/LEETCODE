class Solution {
    public:
        int calPoints(vector<string>& operations) {
            vector<int> r;
            for(const string& op : operations){
                if(op == "+"){
                    int l = r.back();
                    int sl = r[r.size() - 2];
                    r.push_back(l + sl);
                }else if(op == "D"){
                    r.push_back(2 * r.back());
                }
                else if(op == "C"){
                    r.pop_back();
                }else{
                    r.push_back(stoi(op));
                }
            }
            return accumulate(r.begin(), r.end(), 0);
        }
    };