class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int wordlen = words[0].size();
        int wordCount = words.size();
        int totallen = wordlen * wordCount;

        if(s.size() < totallen) return result;

        unordered_map<string, int> wordFreq;
        for(string word : words) wordFreq[word]++;

        for(int i = 0; i < wordlen; i++){
            unordered_map<string, int> seen;
            int left = i;
            int right = i;
            int count = 0;

            while(right + wordlen <= s.size()){
                string word = s.substr(right, wordlen);
                right += wordlen;

                if(wordFreq.find(word) != wordFreq.end()){
                    seen[word]++;
                    count++;

                    while(seen[word] > wordFreq[word]){
                        string leftWord = s.substr(left, wordlen);
                        seen[leftWord]--;
                        count--;
                        left += wordlen;
                    }
                    if(count == wordCount) result.push_back(left);
                }else{
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};