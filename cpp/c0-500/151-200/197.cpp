#include <iostream>
#include <vector>
#include <string>

struct Weather {
    int id;
    std::string recordDate;
    int temperature;
};

int main() {
    // Input data (simulating the Weather table)
    std::vector<Weather> weatherData = {
        {1, "2015-01-01", 10},
        {2, "2015-01-02", 25},
        {3, "2015-01-03", 20},
        {4, "2015-01-04", 30}
    };

    // To store the result IDs
    std::vector<int> result;

    // Process the weather data
    for (size_t i = 1; i < weatherData.size(); ++i) {
        if (weatherData[i].temperature > weatherData[i - 1].temperature) {
            result.push_back(weatherData[i].id);
        }
    }

    // Output the result
    for (int id : result) {
        std::cout << id << std::endl;
    }

    return 0;
}
