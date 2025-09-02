class SnapshotArray {
private:
    vector<map<int, int>> history;
    int curSnapId;

public:
    SnapshotArray(int length) {
        history.resize(length);
        curSnapId = 0;
        for(int i = 0; i <  length; i++){
            history[i][0] = 0;
        }    
    }
    
    void set(int index, int val) {
        history[index][curSnapId] = val;
    }
    
    int snap() {
        return curSnapId++;
    }
    
    int get(int index, int snap_id) {
        auto& snapMap = history[index];
        auto it = snapMap.upper_bound(snap_id);
        if(it == snapMap.begin()) return 0;
        it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */