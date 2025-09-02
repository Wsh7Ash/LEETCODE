#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>

struct Delivery {
    int delivery_id;
    int customer_id;
    std::string order_date;
    std::string customer_pref_delivery_date;
};

class DeliveryAnalyzer {
public:
    static double calculateImmediatePercentage(const std::vector<Delivery>& deliveries) {
        // Step 1: Find first order date for each customer
        std::unordered_map<int, std::string> customerFirstOrder;
        
        for (const auto& delivery : deliveries) {
            int customerId = delivery.customer_id;
            std::string orderDate = delivery.order_date;
            
            if (customerFirstOrder.find(customerId) == customerFirstOrder.end() ||
                orderDate < customerFirstOrder[customerId]) {
                customerFirstOrder[customerId] = orderDate;
            }
        }
        
        // Step 2: Filter deliveries to only first orders and calculate immediate deliveries
        int totalFirstOrders = 0;
        int immediateFirstOrders = 0;
        
        for (const auto& delivery : deliveries) {
            // Check if this is the customer's first order
            if (customerFirstOrder[delivery.customer_id] == delivery.order_date) {
                totalFirstOrders++;
                
                // Check if delivery was immediate (order_date == customer_pref_delivery_date)
                if (delivery.order_date == delivery.customer_pref_delivery_date) {
                    immediateFirstOrders++;
                }
            }
        }
        
        // Step 3: Calculate percentage
        if (totalFirstOrders == 0) {
            return 0.0;
        }
        
        double percentage = (static_cast<double>(immediateFirstOrders) / totalFirstOrders) * 100.0;
        
        // Round to 2 decimal places
        return std::round(percentage * 100.0) / 100.0;
    }
};

// Example usage
int main() {
    // Sample data
    std::vector<Delivery> deliveries = {
        {1, 1, "2019-08-01", "2019-08-02"},
        {2, 2, "2019-08-02", "2019-08-02"},
        {3, 1, "2019-08-11", "2019-08-12"},
        {4, 3, "2019-08-24", "2019-08-24"},
        {5, 3, "2019-08-21", "2019-08-22"},
        {6, 2, "2019-08-11", "2019-08-13"}
    };
    
    double result = DeliveryAnalyzer::calculateImmediatePercentage(deliveries);
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Immediate percentage: " << result << "%" << std::endl;
    
    return 0;
}