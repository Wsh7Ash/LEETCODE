class TreeAncestor {

    private:
        vector<vector<int>> lift;
        int maxPower;
    
    public:
        TreeAncestor(int n, vector<int>& parent) {
            maxPower = ceil(log2(n)) + 1;
            lift.resize(n, vector<int>(maxPower, -1));
    
            for(int i = 0; i < n; i++){
                lift[i][0] = parent[i];
            }
    
            for(int power = 1; power < maxPower; power++){
                for(int node = 0; node < n; node++){
                    int prevAncestor = lift[node][power-1];
                    if(prevAncestor != -1){
                        lift[node][power] = lift[prevAncestor][power-1];
                    } 
                }
            }
        }
        
        int getKthAncestor(int node, int k) {
            if(node == -1) return -1;
            for(int power = 0; power < maxPower; power++){
                if(k & (1 << power)){
                    node = lift[node][power];
                    if(node == -1) return -1;
                }
            }
            return node;
        }
    };
    
    /**
     * Your TreeAncestor object will be instantiated and called as such:
     * TreeAncestor* obj = new TreeAncestor(n, parent);
     * int param_1 = obj->getKthAncestor(node,k);
     */