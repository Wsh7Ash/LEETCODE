class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> c;
        for(int a : answers){
            c[a]++;
        }      
        int t = 0;
        for(auto& [a, n] : c){
            int gs = a + 1;
            int g = (n + gs - 1) / gs;

            t += g * gs;
        }
        return t;
    }
};