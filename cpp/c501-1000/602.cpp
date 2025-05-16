#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

struct StadiumRecord {
    int id;
    std::string visit_date;
    int people;
    int grp;  // For storing group information
};

std::vector<StadiumRecord> findConsecutiveHighAttendance(const std::vector<StadiumRecord>& stadium) {
    // Step 1: Filter records where people >= 100 and calculate groups
    std::vector<StadiumRecord> filtered;
    int row_num = 1;
    
    for (const auto& record : stadium) {
        if (record.people >= 100) {
            StadiumRecord filtered_record = record;
            filtered_record.grp = record.id - row_num;
            filtered.push_back(filtered_record);
        }
        row_num++;
    }

    // Step 2: Find groups with at least 3 records
    std::map<int, int> group_counts;
    for (const auto& record : filtered) {
        group_counts[record.grp]++;
    }

    std::vector<int> valid_groups;
    for (const auto& [grp, count] : group_counts) {
        if (count >= 3) {
            valid_groups.push_back(grp);
        }
    }

    // Step 3: Collect results from valid groups
    std::vector<StadiumRecord> result;
    for (const auto& record : filtered) {
        if (std::find(valid_groups.begin(), valid_groups.end(), record.grp) != valid_groups.end()) {
            result.push_back(record);
        }
    }

    // Step 4: Sort by visit_date
    std::sort(result.begin(), result.end(), [](const StadiumRecord& a, const StadiumRecord& b) {
        return a.visit_date < b.visit_date;
    });

    return result;
}

int main() {
    // Example data - replace with your actual data
    std::vector<StadiumRecord> stadium = {
        {1, "2017-01-01", 10},
        {2, "2017-01-02", 109},
        {3, "2017-01-03", 150},
        {4, "2017-01-04", 99},
        {5, "2017-01-05", 145},
        {6, "2017-01-06", 1455},
        {7, "2017-01-07", 199},
        {8, "2017-01-09", 188}
    };

    auto result = findConsecutiveHighAttendance(stadium);

    // Print results
    std::cout << "id\tvisit_date\tpeople\n";
    std::cout << "----------------------------\n";
    for (const auto& record : result) {
        std::cout << record.id << "\t" << record.visit_date << "\t" << record.people << "\n";
    }

    return 0;
}