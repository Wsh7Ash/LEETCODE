#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

struct Activity {
    int player_id;
    int device_id;
    std::string event_date;  // Using string to represent date for simplicity
    int games_played;
};

std::vector<std::pair<int, std::string>> findFirstLogin(const std::vector<Activity>& activities) {
    // Map to store player_id and their earliest login date
    std::unordered_map<int, std::string> firstLogins;
    
    // Iterate through all activities
    for (const auto& activity : activities) {
        // If player not in map yet, add them
        // If player exists, update only if current date is earlier
        if (firstLogins.find(activity.player_id) == firstLogins.end()) {
            firstLogins[activity.player_id] = activity.event_date;
        } else {
            // Compare dates and keep the earlier one
            if (activity.event_date < firstLogins[activity.player_id]) {
                firstLogins[activity.player_id] = activity.event_date;
            }
        }
    }
    
    // Convert map to vector of pairs for return
    std::vector<std::pair<int, std::string>> result;
    for (const auto& entry : firstLogins) {
        result.push_back({entry.first, entry.second});
    }
    
    return result;
}

// Example usage:
int main() {
    std::vector<Activity> activities = {
        {1, 2, "2016-03-01", 5},
        {1, 2, "2016-05-02", 6},
        {2, 3, "2017-06-25", 1},
        {3, 1, "2016-03-02", 0},
        {3, 4, "2018-07-03", 5}
    };
    
    auto result = findFirstLogin(activities);
    
    // Print results
    for (const auto& entry : result) {
        std::cout << "player_id: " << entry.first 
                  << ", first_login: " << entry.second << std::endl;
    }
    
    return 0;
}