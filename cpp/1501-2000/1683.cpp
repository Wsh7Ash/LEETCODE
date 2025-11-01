#include <vector>
#include <string>
using namespace std;

struct Tweet {
    int tweet_id;
    string content;
};

class TwitterDatabase {
private:
    vector<Tweet> tweets;

public:
    // Method to add tweets to the database
    void addTweet(int id, const string& content) {
        tweets.push_back({id, content});
    }
    
    // Equivalent of the SQL query: SELECT tweet_id FROM Tweets WHERE LENGTH(content) > 15
    vector<int> getLongTweets() {
        vector<int> result;
        for (const auto& tweet : tweets) {
            if (tweet.content.length() > 15) {
                result.push_back(tweet.tweet_id);
            }
        }
        return result;
    }
    
    // Alternative implementation using modern C++ features
    vector<int> getLongTweetsModern() {
        vector<int> result;
        for (const auto& [id, content] : tweets) {
            if (content.size() > 15) {
                result.push_back(id);
            }
        }
        return result;
    }
};

// Usage example:
int main() {
    TwitterDatabase db;
    
    // Add some sample tweets
    db.addTweet(1, "Short tweet");
    db.addTweet(2, "This is a very long tweet that exceeds 15 characters");
    db.addTweet(3, "Another short one");
    db.addTweet(4, "This one is also quite lengthy and will be selected");
    
    // Get long tweets (equivalent to the SQL query)
    vector<int> longTweets = db.getLongTweets();
    
    return 0;
}