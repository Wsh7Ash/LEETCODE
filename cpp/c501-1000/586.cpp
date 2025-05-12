#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

struct Order {
    int order_number;
    int customer_number;
    // other order fields...
};

int findCustomerWithMostOrders(const std::vector<Order>& orders) {
    if (orders.empty()) {
        return -1; // or handle error appropriately
    }

    // Count orders per customer
    std::unordered_map<int, int> orderCounts;
    for (const auto& order : orders) {
        orderCounts[order.customer_number]++;
    }

    // Find customer with maximum orders
    auto maxCustomer = std::max_element(
        orderCounts.begin(),
        orderCounts.end(),
        [](const auto& a, const auto& b) {
            return a.second < b.second;
        }
    );

    return maxCustomer->first;
}

int main() {
    // Example usage
    std::vector<Order> orders = {
        {1, 100},
        {2, 101},
        {3, 100},
        {4, 102},
        {5, 100},
        {6, 101}
    };

    int topCustomer = findCustomerWithMostOrders(orders);
    std::cout << "Customer with most orders: " << topCustomer << std::endl;

    return 0;
}