#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

struct SalesPerson {
    int sales_id;
    std::string name;
};

struct Company {
    int com_id;
    std::string name;
};

struct Order {
    int order_id;
    int com_id;
    int sales_id;
    // other order fields...
};

std::vector<std::string> findSalesWithoutRedOrders(
    const std::vector<SalesPerson>& salesPeople,
    const std::vector<Company>& companies,
    const std::vector<Order>& orders) {
    
    // Step 1: Find the com_id for 'RED'
    int red_com_id = -1;
    for (const auto& company : companies) {
        if (company.name == "RED") {
            red_com_id = company.com_id;
            break;
        }
    }
    
    // If 'RED' company doesn't exist, all salespeople qualify
    if (red_com_id == -1) {
        std::vector<std::string> result;
        for (const auto& sp : salesPeople) {
            result.push_back(sp.name);
        }
        return result;
    }
    
    // Step 2: Find sales_ids who have orders with 'RED'
    std::unordered_set<int> salesWithRedOrders;
    for (const auto& order : orders) {
        if (order.com_id == red_com_id) {
            salesWithRedOrders.insert(order.sales_id);
        }
    }
    
    // Step 3: Find salespeople not in the above set
    std::vector<std::string> result;
    for (const auto& sp : salesPeople) {
        if (salesWithRedOrders.find(sp.sales_id) == salesWithRedOrders.end()) {
            result.push_back(sp.name);
        }
    }
    
    return result;
}

int main() {
    // Example data - replace with your actual data
    std::vector<SalesPerson> salesPeople = {
        {1, "John"},
        {2, "Amy"},
        {3, "Mark"},
        {4, "Pam"},
        {5, "Alex"}
    };
    
    std::vector<Company> companies = {
        {1, "RED"},
        {2, "ORANGE"},
        {3, "YELLOW"},
        {4, "GREEN"}
    };
    
    std::vector<Order> orders = {
        {1, 1, 3},  // Order 1: RED, Mark
        {2, 2, 4},  // Order 2: ORANGE, Pam
        {3, 1, 5},  // Order 3: RED, Alex
        {4, 4, 1},  // Order 4: GREEN, John
        {5, 3, 2}   // Order 5: YELLOW, Amy
    };
    
    auto result = findSalesWithoutRedOrders(salesPeople, companies, orders);
    
    // Print results
    std::cout << "Salespersons without RED orders:\n";
    for (const auto& name : result) {
        std::cout << name << "\n";
    }
    
    return 0;
}