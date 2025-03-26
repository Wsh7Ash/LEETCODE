#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Structure for Customers table
struct Customer {
    int id;
    string name;
};

// Structure for Orders table
struct Order {
    int id;
    int customerId;
};

vector<string> findCustomersWithoutOrders(vector<Customer>& customers, vector<Order>& orders) {
    unordered_set<int> customersWithOrders;
    vector<string> result;

    // Store all customers who have placed an order
    for (const auto& order : orders) {
        customersWithOrders.insert(order.customerId);
    }

    // Find customers who are not in the customersWithOrders set
    for (const auto& customer : customers) {
        if (customersWithOrders.find(customer.id) == customersWithOrders.end()) {
            result.push_back(customer.name);
        }
    }

    return result;
}

// Example usage
int main() {
    vector<Customer> customers = {
        {1, "Joe"}, {2, "Henry"}, {3, "Sam"}, {4, "Max"}
    };

    vector<Order> orders = {
        {1, 3}, {2, 1}
    };

    vector<string> customersWithoutOrders = findCustomersWithoutOrders(customers, orders);

    for (const string& customer : customersWithoutOrders) {
        cout << customer << endl;
    }

    return 0;
}
