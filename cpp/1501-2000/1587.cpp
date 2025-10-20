#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

struct User {
    std::string name;
    int account;
};

struct Transaction {
    int account;
    int amount;
};

struct UserBalance {
    std::string name;
    int balance;
};

std::vector<UserBalance> findHighBalanceUsers(
    const std::vector<User>& users,
    const std::vector<Transaction>& transactions) {
    
    // Create a map for quick user lookup by account
    std::unordered_map<int, std::string> userMap;
    for (const auto& user : users) {
        userMap[user.account] = user.name;
    }
    
    // Calculate balances per account
    std::unordered_map<int, int> accountBalances;
    for (const auto& transaction : transactions) {
        accountBalances[transaction.account] += transaction.amount;
    }
    
    // Filter users with balance > 10000
    std::vector<UserBalance> result;
    for (const auto& [account, balance] : accountBalances) {
        if (balance > 10000) {
            // Find user name for this account
            auto it = userMap.find(account);
            if (it != userMap.end()) {
                result.push_back({it->second, balance});
            }
        }
    }
    
    return result;
}

// Alternative approach using joint iteration (more similar to SQL JOIN)
std::vector<UserBalance> findHighBalanceUsersJoinApproach(
    const std::vector<User>& users,
    const std::vector<Transaction>& transactions) {
    
    // Group transactions by account first
    std::unordered_map<int, int> accountBalances;
    for (const auto& transaction : transactions) {
        accountBalances[transaction.account] += transaction.amount;
    }
    
    // Join with users and apply having condition
    std::vector<UserBalance> result;
    for (const auto& user : users) {
        auto it = accountBalances.find(user.account);
        if (it != accountBalances.end() && it->second > 10000) {
            result.push_back({user.name, it->second});
        }
    }
    
    return result;
}

// Example usage
int main() {
    // Sample data
    std::vector<User> users = {
        {"Alice", 1},
        {"Bob", 2},
        {"Charlie", 3},
        {"Diana", 4}
    };
    
    std::vector<Transaction> transactions = {
        {1, 5000}, {1, 6000},  // Alice: 11000
        {2, 3000}, {2, 4000},  // Bob: 7000
        {3, 12000},            // Charlie: 12000
        {4, 8000}, {4, 3000}   // Diana: 11000
    };
    
    auto result = findHighBalanceUsers(users, transactions);
    
    std::cout << "name\tbalance" << std::endl;
    for (const auto& user : result) {
        std::cout << user.name << "\t" << user.balance << std::endl;
    }
    
    return 0;
}