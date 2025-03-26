#include <iostream>
#include <vector>
#include <unordered_map>
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

// Function to find employees with the highest salary in each department
vector<tuple<string, string, int>> departmentHighestSalary(vector<Employee>& employees, vector<Department>& departments) {
    unordered_map<int, string> departmentMap;
    unordered_map<int, int> maxSalary;
    unordered_map<int, vector<string>> topEmployees;
    
    // Map departmentId to department name
    for (const auto& dept : departments) {
        departmentMap[dept.id] = dept.name;
    }

    // Find the highest salary per department
    for (const auto& emp : employees) {
        if (maxSalary.find(emp.departmentId) == maxSalary.end() || emp.salary > maxSalary[emp.departmentId]) {
            maxSalary[emp.departmentId] = emp.salary;
            topEmployees[emp.departmentId] = {emp.name}; // Reset list with new top salary
        } else if (emp.salary == maxSalary[emp.departmentId]) {
            topEmployees[emp.departmentId].push_back(emp.name); // Add to list if same top salary
        }
    }

    // Prepare result
    vector<tuple<string, string, int>> result;
    for (const auto& entry : maxSalary) {
        int deptId = entry.first;
        int salary = entry.second;
        for (const auto& empName : topEmployees[deptId]) {
            result.emplace_back(departmentMap[deptId], empName, salary);
        }
    }
    
    return result;
}

// Example usage
int main() {
    vector<Employee> employees = {
        {1, "Joe", 70000, 1}, {2, "Jim", 90000, 1}, {3, "Henry", 80000, 2},
        {4, "Sam", 60000, 2}, {5, "Max", 90000, 1}
    };

    vector<Department> departments = {
        {1, "IT"}, {2, "Sales"}
    };

    vector<tuple<string, string, int>> result = departmentHighestSalary(employees, departments);

    for (const auto& row : result) {
        cout << get<0>(row) << " | " << get<1>(row) << " | " << get<2>(row) << endl;
    }

    return 0;
}
