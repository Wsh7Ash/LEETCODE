class Solution {
    public:
        bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
            unordered_map<int, vector<int>> pieceMap;
            for(const auto& piece : pieces){
                pieceMap[piece[0]] = piece; 
            }
    
            int i = 0;
            int n = arr.size();
    
            while(i < n){
                if(pieceMap.find(arr[i]) == pieceMap.end()){
                    return false;
                }
                vector<int> piece = pieceMap[arr[i]];
                for(int j = 0; j < piece.size(); j++){
                    if(i + j >= n || arr[i + j] != piece[j]){
                        return false;
                    }
                }
                i += piece.size();
            }
            return true;
        }
    };