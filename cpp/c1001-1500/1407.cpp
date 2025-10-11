#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

struct User {
    int id;
    std::string name;
};

struct Ride {
    int id;
    int user_id;
    int distance;
};

struct UserDistance {
    std::string name;
    int travelled_distance;
};

// Function to get user data (simulating database query)
std::vector<User> getUsers() {
    return {
        {1, "Alice"},
        {2, "Bob"},
        {3, "Charlie"},
        {4, "David"}
    };
}

// Function to get ride data (simulating database query)
std::vector<Ride> getRides() {
    return {
        {1, 1, 100},
        {2, 1, 200},
        {3, 2, 150},
        {4, 3, 300},
        {5, 3, 50},
        {6, 3, 100}
        // User 4 has no rides
    };
}

int main() {
    // Get data from our "database"
    std::vector<User> users = getUsers();
    std::vector<Ride> rides = getRides();
    
    // Create a map to store total distance for each user
    std::unordered_map<int, int> userDistances;
    
    // Initialize all users with 0 distance
    for (const auto& user : users) {
        userDistances[user.id] = 0;
    }
    
    // Calculate total distance for each user
    for (const auto& ride : rides) {
        userDistances[ride.user_id] += ride.distance;
    }
    
    // Create result vector with user names and distances
    std::vector<UserDistance> results;
    for (const auto& user : users) {
        results.push_back({user.name, userDistances[user.id]});
    }
    
    // Sort results: first by distance descending, then by name ascending
    std::sort(results.begin(), results.end(), 
        [](const UserDistance& a, const UserDistance& b) {
            if (a.travelled_distance != b.travelled_distance) {
                return a.travelled_distance > b.travelled_distance; // desc by distance
            }
            return a.name < b.name; // asc by name
        });
    
    // Print results (similar to SQL output)
    std::cout << "name\ttravelled_distance" << std::endl;
    std::cout << "----\t------------------" << std::endl;
    for (const auto& result : results) {
        std::cout << result.name << "\t" << result.travelled_distance << std::endl;
    }
    
    return 0;
}