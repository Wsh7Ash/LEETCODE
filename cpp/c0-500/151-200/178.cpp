#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Score {
    float score;
    int rank;
};

vector<Score> rankScores(vector<Score>& scores) {
    // Sort the scores in descending order
    sort(scores.begin(), scores.end(), [](const Score& a, const Score& b) {
        return a.score > b.score;  // Sorting in descending order based on score
    });

    vector<Score> result;
    int currentRank = 1;
    
    // Assign rank to the first score
    result.push_back({scores[0].score, currentRank});
    
    for (int i = 1; i < scores.size(); ++i) {
        if (scores[i].score != scores[i - 1].score) {
            // If the score is different from the previous, increment the rank
            currentRank = i + 1;  // Rank is 1-based
        }
        result.push_back({scores[i].score, currentRank});
    }

    return result;
}

int main() {
    vector<Score> scores = {{1, 3.50}, {2, 3.65}, {3, 4.00}, {4, 3.85}, {5, 4.00}, {6, 3.65}};
    
    vector<Score> rankedScores = rankScores(scores);
    
    // Output the ranked scores
    for (const auto& entry : rankedScores) {
        cout << "Score: " << entry.score << ", Rank: " << entry.rank << endl;
    }
    
    return 0;
}
