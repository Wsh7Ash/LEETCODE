#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

struct Product {
    int product_id;
    int new_price;
    string change_date;
};

struct Result {
    int product_id;
    int price;
};

vector<Result> getPrices(const vector<Product>& products, const string& target_date) {
    // Group products by product_id
    unordered_map<int, vector<Product>> productMap;
    set<int> allProductIds;
    
    for (const auto& product : products) {
        productMap[product.product_id].push_back(product);
        allProductIds.insert(product.product_id);
    }
    
    vector<Result> results;
    
    // For each product, find the most recent price change before or on target_date
    for (int product_id : allProductIds) {
        const auto& productChanges = productMap[product_id];
        
        // Filter changes that occurred on or before target_date
        vector<Product> validChanges;
        for (const auto& change : productChanges) {
            if (change.change_date <= target_date) {
                validChanges.push_back(change);
            }
        }
        
        Result result;
        result.product_id = product_id;
        
        if (validChanges.empty()) {
            // No valid changes found, use default price 10
            result.price = 10;
        } else {
            // Find the most recent change (max change_date)
            auto mostRecent = *max_element(validChanges.begin(), validChanges.end(),
                [](const Product& a, const Product& b) {
                    return a.change_date < b.change_date;
                });
            result.price = mostRecent.new_price;
        }
        
        results.push_back(result);
    }
    
    // Sort by product_id
    sort(results.begin(), results.end(), [](const Result& a, const Result& b) {
        return a.product_id < b.product_id;
    });
    
    return results;
}

int main() {
    // Example data
    vector<Product> products = {
        {1, 20, "2019-08-14"},
        {1, 30, "2019-08-15"},
        {1, 35, "2019-08-16"},
        {2, 50, "2019-08-14"},
        {2, 45, "2019-08-17"}, // After target date, should be ignored
        {3, 40, "2019-08-18"}, // After target date, should be ignored
        {4, 60, "2019-08-13"}
    };
    
    string target_date = "2019-08-16";
    
    vector<Result> results = getPrices(products, target_date);
    
    // Print results
    cout << "product_id\tprice" << endl;
    cout << "-------------------" << endl;
    for (const auto& result : results) {
        cout << result.product_id << "\t\t" << result.price << endl;
    }
    
    return 0;
}