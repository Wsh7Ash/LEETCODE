#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iomanip>

struct DepartmentRecord {
    int id;
    std::string month;
    int revenue;
};

class DepartmentPivot {
private:
    std::vector<DepartmentRecord> records;
    
    // Helper function to get month index (0-11)
    int getMonthIndex(const std::string& month) {
        static const std::vector<std::string> months = {
            "Jan", "Feb", "Mar", "Apr", "May", "Jun",
            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
        };
        
        auto it = std::find(months.begin(), months.end(), month);
        if (it != months.end()) {
            return std::distance(months.begin(), it);
        }
        return -1;
    }

public:
    void addRecord(int id, const std::string& month, int revenue) {
        records.push_back({id, month, revenue});
    }

    void generatePivotReport() {
        // Map to store revenue by id and month
        std::map<int, std::vector<int>> pivotData;
        
        // Initialize all months to 0 for each id
        for (const auto& record : records) {
            if (pivotData.find(record.id) == pivotData.end()) {
                pivotData[record.id] = std::vector<int>(12, 0);
            }
        }
        
        // Fill the revenue values
        for (const auto& record : records) {
            int monthIndex = getMonthIndex(record.month);
            if (monthIndex != -1) {
                pivotData[record.id][monthIndex] = record.revenue;
            }
        }
        
        // Print the header
        std::cout << std::setw(5) << "id" 
                  << std::setw(10) << "Jan_Revenue"
                  << std::setw(10) << "Feb_Revenue"
                  << std::setw(10) << "Mar_Revenue"
                  << std::setw(10) << "Apr_Revenue"
                  << std::setw(10) << "May_Revenue"
                  << std::setw(10) << "Jun_Revenue"
                  << std::setw(10) << "Jul_Revenue"
                  << std::setw(10) << "Aug_Revenue"
                  << std::setw(10) << "Sep_Revenue"
                  << std::setw(10) << "Oct_Revenue"
                  << std::setw(10) << "Nov_Revenue"
                  << std::setw(10) << "Dec_Revenue" << std::endl;
        
        // Print the data
        for (const auto& entry : pivotData) {
            std::cout << std::setw(5) << entry.first;
            
            for (int revenue : entry.second) {
                std::cout << std::setw(10) << revenue;
            }
            
            std::cout << std::endl;
        }
    }
};

int main() {
    DepartmentPivot dp;
    
    // Sample data - similar to what would be in the database
    dp.addRecord(1, "Jan", 8000);
    dp.addRecord(1, "Feb", 7000);
    dp.addRecord(1, "Mar", 6000);
    dp.addRecord(2, "Jan", 9000);
    dp.addRecord(2, "Feb", 8000);
    dp.addRecord(2, "Mar", 7000);
    dp.addRecord(3, "Feb", 10000);
    dp.addRecord(3, "Mar", 4000);
    
    std::cout << "Department Revenue Pivot Report:" << std::endl;
    std::cout << "=================================" << std::endl;
    dp.generatePivotReport();
    
    return 0;
}