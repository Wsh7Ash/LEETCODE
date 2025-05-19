#include <iostream>
#include <vector>
#include <string>

struct Salary {
    int id; // Assuming id as a primary key
    std::string sex;
};

void updateSex(std::vector<Salary>& salaries) {
    for (auto& salary : salaries) {
        if (salary.sex == "m") {
            salary.sex = "f";
        } else if (salary.sex == "f") {
            salary.sex = "m";
        }
    }
}

int main() {
    // Example input: simulating the Salary table
    std::vector<Salary> salaries = {
        {1, "m"},
        {2, "f"},
        {3, "m"},
        {4, "f"}
    };
    
    // Process the salaries
    updateSex(salaries);
    
    // Output the result
    std::cout << "id\tsex\n";
    for (const auto& salary : salaries) {
        std::cout << salary.id << "\t" << salary.sex << "\n";
    }
    
    return 0;
}