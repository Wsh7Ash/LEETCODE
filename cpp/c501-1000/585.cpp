#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <iostream>
#include <memory>
#include <iomanip>

int main() {
    try {
        // Create connection
        auto driver = sql::mysql::get_mysql_driver_instance();
        auto con = std::unique_ptr<sql::Connection>(
            driver->connect("tcp://127.0.0.1:3306", "username", "password"));
        
        con->setSchema("your_database_name");

        // Create and execute the query
        auto stmt = std::unique_ptr<sql::Statement>(con->createStatement());
        auto res = std::unique_ptr<sql::ResultSet>(
            stmt->executeQuery(
                "SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016 "
                "FROM Insurance "
                "WHERE tiv_2015 IN ("
                "    SELECT tiv_2015 "
                "    FROM Insurance "
                "    GROUP BY tiv_2015 "
                "    HAVING COUNT(*) > 1"
                ") "
                "AND (lat, lon) IN ("
                "    SELECT lat, lon "
                "    FROM Insurance "
                "    GROUP BY lat, lon "
                "    HAVING COUNT(*) = 1"
                ")"
            )
        );

        // Display the result
        if (res->next()) {
            std::cout << "Total TIV 2016: " 
                      << std::fixed << std::setprecision(2)
                      << res->getDouble("tiv_2016") << std::endl;
        } else {
            std::cout << "No results found." << std::endl;
        }

    } catch (const sql::SQLException &e) {
        std::cerr << "MySQL Error: " << e.what() 
                  << " (MySQL error code: " << e.getErrorCode() 
                  << ", SQLState: " << e.getSQLState() << ")\n";
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}