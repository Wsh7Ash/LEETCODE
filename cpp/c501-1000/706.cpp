class MyHashMap {
    public:
        static const int bc = 1009;
        vector<list<pair<int, int>>> bs;
    
        int getBucketIndex(int key){
            return key % bc;
        }
    
        list<pair<int, int>>::iterator findKey(int bi, int key){
            for(auto it = bs[bi].begin(); it != bs[bi].end(); it++){
                if(it->first == key){
                    return it;
                }
            }
            return bs[bi].end();
        }
    
        MyHashMap() : bs(bc) {}
        
        void put(int key, int value) {
            int bi = getBucketIndex(key);
            auto it = findKey(bi, key);
            if(it != bs[bi].end()){
                it->second = value;
            }else{
                bs[bi].emplace_back(key, value);
            }
        }
        
        int get(int key) {
            int bi = getBucketIndex(key);
            auto it = findKey(bi, key);
            if(it != bs[bi].end()){
                return it->second;
            }else{
                return -1;
            }
        }
        
        void remove(int key) {
            int bi = getBucketIndex(key);
            auto it = findKey(bi, key);
            if(it != bs[bi].end()){
                bs[bi].erase(it);
            }
        }
    };
    
    /**
     * Your MyHashMap object will be instantiated and called as such:
     * MyHashMap* obj = new MyHashMap();
     * obj->put(key,value);
     * int param_2 = obj->get(key);
     * obj->remove(key);
     */