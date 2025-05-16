#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

struct StadiumRecord {
    int id;
    std::string visit_date;
    int people;
};

void solve() {
    // Assuming we have the Stadium data loaded into a vector
    std::vector<StadiumRecord> stadium = {
        // This would be populated with your actual data
        // Example: {1, "2023-01-01", 150}, {2, "2023-01-02", 80}, ...
    };
    
    // First filter: people >= 100 and calculate group
    std::vector<std::pair<StadiumRecord, int>> filtered;
    for (size_t i = 0; i < stadium.size(); ++i) {
        if (stadium[i].people >= 100) {
            int grp = stadium[i].id - (i + 1); // Assuming row_number is based on position
            filtered.emplace_back(stadium[i], grp);
        }
    }
    
    // Group and count groups with >= 3 records
    std::map<int, int> group_counts;
    for (const auto& [record, grp] : filtered) {
        group_counts[grp]++;
    }
    
    // Collect valid groups
    std::vector<int> valid_groups;
    for (const auto& [grp, count] : group_counts) {
        if (count >= 3) {
            valid_groups.push_back(grp);
        }
    }
    
    // Collect results and sort by visit_date
    std::vector<StadiumRecord> result;
    for (const auto& [record, grp] : filtered) {
        if (std::find(valid_groups.begin(), valid_groups.end(), grp) != valid_groups.end()) {
            result.push_back(record);
        }
    }
    
    // Sort by visit_date
    std::sort(result.begin(), result.end(), [](const StadiumRecord& a, const StadiumRecord& b) {
        return a.visit_date < b.visit_date;
    });
    
    // Output the results
    for (const auto& record : result) {
        std::cout << record.id << ", " << record.visit_date << ", " << record.people << "\n";
    }
}

int main() {
    solve();
    return 0;
}