class TweetCounts {
    private:
        unordered_map<string, multiset<int>> tweets;
    
        int getInterval(string freq){
            if(freq == "minute") return 60;
            if(freq == "hour") return 3600;
            if(freq == "day") return 86400;
            return 0;
        }
    
    public:
        TweetCounts() {
            tweets.clear();
        }
        
        void recordTweet(string tweetName, int time) {
            tweets[tweetName].insert(time);
        }
        
        vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
            vector<int> res;
            int interval = getInterval(freq);
    
            for(int i = 0;startTime + i * interval <= endTime; i++){
                int chunkStart = startTime + i * interval;
                int chunkEnd = min(endTime, chunkStart + interval - 1);
    
                auto startIt = tweets[tweetName].lower_bound(chunkStart);
                auto endIt = tweets[tweetName].upper_bound(chunkEnd);
                int count = distance(startIt, endIt);
    
                res.push_back(count);
            }
    
            return res;
        }
    };
    
    /**
     * Your TweetCounts object will be instantiated and called as such:
     * TweetCounts* obj = new TweetCounts();
     * obj->recordTweet(tweetName,time);
     * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
     */