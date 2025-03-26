#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

// Structure for Employee table
struct Employee {
    int id;
    string name;
    int salary;
    int departmentId;
};

// Structure for Department table
struct Department {
    int id;
    string name;
};

// Function to get top 3 unique salary earners per department
vector<tuple<string, string, int>> departmentTopThreeSalaries(vector<Employee>& employees, vector<Department>& departments) {
    unordered_map<int, string> departmentMap;
    unordered_map<int, vector<Employee>> deptEmployees;
    
    // Map departmentId to department name
    for (const auto& dept : departments) {
        departmentMap[dept.id] = dept.name;
    }

    // Group employees by department
    for (const auto& emp : employees) {
        deptEmployees[emp.departmentId].push_back(emp);
    }

    vector<tuple<string, string, int>> result;

    // Process each department
    for (auto& [deptId, empList] : deptEmployees) {
        // Sort employees by salary (descending order)
        sort(empList.begin(), empList.end(), [](const Employee& a, const Employee& b) {
            return a.salary > b.salary;
        });

        // Extract top 3 unique salaries
        set<int> uniqueSalaries;
        int count = 0;

        for (const auto& emp : empList) {
            if (uniqueSalaries.insert(emp.salary).second) { // Insert salary and check if it's unique
                result.emplace_back(departmentMap[deptId], emp.name, emp.salary);
                count++;
            }
            if (count == 3) break; // Stop after getting top 3 unique salaries
        }
    }

    return result;
}

// Example usage
int main() {
    vector<Employee> employees = {
        {1, "Joe", 85000, 1}, {2, "Henry", 80000, 2}, {3, "Sam", 60000, 2},
        {4, "Max", 90000, 1}, {5, "Janet", 69000, 1}, {6, "Randy", 85000, 1},
        {7, "Will", 70000, 1}
    };

    vector<Department> departments = {
        {1, "IT"}, {2, "Sales"}
    };

    vector<tuple<string, string, int>> result = departmentTopThreeSalaries(employees, departments);

    for (const auto& row : result) {
        cout << get<0>(row) << " | " << get<1>(row) << " | " << get<2>(row) << endl;
    }

    return 0;
}
