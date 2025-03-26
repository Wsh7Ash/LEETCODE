#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

struct Person {
    int id;
    std::string email;
};

int main() {
    std::vector<Person> people = {
        {1, "john@example.com"},
        {2, "bob@example.com"},
        {3, "john@example.com"}
    };

    std::unordered_map<std::string, int> emailMap;

    // Iterate over the records
    for (const auto& person : people) {
        if (emailMap.find(person.email) == emailMap.end()) {
            // If the email is not in the map, add it with its id
            emailMap[person.email] = person.id;
        } else {
            // If the email already exists, keep the smallest id
            emailMap[person.email] = std::min(emailMap[person.email], person.id);
        }
    }

    // Output the final result (after removing duplicates)
    for (const auto& entry : emailMap) {
        std::cout << "id: " << entry.second << ", email: " << entry.first << std::endl;
    }

    return 0;
}
