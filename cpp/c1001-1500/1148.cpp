#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>

// Simulating a database row structure
struct ViewRecord {
    int article_id;
    int author_id;
    int viewer_id;
    std::string view_date;
};

// Function to simulate database query
std::vector<ViewRecord> queryViewsDatabase() {
    // In a real application, this would connect to MySQL and execute the query
    // For demonstration, we'll return some sample data
    return {
        {1, 3, 5, "2023-08-01"},
        {2, 7, 7, "2023-08-01"},  // author_id = viewer_id
        {3, 4, 4, "2023-08-02"},  // author_id = viewer_id
        {4, 2, 8, "2023-08-02"},
        {5, 7, 3, "2023-08-03"},
        {6, 4, 4, "2023-08-03"},  // author_id = viewer_id (duplicate)
        {7, 1, 1, "2023-08-04"}   // author_id = viewer_id
    };
}

// Solution using set (automatically sorts and removes duplicates)
std::vector<int> findAuthorsWhoViewedTheirArticles() {
    auto views = queryViewsDatabase();
    std::set<int> result;
    
    for (const auto& view : views) {
        if (view.author_id == view.viewer_id) {
            result.insert(view.author_id);
        }
    }
    
    return std::vector<int>(result.begin(), result.end());
}

// Alternative solution using unordered_set and manual sorting
std::vector<int> findAuthorsWhoViewedTheirArticlesAlt() {
    auto views = queryViewsDatabase();
    std::unordered_set<int> unique_ids;
    
    // Find matching authors and store in set to remove duplicates
    for (const auto& view : views) {
        if (view.author_id == view.viewer_id) {
            unique_ids.insert(view.author_id);
        }
    }
    
    // Convert to vector and sort
    std::vector<int> result(unique_ids.begin(), unique_ids.end());
    std::sort(result.begin(), result.end());
    
    return result;
}

int main() {
    // Get results using first method
    auto authors = findAuthorsWhoViewedTheirArticles();
    
    std::cout << "Authors who viewed their own articles:\n";
    std::cout << "id\n";
    std::cout << "--\n";
    
    for (int id : authors) {
        std::cout << id << std::endl;
    }
    
    return 0;
}