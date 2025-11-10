#include <iostream>
#include <stdexcept>
#include <memory>
#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>

int main() {
    try {
        // 1. Create a connection to the database
        sql::Driver* driver = get_driver_instance();
        std::unique_ptr<sql::Connection> con(
            driver->connect("tcp://127.0.0.1:3306", "your_username", "your_password")
        );

        // 2. Connect to the specific database
        con->setSchema("your_database_name");

        // 3. Prepare the SQL query
        std::string query = R"(
            SELECT 
                date_id,
                make_name,
                COUNT(DISTINCT lead_id) AS unique_leads,
                COUNT(DISTINCT partner_id) AS unique_partners
            FROM DailySales
            GROUP BY date_id, make_name
            ORDER BY date_id, make_name;
        )";

        // 4. Execute the query
        std::unique_ptr<sql::Statement> stmt(con->createStatement());
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery(query));

        // 5. Display the results
        std::cout << "date_id\tmake_name\tunique_leads\tunique_partners\n";
        std::cout << "------------------------------------------------------\n";

        while (res->next()) {
            std::cout 
                << res->getString("date_id") << "\t"
                << res->getString("make_name") << "\t"
                << res->getInt("unique_leads") << "\t\t"
                << res->getInt("unique_partners") << "\n";
        }

    } catch (sql::SQLException& e) {
        std::cerr << "SQL error: " << e.what()
                  << " (MySQL error code: " << e.getErrorCode()
                  << ", SQLState: " << e.getSQLState() << " )" << std::endl;
        return EXIT_FAILURE;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
