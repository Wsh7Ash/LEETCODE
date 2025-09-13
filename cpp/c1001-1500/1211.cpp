#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
#include <iostream>
#include <iomanip>

int main() {
    try {
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;

        // Create connection
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "username", "password");
        con->setSchema("your_database_name");

        // Execute query
        stmt = con->createStatement();
        res = stmt->executeQuery(
            "SELECT query_name, "
            "ROUND(AVG(rating * 1.0 / position), 2) as quality, "
            "ROUND(SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END) * 100.0 / COUNT(*), 2) as poor_query_percentage "
            "FROM Queries "
            "WHERE query_name IS NOT NULL "
            "GROUP BY query_name"
        );

        // Display results
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "query_name | quality | poor_query_percentage\n";
        std::cout << "-------------------------------------------\n";

        while (res->next()) {
            std::cout << std::setw(10) << res->getString("query_name") << " | "
                      << std::setw(7) << res->getDouble("quality") << " | "
                      << std::setw(21) << res->getDouble("poor_query_percentage") << "%\n";
        }

        delete res;
        delete stmt;
        delete con;

    } catch (sql::SQLException &e) {
        std::cout << "SQL Error: " << e.what() << std::endl;
    }

    return 0;
}