#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

struct Order {
    int product_id;
    std::string order_date;
    int unit;
};

struct Product {
    int product_id;
    std::string product_name;
};

struct Result {
    std::string product_name;
    int unit;
};

class Solution {
public:
    std::vector<Result> getProductsWithAtLeast100Units(std::vector<Product>& products, std::vector<Order>& orders) {
        // Filter orders for February 2020
        std::vector<Order> febOrders;
        for (const auto& order : orders) {
            if (order.order_date >= "2020-02-01" && order.order_date < "2020-03-01") {
                febOrders.push_back(order);
            }
        }
        
        // Create product lookup map
        std::unordered_map<int, std::string> productMap;
        for (const auto& product : products) {
            productMap[product.product_id] = product.product_name;
        }
        
        // Calculate total units per product
        std::unordered_map<int, int> productUnits;
        for (const auto& order : febOrders) {
            productUnits[order.product_id] += order.unit;
        }
        
        // Prepare results with HAVING condition (unit >= 100)
        std::vector<Result> results;
        for (const auto& [product_id, total_units] : productUnits) {
            if (total_units >= 100 && productMap.find(product_id) != productMap.end()) {
                results.push_back({productMap[product_id], total_units});
            }
        }
        
        // Sort by product_name
        std::sort(results.begin(), results.end(), 
                  [](const Result& a, const Result& b) {
                      return a.product_name < b.product_name;
                  });
        
        return results;
    }
};

// Alternative implementation using a more SQL-like approach with joins
class Solution2 {
public:
    std::vector<Result> getProductsWithAtLeast100Units(std::vector<Product>& products, std::vector<Order>& orders) {
        std::unordered_map<int, std::string> productMap;
        for (const auto& product : products) {
            productMap[product.product_id] = product.product_name;
        }
        
        // Group by product_id and sum units for February 2020
        std::unordered_map<int, int> productUnits;
        for (const auto& order : orders) {
            if (order.order_date >= "2020-02-01" && order.order_date < "2020-03-01") {
                productUnits[order.product_id] += order.unit;
            }
        }
        
        std::vector<Result> results;
        for (const auto& [product_id, total_units] : productUnits) {
            if (total_units >= 100) {
                auto it = productMap.find(product_id);
                if (it != productMap.end()) {
                    results.push_back({it->second, total_units});
                }
            }
        }
        
        // ORDER BY product_name
        std::sort(results.begin(), results.end(),
                  [](const Result& a, const Result& b) {
                      return a.product_name < b.product_name;
                  });
        
        return results;
    }
};

// Helper function to print results
void printResults(const std::vector<Result>& results) {
    std::cout << std::left << std::setw(20) << "product_name" 
              << std::setw(10) << "unit" << std::endl;
    std::cout << std::string(30, '-') << std::endl;
    
    for (const auto& result : results) {
        std::cout << std::left << std::setw(20) << result.product_name
                  << std::setw(10) << result.unit << std::endl;
    }
}

int main() {
    // Example test data
    std::vector<Product> products = {
        {1, "Leetcode Solutions"},
        {2, "Jewels of Stringology"},
        {3, "HP"},
        {4, "Lenovo"}
    };
    
    std::vector<Order> orders = {
        {1, "2020-02-05", 60},
        {1, "2020-02-10", 70},
        {2, "2020-01-18", 30},
        {2, "2020-02-11", 80},
        {3, "2020-02-17", 120},
        {3, "2020-02-24", 50},
        {4, "2020-03-01", 20},
        {4, "2020-02-22", 30}
    };
    
    Solution solution;
    auto results = solution.getProductsWithAtLeast100Units(products, orders);
    
    std::cout << "Products with at least 100 units in February 2020:\n";
    printResults(results);
    
    return 0;
}