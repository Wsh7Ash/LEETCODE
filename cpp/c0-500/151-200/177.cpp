#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Employee {
public:
    int id;
    int salary;
    Employee(int i, int s) : id(i), salary(s) {}
};

int getNthHighestSalary(vector<Employee>& employees, int n) {
    set<int, greater<int>> unique_salaries;
    
    // Collect distinct salaries
    for (const auto& emp : employees) {
        unique_salaries.insert(emp.salary);
    }

    // If n is greater than available distinct salaries, return -1 (null equivalent)
    if (unique_salaries.size() < n) {
        return -1;  // -1 represents NULL in this case
    }

    // Iterate to find the nth highest salary
    auto it = unique_salaries.begin();
    advance(it, n - 1);
    return *it;
}

int main() {
    vector<Employee> employees = {{1, 100}, {2, 200}, {3, 300}};
    int n = 2;
    int result = getNthHighestSalary(employees, n);

    cout << "getNthHighestSalary(" << n << ") = ";
    if (result == -1)
        cout << "NULL" << endl;
    else
        cout << result << endl;

    return 0;
}
