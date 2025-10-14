#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>

// Assuming we have a structure to represent Activities data
struct Activity {
    std::string sell_date;
    std::string product;
};

std::vector<Activity> getActivitiesData() {
    // This function would typically fetch data from a database
    // For demonstration, returning sample data
    return {
        {"2020-05-30", "Headphone"},
        {"2020-06-01", "Pencil"},
        {"2020-06-02", "Mask"},
        {"2020-05-30", "Basketball"},
        {"2020-06-01", "Bible"},
        {"2020-06-02", "Mask"},
        {"2020-05-30", "T-Shirt"}
    };
}

// Structure to hold the result for each sell_date
struct DateResult {
    std::string sell_date;
    int num_sold;
    std::string products;
};

int main() {
    // Get the activities data
    auto activities = getActivitiesData();
    
    // Map to group products by sell_date
    std::map<std::string, std::set<std::string>> dateProducts;
    
    // Group products by sell_date (automatically removes duplicates due to set)
    for (const auto& activity : activities) {
        dateProducts[activity.sell_date].insert(activity.product);
    }
    
    // Convert to result structure
    std::vector<DateResult> results;
    
    for (const auto& [sell_date, products_set] : dateProducts) {
        DateResult result;
        result.sell_date = sell_date;
        result.num_sold = products_set.size();
        
        // Convert set to sorted vector for consistent ordering
        std::vector<std::string> sorted_products(products_set.begin(), products_set.end());
        std::sort(sorted_products.begin(), sorted_products.end());
        
        // Join products with comma separator (equivalent to GROUP_CONCAT)
        std::ostringstream products_stream;
        for (size_t i = 0; i < sorted_products.size(); ++i) {
            if (i > 0) {
                products_stream << ",";
            }
            products_stream << sorted_products[i];
        }
        result.products = products_stream.str();
        
        results.push_back(result);
    }
    
    // Results are automatically sorted by sell_date due to using std::map
    
    // Display results
    std::cout << "sell_date\tnum_sold\tproducts\n";
    std::cout << "----------------------------------------\n";
    for (const auto& result : results) {
        std::cout << result.sell_date << "\t" 
                  << result.num_sold << "\t\t"
                  << result.products << "\n";
    }
    
    return 0;
}