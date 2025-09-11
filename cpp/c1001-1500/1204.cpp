#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class QueueProcessor {
private:
    struct Person {
        int id;
        string name;
        int weight;
        int turn;
        int cumulativeWeight;
        
        Person(int id, const string& name, int weight, int turn) 
            : id(id), name(name), weight(weight), turn(turn), cumulativeWeight(0) {}
    };
    
    vector<Person> persons;
    
public:
    void addPerson(int id, const string& name, int weight, int turn) {
        persons.emplace_back(id, name, weight, turn);
    }
    
    string getLastPersonUnderLimit(int maxWeight = 1000) {
        // Sort by turn
        sort(persons.begin(), persons.end(), [](const Person& a, const Person& b) {
            return a.turn < b.turn;
        });
        
        // Calculate cumulative weights
        int cumulative = 0;
        for (auto& person : persons) {
            cumulative += person.weight;
            person.cumulativeWeight = cumulative;
        }
        
        // Find the last valid person
        string result;
        for (const auto& person : persons) {
            if (person.cumulativeWeight <= maxWeight) {
                result = person.name;
            }
        }
        
        return result;
    }
    
    void clear() {
        persons.clear();
    }
};

int main() {
    QueueProcessor processor;
    
    // Add persons to the queue
    processor.addPerson(5, "Alice", 250, 1);
    processor.addPerson(4, "Bob", 175, 5);
    processor.addPerson(3, "Charlie", 350, 2);
    processor.addPerson(6, "David", 400, 3);
    processor.addPerson(1, "Emma", 200, 4);
    
    string result = processor.getLastPersonUnderLimit();
    cout << "Last person who can board: " << result << endl;
    
    return 0;
}