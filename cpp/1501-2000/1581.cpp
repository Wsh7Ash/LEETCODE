#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

struct Visit {
    int visit_id;
    int customer_id;
};

struct Transaction {
    int transaction_id;
    int visit_id;
    int amount; // assuming there's an amount field
};

struct CustomerVisitCount {
    int customer_id;
    int count_no_trans;
};

std::vector<CustomerVisitCount> findCustomersWithNoTransactions(
    const std::vector<Visit>& visits,
    const std::vector<Transaction>& transactions) {
    
    // Create a set of all visit_ids that have transactions
    std::unordered_set<int> visitedWithTransactions;
    for (const auto& transaction : transactions) {
        visitedWithTransactions.insert(transaction.visit_id);
    }
    
    // Count visits without transactions per customer
    std::unordered_map<int, int> customerCounts;
    for (const auto& visit : visits) {
        if (visitedWithTransactions.find(visit.visit_id) == visitedWithTransactions.end()) {
            customerCounts[visit.customer_id]++;
        }
    }
    
    // Convert to vector and sort
    std::vector<CustomerVisitCount> result;
    for (const auto& [customer_id, count] : customerCounts) {
        result.push_back({customer_id, count});
    }
    
    // Sort by count_no_trans descending, then customer_id ascending
    std::sort(result.begin(), result.end(), 
        [](const CustomerVisitCount& a, const CustomerVisitCount& b) {
            if (a.count_no_trans != b.count_no_trans) {
                return a.count_no_trans > b.count_no_trans;
            }
            return a.customer_id < b.customer_id;
        });
    
    return result;
}

// Example usage
int main() {
    // Sample data
    std::vector<Visit> visits = {
        {1, 1}, {2, 2}, {3, 3}, {4, 1}, {5, 2}, {6, 4}
    };
    
    std::vector<Transaction> transactions = {
        {1, 1, 100}, {2, 2, 200}, {3, 3, 150}
    };
    
    auto result = findCustomersWithNoTransactions(visits, transactions);
    
    std::cout << "customer_id\tcount_no_trans" << std::endl;
    for (const auto& customer : result) {
        std::cout << customer.customer_id << "\t\t" << customer.count_no_trans << std::endl;
    }
    
    return 0;
}