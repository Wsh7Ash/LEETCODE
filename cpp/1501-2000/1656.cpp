class OrderedStream {
    public:
        vector<string> data;
        int ptr;
        OrderedStream(int n) : data(n + 1), ptr(1) {}
        
        vector<string> insert(int idKey, string value) {
            data[idKey] = value;
            vector<string> res;
            if(idKey == ptr){
                while(ptr < data.size() && !data[ptr].empty()){
                    res.push_back(data[ptr]);
                    ptr++;
                }
            }
            return res;
        }
    };
    
    /**
     * Your OrderedStream object will be instantiated and called as such:
     * OrderedStream* obj = new OrderedStream(n);
     * vector<string> param_1 = obj->insert(idKey,value);
     */