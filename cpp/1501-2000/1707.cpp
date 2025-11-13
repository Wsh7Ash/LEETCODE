class TrieNode{
public:
    TrieNode* children[2];
    TrieNode(){
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    void insert(int num){
        TrieNode* node = root;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(node->children[bit] == nullptr){
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }

    int getMaxXor(int num){
        TrieNode* node = root;
        int maxXor = 0;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            int oppositeBit = 1 - bit;
            if(node->children[oppositeBit] != nullptr){
                maxXor |= (1 << i);
                node = node->children[oppositeBit];
            }else if(node->children[bit] != nullptr){
                node = node->children[bit];
            }
            else{
                return -1;
            }
        }
        return maxXor;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<pair<vector<int>, int>> indexedQueries;
        for(int i = 0; i < queries.size(); i++){
            indexedQueries.push_back({queries[i], i});
        }        
        sort(nums.begin(), nums.end());
        sort(indexedQueries.begin(), indexedQueries.end(), [](const pair<vector<int>, int>& a, const pair<vector<int>,  int>& b){
            return a.first[1] < b.first[1];
        });
        Trie trie;
        vector<int> res(queries.size());
        int numsIndex = 0;
        for(int i = 0; i < indexedQueries.size(); i++){
            int xi = indexedQueries[i].first[0];
            int mi = indexedQueries[i].first[1];
            int queryIndex = indexedQueries[i].second;
            while(numsIndex < nums.size() && nums[numsIndex] <= mi){
                trie.insert(nums[numsIndex]);
                numsIndex++;
            }
            if(numsIndex == 0){
                res[queryIndex] = -1;
            }
            else{
                res[queryIndex] = trie.getMaxXor(xi);
            }
        }
        return res;
    }
};