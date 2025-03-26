#include <iostream>
#include <vector>
#include <string>
#include <optional>  // For using std::nullopt when no address is found

using namespace std;

// Define the Person struct
struct Person {
    int personId;
    string lastName;
    string firstName;
};

// Define the Address struct
struct Address {
    int personId;
    string city;
    string state;
};

vector<vector<string>> combineTables(const vector<Person>& persons, const vector<Address>& addresses) {
    vector<vector<string>> result;
    
    // Iterate through each person
    for (const auto& person : persons) {
        bool foundAddress = false;
        string city = "NULL";
        string state = "NULL";
        
        // Check if there's a corresponding address for the current person
        for (const auto& address : addresses) {
            if (address.personId == person.personId) {
                city = address.city;
                state = address.state;
                foundAddress = true;
                break;
            }
        }
        
        // Add the person's information and address (or NULL if not found)
        result.push_back({person.firstName, person.lastName, city, state});
    }
    
    return result;
}

int main() {
    // Example data
    vector<Person> persons = {{1, "Wang", "Allen"}, {2, "Alice", "Bob"}};
    vector<Address> addresses = {{1, "New York City", "New York"}, {3, "Leetcode", "California"}};

    // Combine the tables
    vector<vector<string>> result = combineTables(persons, addresses);

    // Output the result
    for (const auto& row : result) {
        for (const auto& value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}
