class RLEIterator {
    public:
        vector<int> encoding;
        int curPos;
        int curCount;
    
        RLEIterator(vector<int>& encoded) : encoding(encoded), curPos(0), curCount(0) {
            if(curPos < encoding.size()) curCount = encoding[curPos];
        }
        
        int next(int n) {
            while(curPos < encoding.size()){
                if(curCount >= n){
                    curCount -= n;
                    return encoding[curPos + 1];
                }else{
                    n -= curCount;
                    curPos += 2;
                    if(curPos < encoding.size()){
                        curCount = encoding[curPos];
                    }else{
                        return -1;
                    }
                }
            }
            return -1;
        }
    };
    
    /**
     * Your RLEIterator object will be instantiated and called as such:
     * RLEIterator* obj = new RLEIterator(encoding);
     * int param_1 = obj->next(n);
     */