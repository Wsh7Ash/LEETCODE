class RangeModule {
    public:
        struct Interval{
            int left;
            int right;
            Interval(int l, int r) : left(l), right(r){}
            
            bool operator<(const Interval& other) const{
                if (left != other.left) {
                    return left < other.left;
                }
                return right < other.right;
            }
        };
        
        set<Interval> intervals;
    
        RangeModule() {}
        
        void addRange(int left, int right) {
            vector<set<Interval>::iterator> toErase;
            
            for (auto it = intervals.begin(); it != intervals.end(); ++it) {
                if (it->right >= left && it->left <= right) {
                    left = min(left, it->left);
                    right = max(right, it->right);
                    toErase.push_back(it);
                }
            }
            
            for (auto it : toErase) {
                intervals.erase(it);
            }
            
            intervals.insert(Interval(left, right));
        }
        
        bool queryRange(int left, int right) {
            for (const auto& interval : intervals) {
                if (interval.left <= left && interval.right >= right) {
                    return true;
                }
            }
            return false;
        }
        
        void removeRange(int left, int right) {
            vector<set<Interval>::iterator> toErase;
            vector<Interval> toAdd;
            
            for (auto it = intervals.begin(); it != intervals.end(); ++it) {
                if (it->right > left && it->left < right) {
                    toErase.push_back(it);
                    
                    if (it->left < left) {
                        toAdd.push_back(Interval(it->left, left));
                    }
                    
                    if (it->right > right) {
                        toAdd.push_back(Interval(right, it->right));
                    }
                }
            }
            
            for (auto it : toErase) {
                intervals.erase(it);
            }
            
            for (const auto& interval : toAdd) {
                intervals.insert(interval);
            }
        }
    };
    
    /**
     * Your RangeModule object will be instantiated and called as such:
     * RangeModule* obj = new RangeModule();
     * obj->addRange(left,right);
     * bool param_2 = obj->queryRange(left,right);
     * obj->removeRange(left,right);
     */