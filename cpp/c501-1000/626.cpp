#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Seat {
    int id;
    std::string student;
};

std::vector<Seat> swapSeats(std::vector<Seat>& seats) {
    int n = seats.size();
    std::vector<Seat> result(n);
    
    for (int i = 0; i < n; ++i) {
        int curr_id = seats[i].id;
        // If id is odd and it's the max id, keep it as is
        if (curr_id % 2 == 1 && curr_id == seats[n-1].id) {
            result[i] = {curr_id, seats[i].student};
        }
        // If id is odd, assign it to id+1
        else if (curr_id % 2 == 1) {
            result[i] = {curr_id + 1, seats[i].student};
        }
        // If id is even, assign it to id-1
        else {
            result[i] = {curr_id - 1, seats[i].student};
        }
    }
    
    // Sort by id to match the query's ORDER BY id
    std::sort(result.begin(), result.end(), [](const Seat& a, const Seat& b) {
        return a.id < b.id;
    });
    
    return result;
}

int main() {
    // Example input: simulating the Seat table
    std::vector<Seat> seats = {
        {1, "John"},
        {2, "Jane"},
        {3, "Alice"},
        {4, "Bob"},
        {5, "Charlie"}
    };
    
    // Process the seats
    std::vector<Seat> result = swapSeats(seats);
    
    // Output the result
    std::cout << "id\tstudent\n";
    for (const auto& seat : result) {
        std::cout << seat.id << "\t" << seat.student << "\n";
    }
    
    return 0;
}