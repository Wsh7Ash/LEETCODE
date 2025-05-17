#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Triangle {
    int x;
    int y;
    int z;
    string is_triangle;
};

vector<Triangle> checkTriangles(const vector<vector<int>>& triangles) {
    vector<Triangle> result;
    
    for (const auto& t : triangles) {
        Triangle tri;
        tri.x = t[0];
        tri.y = t[1];
        tri.z = t[2];
        
        // Check triangle inequality theorem
        if (t[0] + t[1] > t[2] && 
            t[0] + t[2] > t[1] && 
            t[1] + t[2] > t[0]) {
            tri.is_triangle = "Yes";
        } else {
            tri.is_triangle = "No";
        }
        
        result.push_back(tri);
    }
    
    return result;
}

int main() {
    // Example triangle data: vector of {x, y, z} triplets
    vector<vector<int>> triangle_data = {
        {3, 4, 5},
        {1, 2, 3},
        {5, 12, 13},
        {7, 10, 5},
        {10, 10, 10}
    };
    
    vector<Triangle> results = checkTriangles(triangle_data);
    
    // Print the results in a similar format to the SQL output
    cout << "x\ty\tz\ttriangle" << endl;
    for (const auto& t : results) {
        cout << t.x << "\t" << t.y << "\t" << t.z << "\t" << t.is_triangle << endl;
    }
    
    return 0;
}