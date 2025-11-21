#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

struct EmployeeRecord {
    std::string event_day;
    int emp_id;
    int in_time;
    int out_time;
};

struct DailyTotal {
    std::string day;
    int emp_id;
    int total_time;
};

int main() {
    // Sample data - replace this with your actual data source
    std::vector<EmployeeRecord> employees = {
        {"2024-01-01", 1, 480, 1080},  // 8:00 in, 18:00 out (600 minutes)
        {"2024-01-01", 2, 540, 1020},  // 9:00 in, 17:00 out (480 minutes)
        {"2024-01-01", 1, 480, 960},   // 8:00 in, 16:00 out (480 minutes)
        {"2024-01-02", 1, 480, 1080},  // 8:00 in, 18:00 out (600 minutes)
        {"2024-01-02", 2, 600, 1200},  // 10:00 in, 20:00 out (600 minutes)
    };
    
    // Map to store daily totals: key = (emp_id, day), value = total_time
    std::map<std::pair<int, std::string>, int> dailyTotals;
    
    // Calculate total time for each employee per day
    for (const auto& record : employees) {
        auto key = std::make_pair(record.emp_id, record.event_day);
        dailyTotals[key] += (record.out_time - record.in_time);
    }
    
    // Convert map to vector for sorting and output
    std::vector<DailyTotal> results;
    for (const auto& [key, total_time] : dailyTotals) {
        results.push_back({key.second, key.first, total_time});
    }
    
    // Sort by emp_id, then by day (map already maintains order, but we'll sort explicitly)
    std::sort(results.begin(), results.end(), 
        [](const DailyTotal& a, const DailyTotal& b) {
            if (a.emp_id != b.emp_id) {
                return a.emp_id < b.emp_id;
            }
            return a.day < b.day;
        });
    
    // Output the results
    std::cout << "day\t\temp_id\ttotal_time\n";
    std::cout << "--------------------------------\n";
    for (const auto& result : results) {
        std::cout << result.day << "\t" << result.emp_id << "\t" << result.total_time << "\n";
    }
    
    return 0;
}