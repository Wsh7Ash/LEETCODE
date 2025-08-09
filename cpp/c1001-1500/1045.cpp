#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> findCustomersWithAllProducts(
        const std::vector<std::pair<int, int>>& customerPurchases,
        const std::vector<int>& allProducts
    ) {
        // Create a set of all available products for quick lookup
        std::unordered_set<int> productSet(allProducts.begin(), allProducts.end());
        int totalProducts = productSet.size();
        
        // Map to store each customer's unique products
        std::unordered_map<int, std::unordered_set<int>> customerProducts;
        
        // Process each customer purchase
        for (const auto& purchase : customerPurchases) {
            int customerId = purchase.first;
            int productKey = purchase.second;
            
            // Only count valid products
            if (productSet.count(productKey)) {
                customerProducts[customerId].insert(productKey);
            }
        }
        
        // Find customers who bought all products
        std::vector<int> result;
        for (const auto& customer : customerProducts) {
            int customerId = customer.first;
            const auto& products = customer.second;
            
            if (products.size() == totalProducts) {
                result.push_back(customerId);
            }
        }
        
        // Sort result for consistent output
        std::sort(result.begin(), result.end());
        return result;
    }
};

// Alternative implementation using just vectors (if you prefer)
class SolutionVector {
public:
    std::vector<int> findCustomersWithAllProducts(
        const std::vector<std::pair<int, int>>& customerPurchases,
        const std::vector<int>& allProducts
    ) {
        int totalProducts = allProducts.size();
        
        // Map customer to their unique products
        std::unordered_map<int, std::unordered_set<int>> customerProducts;
        
        // Build customer product sets
        for (const auto& purchase : customerPurchases) {
            customerProducts[purchase.first].insert(purchase.second);
        }
        
        std::vector<int> result;
        for (const auto& customer : customerProducts) {
            if (customer.second.size() == totalProducts) {
                result.push_back(customer.first);
            }
        }
        
        std::sort(result.begin(), result.end());
        return result;
    }
};

// Example usage and test
#include <iostream>

int main() {
    Solution solution;
    
    // Example data
    // customerPurchases: {customer_id, product_key}
    std::vector<std::pair<int, int>> customerPurchases = {
        {1, 5}, {2, 6}, {3, 5}, {3, 6}, {1, 6}, {1, 7}, {2, 7}, {2, 5}
    };
    
    // All available products
    std::vector<int> allProducts = {5, 6, 7};
    
    std::vector<int> result = solution.findCustomersWithAllProducts(
        customerPurchases, allProducts
    );
    
    std::cout << "Customers who bought all products: ";
    for (int customerId : result) {
        std::cout << customerId << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

// Time Complexity: O(n + m) where n = purchases, m = customers
// Space Complexity: O(n + p) where p = products