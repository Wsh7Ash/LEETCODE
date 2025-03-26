#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Employee {
    int id;
    string name;
    int salary;
    int managerId;
};

vector<string> findEmployees(vector<Employee>& employees) {
    unordered_map<int, int> managerSalary; // Map to store managerId -> salary
    vector<string> result;

    // Store salaries of managers
    for (const auto& emp : employees) {
        managerSalary[emp.id] = emp.salary;
    }

    // Find employees who earn more than their manager
    for (const auto& emp : employees) {
        if (emp.managerId != -1 && managerSalary.count(emp.managerId) && emp.salary > managerSalary[emp.managerId]) {
            result.push_back(emp.name);
        }
    }

    return result;
}

// Example usage
int main() {
    vector<Employee> employees = {
        {1, "Joe", 70000, 3},
        {2, "Henry", 80000, 4},
        {3, "Sam", 60000, -1},  // Null manager represented as -1
        {4, "Max", 90000, -1}
    };

    vector<string> result = findEmployees(employees);
    for (const string& name : result) {
        cout << name << endl;
    }

    return 0;
}
