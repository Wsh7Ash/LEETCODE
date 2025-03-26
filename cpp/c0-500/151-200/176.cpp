#include <iostream>
#include <vector>
#include <set>
#include <optional>

using namespace std;

optional<int> secondHighestSalary(const vector<int>& salaries) {
    set<int> uniqueSalaries(salaries.begin(), salaries.end());  // Remove duplicates by using a set
    
    // If there are less than two unique salaries, return null
    if (uniqueSalaries.size() < 2) {
        return nullopt;
    }
    
    // Get the second highest salary
    auto it = uniqueSalaries.end();
    --it;  // Move to the highest salary
    --it;  // Move to the second highest salary
    
    return *it;
}

int main() {
    vector<int> salaries1 = {100, 200, 300};
    vector<int> salaries2 = {100};
    
    // Example 1
    auto result1 = secondHighestSalary(salaries1);
    if (result1.has_value()) {
        cout << "Second highest salary: " << result1.value() << endl;
    } else {
        cout << "Second highest salary: null" << endl;
    }
    
    // Example 2
    auto result2 = secondHighestSalary(salaries2);
    if (result2.has_value()) {
        cout << "Second highest salary: " << result2.value() << endl;
    } else {
        cout << "Second highest salary: null" << endl;
    }
    
    return 0;
}
