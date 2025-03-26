#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // Convert bank to unordered_set for O(1) lookup
        unordered_set<string> validGenes(bank.begin(), bank.end());
        
        // If endGene is not in bank, return -1
        if (validGenes.find(endGene) == validGenes.end()) {
            return -1;
        }
        
        // Possible characters for mutation
        vector<char> chars = {'A', 'C', 'G', 'T'};
        
        // Queue for BFS: pair of gene string and mutation count
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        
        // Set to keep track of visited genes
        unordered_set<string> visited;
        visited.insert(startGene);
        
        // BFS
        while (!q.empty()) {
            auto [current, mutations] = q.front();
            q.pop();
            
            // If we reached target
            if (current == endGene) {
                return mutations;
            }
            
            // Try mutating each position
            for (int i = 0; i < 8; i++) {
                string original = current;
                
                // Try each possible character
                for (char c : chars) {
                    if (current[i] == c) continue;
                    
                    current[i] = c;
                    // If this is a valid mutation and not visited
                    if (validGenes.count(current) && !visited.count(current)) {
                        q.push({current, mutations + 1});
                        visited.insert(current);
                    }
                }
                
                // Restore original string for next position
                current = original;
            }
        }
        
        // If we can't reach endGene
        return -1;
    }
};
Let's break down how this solution works:

Approach:
Use BFS to find shortest path (minimum mutations)
Each gene string is a node
Edge exists between nodes if they differ by 1 character and both are valid
Start from startGene and search for endGene
Key Components:
validGenes: Set of valid gene strings from bank
Queue: Stores gene strings and their mutation counts
Visited set: Prevents revisiting same gene strings
Character array: Possible mutation options (A, C, G, T)
Algorithm:
Check if endGene is valid
Start BFS from startGene
For each gene string:
Try mutating each position with each possible character
If result is valid and unvisited, add to queue
Return mutations count when endGene found
Return -1 if endGene not reachable
Time and Space Complexity:
Time Complexity: O(4 * 8 * N) where N is number of possible valid states
4 possible chars, 8 positions, N reachable states
Space Complexity: O(N) for queue and visited set
Example 1: start="AACCGGTT", end="AACCGGTA", bank=["AACCGGTA"]
Start: "AACCGGTT"
Try all mutations, find "AACCGGTA" in bank
Return 1 (one mutation)
Example 2: start="AACCGGTT", end="AAACGGTA", bank=["AACCGGTA","AACCGCTA","AAACGGTA"]
"AACCGGTT" → "AACCGGTA" (1 mutation)
"AACCGGTA" → "AAACGGTA" (2 mutations)
Return 2
The solution handles all constraints:

Works with bank size 0-10
Handles 8-character strings
Only processes valid mutations from bank
Returns -1 when no valid mutation path exists
Assumes startGene is valid even if not in bank