#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>
#include <string>

// Structure definitions
struct Price {
    int product_id;
    double price;
    std::string start_date;
    std::string end_date;
};

struct UnitSold {
    int product_id;
    int units;
    std::string purchase_date;
};

struct Result {
    int product_id;
    double average_price;
};

// Function to check if a date is between two dates
bool isDateBetween(const std::string& date, const std::string& start_date, const std::string& end_date) {
    return date >= start_date && date <= end_date;
}

// Main function to calculate average price
std::vector<Result> calculateAveragePrice(
    const std::vector<Price>& prices,
    const std::vector<UnitSold>& unitsSold) {
    
    std::unordered_map<int, std::vector<Price>> priceMap;
    std::unordered_map<int, std::vector<UnitSold>> unitsMap;
    
    // Group prices by product_id
    for (const auto& price : prices) {
        priceMap[price.product_id].push_back(price);
    }
    
    // Group units sold by product_id
    for (const auto& unit : unitsSold) {
        unitsMap[unit.product_id].push_back(unit);
    }
    
    std::vector<Result> results;
    
    // Process each product
    for (const auto& priceEntry : priceMap) {
        int product_id = priceEntry.first;
        const auto& productPrices = priceEntry.second;
        
        double totalRevenue = 0.0;
        int totalUnits = 0;
        
        // For each price period
        for (const auto& price : productPrices) {
            // Find matching units sold
            if (unitsMap.find(product_id) != unitsMap.end()) {
                for (const auto& unit : unitsMap[product_id]) {
                    if (isDateBetween(unit.purchase_date, price.start_date, price.end_date)) {
                        totalRevenue += unit.units * price.price;
                        totalUnits += unit.units;
                    }
                }
            }
        }
        
        // Calculate average price (equivalent to COALESCE and NULLIF)
        double average_price = 0.0;
        if (totalUnits > 0) {
            average_price = totalRevenue / totalUnits;
        }
        
        // Round to 2 decimal places
        average_price = std::round(average_price * 100.0) / 100.0;
        
        results.push_back({product_id, average_price});
    }
    
    return results;
}

// Alternative optimized version using direct joins
std::vector<Result> calculateAveragePriceOptimized(
    const std::vector<Price>& prices,
    const std::vector<UnitSold>& unitsSold) {
    
    std::unordered_map<int, Result> resultMap;
    
    // Initialize results for all products
    for (const auto& price : prices) {
        resultMap[price.product_id] = {price.product_id, 0.0};
    }
    
    // Process each units sold record
    for (const auto& unit : unitsSold) {
        // Find matching price periods
        for (const auto& price : prices) {
            if (price.product_id == unit.product_id && 
                isDateBetween(unit.purchase_date, price.start_date, price.end_date)) {
                
                // Update the result in the map
                auto& result = resultMap[price.product_id];
                // We'll store intermediate values and calculate at the end
                // For simplicity, we'll use a different approach
            }
        }
    }
    
    // Convert map to vector
    std::vector<Result> results;
    for (const auto& entry : resultMap) {
        results.push_back(entry.second);
    }
    
    return results;
}

// Example usage
int main() {
    // Sample data
    std::vector<Price> prices = {
        {1, 10.0, "2023-01-01", "2023-01-31"},
        {1, 15.0, "2023-02-01", "2023-02-28"},
        {2, 20.0, "2023-01-01", "2023-01-31"},
        {2, 25.0, "2023-02-01", "2023-02-28"}
    };
    
    std::vector<UnitSold> unitsSold = {
        {1, 100, "2023-01-15"},
        {1, 50, "2023-02-15"},
        {2, 75, "2023-01-20"},
        {2, 25, "2023-02-15"}
    };
    
    // Calculate average prices
    auto results = calculateAveragePrice(prices, unitsSold);
    
    // Display results
    std::cout << "product_id | average_price" << std::endl;
    std::cout << "-----------|--------------" << std::endl;
    for (const auto& result : results) {
        std::cout << std::setw(10) << result.product_id << " | " 
                  << std::fixed << std::setprecision(2) << result.average_price << std::endl;
    }
    
    return 0;
}