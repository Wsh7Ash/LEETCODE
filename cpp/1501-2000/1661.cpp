#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <iomanip>

struct Activity {
    int machine_id;
    std::string activity_type;
    double timestamp;
};

double calculateProcessingTime(const std::vector<Activity>& activities) {
    std::unordered_map<int, std::pair<double, int>> machineData; // machine_id -> (sum, count)
    
    // Process each activity record
    for (const auto& activity : activities) {
        if (activity.activity_type == "end") {
            machineData[activity.machine_id].first += activity.timestamp;
            machineData[activity.machine_id].second++;
        } else if (activity.activity_type == "start") {
            machineData[activity.machine_id].first -= activity.timestamp;
            machineData[activity.machine_id].second++;
        }
    }
    
    // Calculate average processing time for each machine
    double totalProcessingTime = 0.0;
    int machineCount = 0;
    
    for (const auto& [machine_id, data] : machineData) {
        if (data.second > 0) { // Ensure we have pairs of start/end activities
            double avgTime = (data.first / (data.second / 2)) * 2; // Equivalent to SQL logic
            totalProcessingTime += avgTime;
            machineCount++;
        }
    }
    
    return machineCount > 0 ? totalProcessingTime / machineCount : 0.0;
}

// Alternative function that returns processing time per machine
std::unordered_map<int, double> calculateProcessingTimePerMachine(const std::vector<Activity>& activities) {
    std::unordered_map<int, std::pair<double, int>> machineData;
    
    // Process each activity record
    for (const auto& activity : activities) {
        if (activity.activity_type == "end") {
            machineData[activity.machine_id].first += activity.timestamp;
            machineData[activity.machine_id].second++;
        } else if (activity.activity_type == "start") {
            machineData[activity.machine_id].first -= activity.timestamp;
            machineData[activity.machine_id].second++;
        }
    }
    
    // Calculate processing time for each machine
    std::unordered_map<int, double> result;
    for (const auto& [machine_id, data] : machineData) {
        if (data.second > 0 && data.second % 2 == 0) { // Ensure we have complete pairs
            double processingTime = (data.first / (data.second / 2)); // Average * 2
            result[machine_id] = std::round(processingTime * 1000) / 1000.0; // Round to 3 decimal places
        }
    }
    
    return result;
}

int main() {
    // Example data - similar to what would be in the Activity table
    std::vector<Activity> activities = {
        {0, "start", 0.712},
        {0, "end", 1.520},
        {0, "start", 3.140},
        {0, "end", 4.120},
        {1, "start", 0.550},
        {1, "end", 1.550},
        {1, "start", 0.430},
        {1, "end", 1.420},
        {2, "start", 4.100},
        {2, "end", 4.512}
    };
    
    // Calculate and display results
    auto results = calculateProcessingTimePerMachine(activities);
    
    std::cout << "Machine ID | Processing Time" << std::endl;
    std::cout << "-----------|----------------" << std::endl;
    
    for (const auto& [machine_id, processing_time] : results) {
        std::cout << std::setw(10) << machine_id << " | " 
                  << std::fixed << std::setprecision(3) << processing_time << std::endl;
    }
    
    return 0;
}