#include <string>
#include <vector>
#include <sstream>

class Solution {
public:
    int lengthLongestPath(string input) {
        // Vector to store path lengths at each level
        vector<int> levels(1000, 0);  // sufficiently large size
        int maxLength = 0;  // track maximum path length
        stringstream ss(input);
        string line;
        
        // Process each line
        while (getline(ss, line, '\n')) {
            // Count number of tabs (level)
            int level = 0;
            while (level < line.length() && line[level] == '\t') {
                level++;
            }
            
            // Get the name (without tabs)
            string name = line.substr(level);
            int nameLength = name.length();
            
            // If it's a file (contains a dot)
            if (name.find('.') != string::npos) {
                // Calculate total path length: parent length + current name + 1 for '/'
                int currentLength = (level > 0 ? levels[level - 1] : 0) + nameLength + (level > 0 ? 1 : 0);
                maxLength = max(maxLength, currentLength);
            } else {
                // For directory, update length at this level
                // Parent length + current name length + 1 for '/'
                levels[level] = (level > 0 ? levels[level - 1] : 0) + nameLength + (level > 0 ? 1 : 0);
            }
        }
        
        return maxLength;
    }
};
Let's break down how this solution works:

Approach:
We use a vector to keep track of path lengths at each directory level
Process the input line by line (split by '\n')
For each line, determine its level (count tabs) and whether it's a file or directory
Track maximum length when we find files
Time Complexity: O(n) where n is the length of input string
Space Complexity: O(1) since levels vector is fixed size
Key Components:
levels vector: stores the cumulative path length up to each level
Level counting: number of tabs indicates directory depth
File detection: presence of '.' indicates a file
Path length: includes parent path + current name + slashes
Example walkthrough for "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1":
text

Collapse

Wrap

Copy
Line 1: "dir"
- level = 0
- directory: levels[0] = 3

Line 2: "\tsubdir1"
- level = 1
- directory: levels[1] = levels[0] + 7 + 1 = 11

Line 3: "\t\tfile1.ext"
- level = 2
- file: total = levels[1] + 9 + 1 = 21
- maxLength = 21

Line 4: "\t\tsubsubdir1"
- level = 2
- directory: levels[2] = levels[1] + 10 + 1 = 22

Final result: 21
Handling the requirements:
Works for input length 1 to 10^4
Handles all specified characters (letters, digits, spaces, dots)
Returns 0 when no files exist
Assumes valid file system structure as per constraints
Path length calculation:
For directories: parent_length + name_length + 1 (slash)
For files: parent_length + name_length + 1 (slash)
At root level (level 0), no leading slash is added
The solution efficiently tracks path lengths using a level-based approach, avoiding the need to construct actual path strings. It handles all the example cases correctly:

Example 1: Returns 20 for "dir/subdir2/file.ext"
Example 2: Returns 32 for "dir/subdir2/subsubdir2/file2.ext"
Example 3: Returns 0 for "a" (no files)