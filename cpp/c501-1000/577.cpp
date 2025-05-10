#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <iostream>

int main() {
    try {
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;

        // Create a connection
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "username", "password");
        
        // Connect to the appropriate database
        con->setSchema("your_database_name");

        // Create and execute the query
        stmt = con->createStatement();
        res = stmt->executeQuery(
            "SELECT e.name, b.bonus "
            "FROM Employee e "
            "LEFT JOIN Bonus b ON e.empId = b.empId "
            "WHERE b.bonus < 1000 OR b.bonus IS NULL"
        );

        // Print the results
        while (res->next()) {
            std::cout << "Name: " << res->getString("name");
            
            if (res->isNull("bonus")) {
                std::cout << ", Bonus: NULL" << std::endl;
            } else {
                std::cout << ", Bonus: " << res->getInt("bonus") << std::endl;
            }
        }

        // Clean up
        delete res;
        delete stmt;
        delete con;

    } catch (sql::SQLException &e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }

    return 0;
}