#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string simplifyPath(string path) {
    vector<string> stack; // Use a vector to simulate a stack
    stringstream ss(path); // Use stringstream to split the path
    string component;

    // Split the path by '/'
    while (getline(ss, component, '/')) {
        if (component == "..") {
            // Go up one level (pop from stack if not empty)
            if (!stack.empty()) {
                stack.pop_back();
            }
        } else if (component != "." && !component.empty()) {
            // Push valid directory names onto the stack
            stack.push_back(component);
        }
    }

    // Construct the canonical path
    string canonicalPath = "/";
    for (const string& dir : stack) {
        canonicalPath += dir + "/";
    }

    // Remove the trailing slash if it's not the root directory
    if (canonicalPath.size() > 1) {
        canonicalPath.pop_back();
    }

    return canonicalPath;
}

int main() {
    // Test cases
    cout << simplifyPath("/home/") << endl;                     // Output: "/home"
    cout << simplifyPath("/home//foo/") << endl;                // Output: "/home/foo"
    cout << simplifyPath("/home/user/Documents/../Pictures") << endl; // Output: "/home/user/Pictures"
    cout << simplifyPath("/../") << endl;                       // Output: "/"
    cout << simplifyPath("/.../a/../b/c/../d/./") << endl;      // Output: "/.../b/d"

    return 0;
}