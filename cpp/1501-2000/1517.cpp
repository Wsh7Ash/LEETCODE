#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <algorithm>

struct User {
    int user_id;
    std::string name;
    std::string mail;
};

class UserQuery {
public:
    static std::vector<User> filterLeetcodeUsers(const std::vector<User>& users) {
        std::vector<User> result;
        
        // Regular expression pattern: ^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\.com$
        std::regex pattern("^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\\.com$");
        
        for (const auto& user : users) {
            // Check both conditions:
            // 1. Mail matches the regex pattern
            // 2. Mail contains "@leetcode.com" (case-sensitive due to binary keyword equivalent)
            if (std::regex_match(user.mail, pattern) && 
                containsCaseSensitive(user.mail, "@leetcode.com")) {
                result.push_back(user);
            }
        }
        
        return result;
    }

private:
    // Helper function to perform case-sensitive substring search
    static bool containsCaseSensitive(const std::string& str, const std::string& substr) {
        return str.find(substr) != std::string::npos;
    }
};

// Alternative implementation using only regex (more efficient)
std::vector<User> filterLeetcodeUsersRegexOnly(const std::vector<User>& users) {
    std::vector<User> result;
    
    // Combined regex that handles both conditions:
    // - Starts with letter, followed by allowed characters, ends with @leetcode.com
    // - Case-sensitive matching (default in std::regex)
    std::regex pattern("^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\\.com$");
    
    for (const auto& user : users) {
        if (std::regex_match(user.mail, pattern)) {
            result.push_back(user);
        }
    }
    
    return result;
}

// Example usage and test
int main() {
    // Sample test data
    std::vector<User> users = {
        {1, "John", "john@leetcode.com"},
        {2, "Alice", "alice123@leetcode.com"},
        {3, "Bob", "Bob.leet@leetcode.com"},
        {4, "Charlie", "charlie@LEETCODE.COM"}, // Should not match (case sensitive)
        {5, "David", "david@gmail.com"}, // Should not match (wrong domain)
        {6, "Eve", "1eve@leetcode.com"}, // Should not match (starts with number)
        {7, "Frank", "frank-code@leetcode.com"},
        {8, "Grace", "grace@leetcode.org"}, // Should not match (wrong TLD)
    };
    
    std::cout << "Filtering LeetCode users..." << std::endl;
    std::cout << "============================" << std::endl;
    
    auto filteredUsers = UserQuery::filterLeetcodeUsers(users);
    
    std::cout << "User ID\tName\tMail" << std::endl;
    std::cout << "-------\t----\t----" << std::endl;
    
    for (const auto& user : filteredUsers) {
        std::cout << user.user_id << "\t" << user.name << "\t" << user.mail << std::endl;
    }
    
    return 0;
}