/*cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -nr | awk '{print $2, $1}'*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream file("words.txt");
    std::string word;
    std::map<std::string, int> wordCount;

    // Step 1: Read words from file and count occurrences
    while (file >> word) {
        wordCount[word]++;
    }

    // Step 2: Store words and their counts in a vector for sorting
    std::vector<std::pair<int, std::string>> countVec;
    for (const auto& pair : wordCount) {
        countVec.push_back({pair.second, pair.first});
    }

    // Step 3: Sort the vector in descending order based on count
    std::sort(countVec.rbegin(), countVec.rend());

    // Step 4: Print the results
    for (const auto& pair : countVec) {
        std::cout << pair.second << " " << pair.first << std::endl;
    }

    return 0;
}
