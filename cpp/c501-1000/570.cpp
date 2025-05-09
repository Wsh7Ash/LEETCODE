#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

struct Employee {
    int id;
    string name;
    int managerId;
};

vector<string> findManagersWithAtLeastFiveReports(const vector<Employee>& employees) {
    unordered_map<int, int> reportCounts;
    vector<string> result;

    // Count the number of reports for each manager
    for (const auto& emp : employees) {
        if (emp.managerId != -1) {  // Assuming -1 represents NULL in the database
            reportCounts[emp.managerId]++;
        }
    }

    // Find managers with at least 5 reports and collect their names
    for (const auto& emp : employees) {
        if (reportCounts.count(emp.id) && reportCounts[emp.id] >= 5) {
            result.push_back(emp.name);
        }
    }

    return result;
}

int main() {
    // Example usage
    vector<Employee> employees = {
        {101, "John", -1},
        {102, "Dan", 101},
        {103, "James", 101},
        {104, "Amy", 101},
        {105, "Anne", 101},
        {106, "Ron", 101},
        {107, "Michael", 102},
        {108, "Sarah", 103},
        {109, "Emily", 103}
    };

    vector<string> managers = findManagersWithAtLeastFiveReports(employees);

    cout << "Managers with at least 5 direct reports:" << endl;
    for (const auto& name : managers) {
        cout << name << endl;
    }

    return 0;
}