#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

struct Person {
    int id;
    string email;
};

vector<string> findDuplicateEmails(vector<Person>& people) {
    unordered_map<string, int> emailCount;
    set<string> result;  // Using a set to store unique duplicate emails

    // Count occurrences of each email
    for (const auto& person : people) {
        emailCount[person.email]++;
    }

    // Collect emails that appear more than once
    for (const auto& entry : emailCount) {
        if (entry.second > 1) {
            result.insert(entry.first);
        }
    }

    return vector<string>(result.begin(), result.end());
}

// Example usage
int main() {
    vector<Person> people = {
        {1, "a@b.com"},
        {2, "c@d.com"},
        {3, "a@b.com"}
    };

    vector<string> duplicates = findDuplicateEmails(people);

    for (const string& email : duplicates) {
        cout << email << endl;
    }

    return 0;
}
