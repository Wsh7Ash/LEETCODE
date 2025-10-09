#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>

int main() {
    try {
        // Initialize the MySQL driver
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *con;

        driver = sql::mysql::get_mysql_driver_instance();
        // Replace with your MySQL server details
        con = driver->connect("tcp://127.0.0.1:3306", "username", "password");

        // Select the database
        con->setSchema("your_database_name");

        // Create a statement
        std::unique_ptr<sql::Statement> stmt(con->createStatement());

        // Execute the query
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery(
            "SELECT eu.unique_id, e.name "
            "FROM Employees e "
            "LEFT JOIN EmployeeUNI eu ON e.id = eu.id"
        ));

        // Process the result set
        while (res->next()) {
            // Handle NULL for unique_id
            if (res->isNull("unique_id")) {
                std::cout << "NULL, ";
            } else {
                std::cout << res->getInt("unique_id") << ", ";
            }
            // Get name (assuming it's not NULL)
            std::cout << res->getString("name") << std::endl;
        }

        // Clean up
        delete con;

    } catch (sql::SQLException &e) {
        std::cout << "SQL Error: " << e.what() << std::endl;
        std::cout << "SQLState: " << e.getSQLState() << std::endl;
        std::cout << "ErrorCode: " << e.getErrorCode() << std::endl;
        return 1;
    }

    return 0;
}