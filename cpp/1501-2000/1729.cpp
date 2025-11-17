#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

// Assuming we have a Follower structure
struct Follower {
    int user_id;
    int follower_id;
};

std::vector<std::pair<int, int>> countFollowers(const std::vector<Follower>& followers) {
    // Map to store user_id -> followers_count
    std::map<int, int> followersCount;
    
    // Group by user_id and count followers (equivalent to GROUP BY user_id)
    for (const auto& follower : followers) {
        followersCount[follower.user_id]++;
    }
    
    // Convert map to vector of pairs and sort by user_id (already sorted in map)
    // Map automatically maintains ascending order of keys
    std::vector<std::pair<int, int>> result;
    for (const auto& [user_id, count] : followersCount) {
        result.emplace_back(user_id, count);
    }
    
    return result;
}

// Alternative implementation if you want to work with arrays/vectors directly
std::vector<std::pair<int, int>> countFollowersFromData(const std::vector<int>& user_ids, 
                                                       const std::vector<int>& follower_ids) {
    std::map<int, int> followersCount;
    
    // Assuming both vectors are the same size and represent the Followers table
    for (size_t i = 0; i < user_ids.size(); ++i) {
        followersCount[user_ids[i]]++;
    }
    
    std::vector<std::pair<int, int>> result;
    for (const auto& [user_id, count] : followersCount) {
        result.emplace_back(user_id, count);
    }
    
    return result;
}

int main() {
    // Example usage
    std::vector<Follower> followers = {
        {1, 101},
        {1, 102},
        {1, 103},
        {2, 101},
        {2, 104},
        {3, 101},
        {3, 102},
        {3, 103},
        {3, 104}
    };
    
    auto result = countFollowers(followers);
    
    // Print results (equivalent to the SELECT statement)
    std::cout << "user_id\tfollowers_count" << std::endl;
    for (const auto& [user_id, count] : result) {
        std::cout << user_id << "\t" << count << std::endl;
    }
    
    return 0;
}