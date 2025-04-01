class Solution {
    public:
        unordered_map<string, string> longToShort;
        unordered_map<string, string> shortToLong;
        const string chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int counter = 0;
        string base62Encode(int num){
            string res;
            while(num > 0){
                res.push_back(chars[num % 62]);
                num /= 62;
            }
            reverse(res.begin(), res.end());
            return res.empty() ? "0" : res;
        }
        // Encodes a URL to a shortened URL.
        string encode(string longUrl) {
            if(longToShort.find(longUrl) != longToShort.end()){
                return longToShort[longUrl];
            }
            string shortUrl = base62Encode(counter++);
            longToShort[longUrl] = shortUrl;
            shortToLong[shortUrl] = longUrl;
            return shortUrl;
        }
    
        // Decodes a shortened URL to its original URL.
        string decode(string shortUrl) {
            return shortToLong[shortUrl];
        }
    };
    
    // Your Solution object will be instantiated and called as such:
    // Solution solution;
    // solution.decode(solution.encode(url));