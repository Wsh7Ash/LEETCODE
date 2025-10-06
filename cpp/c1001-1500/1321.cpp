#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>
#include <algorithm>

struct Customer {
    std::string visited_on;
    double amount;
};

struct DailyResult {
    std::string visited_on;
    double amount;
    double average_amount;
};

class Solution {
public:
    std::vector<DailyResult> calculateMovingAverage(std::vector<Customer>& customers) {
        // Group by visited_on and sum amounts for each day
        std::map<std::string, double> dailySums;
        for (const auto& customer : customers) {
            dailySums[customer.visited_on] += customer.amount;
        }
        
        // Convert map to vector for easier processing
        std::vector<std::pair<std::string, double>> dailyData;
        for (const auto& entry : dailySums) {
            dailyData.push_back(entry);
        }
        
        // Sort by date to ensure chronological order
        std::sort(dailyData.begin(), dailyData.end(), 
                  [](const auto& a, const auto& b) {
                      return a.first < b.first;
                  });
        
        std::vector<DailyResult> results;
        
        // Calculate 7-day moving average
        for (int i = 6; i < dailyData.size(); i++) {
            double sevenDaySum = 0.0;
            
            // Sum amounts for current day and previous 6 days
            for (int j = i - 6; j <= i; j++) {
                sevenDaySum += dailyData[j].second;
            }
            
            double average = sevenDaySum / 7.0;
            
            results.push_back({
                dailyData[i].first,
                sevenDaySum,
                std::round(average * 100) / 100.0  // Round to 2 decimal places
            });
        }
        
        return results;
    }
};

// Helper function to print results
void printResults(const std::vector<DailyResult>& results) {
    std::cout << std::left << std::setw(12) << "visited_on" 
              << std::setw(12) << "amount" 
              << std::setw(16) << "average_amount" << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    
    for (const auto& result : results) {
        std::cout << std::left << std::setw(12) << result.visited_on
                  << std::setw(12) << std::fixed << std::setprecision(2) << result.amount
                  << std::setw(16) << result.average_amount << std::endl;
    }
}

int main() {
    // Example usage
    std::vector<Customer> customers = {
        {"2023-01-01", 100},
        {"2023-01-01", 200},
        {"2023-01-02", 150},
        {"2023-01-03", 300},
        {"2023-01-04", 250},
        {"2023-01-05", 400},
        {"2023-01-06", 350},
        {"2023-01-07", 200},
        {"2023-01-08", 450},
        {"2023-01-09", 300},
        {"2023-01-10", 500}
    };
    
    Solution solution;
    auto results = solution.calculateMovingAverage(customers);
    
    printResults(results);
    
    return 0;
}