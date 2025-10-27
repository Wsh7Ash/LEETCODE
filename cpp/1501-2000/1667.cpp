#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

struct User {
    int user_id;
    std::string name;
};

std::string formatName(const std::string& name) {
    if (name.empty()) return name;
    
    std::string formatted = name;
    // Convert first character to uppercase
    formatted[0] = std::toupper(formatted[0]);
    
    // Convert remaining characters to lowercase
    for (size_t i = 1; i < formatted.length(); ++i) {
        formatted[i] = std::tolower(formatted[i]);
    }
    
    return formatted;
}

int main() {
    // Sample user data (in real scenario, this would come from a database)
    std::vector<User> users = {
        {1, "john"},
        {2, "SARAH"},
        {3, "mArY"},
        {4, "pETER"},
        {5, ""}  // edge case: empty name
    };
    
    // Process each user - equivalent to the SELECT statement
    std::vector<User> formattedUsers;
    for (const auto& user : users) {
        formattedUsers.push_back({
            user.user_id,
            formatName(user.name)
        });
    }
    
    // Sort by user_id - equivalent to ORDER BY user_id
    std::sort(formattedUsers.begin(), formattedUsers.end(),
              [](const User& a, const User& b) {
                  return a.user_id < b.user_id;
              });
    
    // Display results
    std::cout << "user_id\tname" << std::endl;
    std::cout << "-------\t----" << std::endl;
    for (const auto& user : formattedUsers) {
        std::cout << user.user_id << "\t" << user.name << std::endl;
    }
    
    return 0;
}