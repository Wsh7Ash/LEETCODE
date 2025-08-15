#include <vector>
#include <unordered_map>
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

// Define the Employee and Project structures
struct Employee {
    int employee_id;
    double experience_years;
};

struct Project {
    int project_id;
    int employee_id;
};

// Function to calculate the average experience years per project
unordered_map<int, double> calculateAverageExperience(
    const vector<Project>& projects,
    const vector<Employee>& employees
) {
    // Create a map from employee_id to experience_years
    unordered_map<int, double> employeeExperience;
    for (const auto& emp : employees) {
        employeeExperience[emp.employee_id] = emp.experience_years;
    }

    // Map to store total experience and count of employees per project
    unordered_map<int, pair<double, int>> projectStats;

    for (const auto& proj : projects) {
        auto it = employeeExperience.find(proj.employee_id);
        if (it != employeeExperience.end()) {
            projectStats[proj.project_id].first += it->second;
            projectStats[proj.project_id].second += 1;
        }
    }

    // Calculate the average for each project
    unordered_map<int, double> averageExperience;
    for (const auto& stat : projectStats) {
        averageExperience[stat.first] = stat.second.first / stat.second.second;
    }

    return averageExperience;
}

int main() {
    // Example data
    vector<Employee> employees = {
        {1, 3.5},
        {2, 2.0},
        {3, 5.5},
        {4, 4.0}
    };

    vector<Project> projects = {
        {1, 1},
        {1, 2},
        {2, 3},
        {2, 4},
        {3, 1}
    };

    // Calculate average experience per project
    auto averageExp = calculateAverageExperience(projects, employees);

    // Print the results
    cout << fixed << setprecision(2);
    for (const auto& avg : averageExp) {
        cout << "Project " << avg.first << ": " << avg.second << " average years" << endl;
    }

    return 0;
}