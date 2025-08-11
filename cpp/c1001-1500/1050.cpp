#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility> // for std::pair

struct ActorDirector {
    int actor_id;
    int director_id;
};

std::vector<std::pair<int, int>> findFrequentCollaborators(const std::vector<ActorDirector>& records) {
    std::unordered_map<int, std::unordered_map<int, int>> countMap;
    std::vector<std::pair<int, int>> result;
    
    // Count collaborations
    for (const auto& record : records) {
        countMap[record.actor_id][record.director_id]++;
    }
    
    // Find pairs with >= 3 collaborations
    for (const auto& actorEntry : countMap) {
        int actor_id = actorEntry.first;
        for (const auto& directorEntry : actorEntry.second) {
            int director_id = directorEntry.first;
            int count = directorEntry.second;
            if (count >= 3) {
                result.emplace_back(actor_id, director_id);
            }
        }
    }
    
    return result;
}

int main() {
    // Example usage
    std::vector<ActorDirector> records = {
        {1, 1},
        {1, 1},
        {1, 1},
        {1, 2},
        {2, 1},
        {2, 1}
    };
    
    auto frequentPairs = findFrequentCollaborators(records);
    
    std::cout << "Actor ID | Director ID\n";
    std::cout << "--------|------------\n";
    for (const auto& pair : frequentPairs) {
        std::cout << pair.first << "       | " << pair.second << "\n";
    }
    
    return 0;
}