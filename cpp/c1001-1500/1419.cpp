class Solution {
    public:
        int minNumberOfFrogs(string croakOfFrogs) {
            unordered_map<char, int> count;
            int frogs = 0;
            int maxFrogs = 0;
            for(char ch :  croakOfFrogs) {
                count[ch]++;
                if(!(count['c'] >= count['r'] &&
                     count['r'] >= count['o'] && 
                     count['o'] >= count['a'] && 
                     count['a'] >= count['k'])){
                    return -1;
                }
    
                if(ch == 'c'){
                    frogs++;
                    maxFrogs = max(maxFrogs, frogs);
                }else if(ch == 'k'){
                    frogs--;
                }
            }
            return (frogs == 0) ? maxFrogs : -1;
        }
    };