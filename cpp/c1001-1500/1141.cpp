#include <iostResulteam>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

struct Activity {
    std::string activity_date;
    int user_id;
    // Add other fields as needed
};

struct Result {
    std::string day;
    int active_users;
};

std::vector<Result> getActiveUsers(const std::vector<Activity>& activities) {
    // Date range bounds
    std::string start_date = "2019-06-28";
    std::string end_date = "2019-07-27";
    
    // Map to store unique users per date
    std::map<std::string, std::set<int>> daily_users;
    
    // Filter activities within date range and group by date
    for (const auto& activity : activities) {
        // Check if activity_date is within range
        if (activity.activity_date >= start_date && activity.activity_date <= end_date) {
            daily_users[activity.activity_date].insert(activity.user_id);
        }
    }
    
    // Convert to result format
    std::vector<Result> results;
    for (const auto& [date, users] : daily_users) {
        results.push_back({date, static_cast<int>(users.size())});
    }
    
    // Sort by date (optional, depending on requirements)
    std::sort(results.begin(), results.end(), 
              [](const Result& a, const Result& b) {
                  return a.day < b.day;
              });
    
    return results;
}

// Example usage
int main() {
    // Sample data
    std::vector<Activity> activities = {
        {"2019-06-29", 1},
        {"2019-06-29", 2},
        {"2019-06-29", 1}, // Duplicate user on same day
        {"2019-06-30", 1},
        {"2019-06-30", 3},
        {"2019-07-01", 2},
        {"2019-07-01", 3},
        {"2019-07-01", 4},
        {"2019-05-15", 1}, // Outside date range
        {"2019-08-01", 1}  // Outside date range
    };
    
    auto results = getActiveUsers(activities);
    
    // Print results
    std::cout << "Day\t\tActive Users\n";
    std::cout << "------------------------\n";
    for (const auto& result : results) {
        std::cout << result.day << "\t" << result.active_users << "\n";
    }
    
    return 0;
}