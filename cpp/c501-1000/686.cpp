class Solution {
    public:
        int repeatedStringMatch(string a, string b) {
            for(char c : b){
                if(a.find(c) == string::npos){
                    return -1;
                }
            }
            int count = 1;
            string rep = a;
            while(rep.size() < b.size()){
                rep += a;
                count++;
            }
            if(rep.find(b) != string::npos){
                return count;
            }
    
            rep += a;
            count++;
            if(rep.find(b) != string::npos){
                return count;
            }
            return -1;
        }
    };