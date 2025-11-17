#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cmath>

struct Employee {
    int employee_id;
    std::string name;
    int age;
    int reports_to;
};

struct ManagerReport {
    int employee_id;
    std::string name;
    int reports_count;
    int average_age;
};

std::vector<ManagerReport> getManagerReports(const std::vector<Employee>& employees) {
    // Group employees by their manager
    std::unordered_map<int, std::vector<Employee>> reportsByManager;
    
    for (const auto& emp : employees) {
        if (emp.reports_to != 0) { // 0 or -1 could represent no manager
            reportsByManager[emp.reports_to].push_back(emp);
        }
    }
    
    std::vector<ManagerReport> result;
    
    // Process each manager who has reports
    for (const auto& [manager_id, reports] : reportsByManager) {
        // Find the manager's details
        auto manager_it = std::find_if(employees.begin(), employees.end(),
            [manager_id](const Employee& emp) { return emp.employee_id == manager_id; });
        
        if (manager_it != employees.end()) {
            int total_age = 0;
            int count = reports.size();
            
            // Calculate total age of reports
            for (const auto& report : reports) {
                total_age += report.age;
            }
            
            // Calculate average age (rounded)
            int average_age = std::round(static_cast<double>(total_age) / count);
            
            result.push_back({
                manager_it->employee_id,
                manager_it->name,
                count,
                average_age
            });
        }
    }
    
    // Sort by employee_id
    std::sort(result.begin(), result.end(),
        [](const ManagerReport& a, const ManagerReport& b) {
            return a.employee_id < b.employee_id;
        });
    
    return result;
}

// Example usage
int main() {
    // Sample data
    std::vector<Employee> employees = {
        {1, "Michael", 45, 0},
        {2, "Alice", 38, 1},
        {3, "Bob", 42, 1},
        {4, "Charlie", 29, 1},
        {5, "David", 35, 2},
        {6, "Eve", 28, 2}
    };
    
    auto managerReports = getManagerReports(employees);
    
    // Print results
    std::cout << "employee_id | name      | reports_count | average_age\n";
    std::cout << "------------|-----------|---------------|------------\n";
    
    for (const auto& report : managerReports) {
        std::cout << report.employee_id << "           | " 
                  << report.name << "    | " 
                  << report.reports_count << "             | " 
                  << report.average_age << std::endl;
    }
    
    return 0;
}