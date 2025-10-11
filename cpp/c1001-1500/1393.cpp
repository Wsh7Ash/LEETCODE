#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

struct StockRecord {
    std::string stock_name;
    std::string operation;
    int price;
};

struct StockResult {
    std::string stock_name;
    int capital_gain_loss;
};

std::vector<StockResult> calculateCapitalGainLoss(const std::vector<StockRecord>& stocks) {
    std::unordered_map<std::string, int> gainLossMap;
    
    // Calculate capital gain/loss for each stock
    for (const auto& record : stocks) {
        if (record.operation == "Sell") {
            gainLossMap[record.stock_name] += record.price;
        } else { // Assuming "Buy" operation
            gainLossMap[record.stock_name] -= record.price;
        }
    }
    
    // Convert map to vector of results
    std::vector<StockResult> results;
    for (const auto& pair : gainLossMap) {
        results.push_back({pair.first, pair.second});
    }
    
    // Sort by capital_gain_loss in descending order
    std::sort(results.begin(), results.end(), 
              [](const StockResult& a, const StockResult& b) {
                  return a.capital_gain_loss > b.capital_gain_loss;
              });
    
    return results;
}

int main() {
    // Sample data - equivalent to the Stocks table
    std::vector<StockRecord> stocks = {
        {"Apple", "Buy", 1000},
        {"Apple", "Sell", 1200},
        {"Google", "Buy", 800},
        {"Google", "Sell", 950},
        {"Apple", "Buy", 500},
        {"Apple", "Sell", 700},
        {"Microsoft", "Buy", 1200},
        {"Microsoft", "Sell", 1100}
    };
    
    // Calculate results
    std::vector<StockResult> results = calculateCapitalGainLoss(stocks);
    
    // Print results in the same format as SQL query
    std::cout << "stock_name | capital_gain_loss" << std::endl;
    std::cout << "-----------|------------------" << std::endl;
    
    for (const auto& result : results) {
        std::cout << result.stock_name << " | " << result.capital_gain_loss << std::endl;
    }
    
    return 0;
}