#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iomanip>

struct User {
    int user_id;
    // other user fields...
};

struct Register {
    int contest_id;
    int user_id;
    // other registration fields...
};

struct ContestPercentage {
    int contest_id;
    double percentage;
};

int main() {
    // Sample data - in real scenario, this would come from database
    std::vector<User> users = {
        {1}, {2}, {3}, {4}, {5}, {6}  // 6 total users
    };
    
    std::vector<Register> registrations = {
        {1, 1}, {1, 2}, {1, 3},  // contest 1: 3 users
        {2, 1}, {2, 4}, {2, 5}, {2, 6},  // contest 2: 4 users
        {3, 2}, {3, 3},  // contest 3: 2 users
        {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}  // contest 4: 5 users
    };
    
    // Calculate total number of users
    int totalUsers = users.size();
    
    // Group registrations by contest_id and count users per contest
    std::map<int, int> contestUserCount;
    for (const auto& reg : registrations) {
        contestUserCount[reg.contest_id]++;
    }
    
    // Calculate percentage for each contest
    std::vector<ContestPercentage> results;
    for (const auto& [contest_id, user_count] : contestUserCount) {
        double percentage = (user_count * 100.0) / totalUsers;
        results.push_back({contest_id, percentage});
    }
    
    // Sort by percentage (descending) and then by contest_id (ascending)
    std::sort(results.begin(), results.end(), 
        [](const ContestPercentage& a, const ContestPercentage& b) {
            if (std::abs(a.percentage - b.percentage) < 0.001) {
                return a.contest_id < b.contest_id; // contest_id ascending
            }
            return a.percentage > b.percentage; // percentage descending
        });
    
    // Display results (formatted like SQL output)
    std::cout << "contest_id | percentage\n";
    std::cout << "-----------+-----------\n";
    for (const auto& result : results) {
        std::cout << std::setw(10) << result.contest_id << " | "
                  << std::setw(8) << std::fixed << std::setprecision(2) 
                  << result.percentage << "\n";
    }
    
    return 0;
}