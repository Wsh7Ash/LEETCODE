#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct User {
    int user_id;
    string join_date;
};

struct Order {
    int order_id;
    int buyer_id;
    string order_date;
};

struct Result {
    int buyer_id;
    string join_date;
    int orders_in_2019;
};

vector<Result> processOrders(const vector<User>& users, const vector<Order>& orders) {
    // Create a map to count orders per user for 2019
    unordered_map<int, int> orderCounts;
    
    // Count orders from 2019 for each user
    for (const auto& order : orders) {
        if (order.order_date.substr(0, 4) == "2019") {
            orderCounts[order.buyer_id]++;
        }
    }
    
    // Prepare results
    vector<Result> results;
    for (const auto& user : users) {
        Result result;
        result.buyer_id = user.user_id;
        result.join_date = user.join_date;
        result.orders_in_2019 = orderCounts[user.user_id]; // Returns 0 if not found
        
        results.push_back(result);
    }
    
    // Sort by user_id
    sort(results.begin(), results.end(), [](const Result& a, const Result& b) {
        return a.buyer_id < b.buyer_id;
    });
    
    return results;
}

int main() {
    // Example usage
    vector<User> users = {
        {1, "2018-01-01"},
        {2, "2018-02-09"},
        {3, "2018-01-19"},
        {4, "2018-05-21"}
    };
    
    vector<Order> orders = {
        {1, 1, "2019-01-01"},
        {2, 2, "2019-02-11"},
        {3, 3, "2018-12-31"},
        {4, 3, "2019-01-01"},
        {5, 3, "2019-02-11"},
        {6, 4, "2019-06-02"}
    };
    
    vector<Result> results = processOrders(users, orders);
    
    // Print results
    cout << "buyer_id\tjoin_date\torders_in_2019" << endl;
    cout << "----------------------------------------" << endl;
    for (const auto& result : results) {
        cout << result.buyer_id << "\t\t" 
             << result.join_date << "\t" 
             << result.orders_in_2019 << endl;
    }
    
    return 0;
}