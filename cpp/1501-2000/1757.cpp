#include <iostream>
#include <vector>
#include <string>

struct Product {
    int product_id;
    std::string low_fats;
    std::string recyclable;
};

std::vector<int> findEcoFriendlyProducts(const std::vector<Product>& products) {
    std::vector<int> result;
    
    for (const auto& product : products) {
        if (product.low_fats == "Y" && product.recyclable == "Y") {
            result.push_back(product.product_id);
        }
    }
    
    return result;
}

// Example usage:
int main() {
    // Sample data
    std::vector<Product> products = {
        {1, "Y", "Y"},
        {2, "N", "Y"},
        {3, "Y", "N"},
        {4, "Y", "Y"},
        {5, "N", "N"}
    };
    
    // Find eco-friendly products
    std::vector<int> ecoFriendly = findEcoFriendlyProducts(products);
    
    // Print results
    std::cout << "Product IDs of eco-friendly products (low fats and recyclable):\n";
    for (int id : ecoFriendly) {
        std::cout << id << " ";
    }
    std::cout << std::endl;
    
    return 0;
}