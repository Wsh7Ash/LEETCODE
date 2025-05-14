#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>

int main() {
    try {
        // Create MySQL driver instance
        sql::mysql::MySQL_Driver *driver;
        driver = sql::mysql::get_mysql_driver_instance();

        // Establish connection
        std::unique_ptr<sql::Connection> con(driver->connect("tcp://127.0.0.1:3306", "username", "password"));

        // Select database
        con->setSchema("your_database");

        // Create statement
        std::unique_ptr<sql::PreparedStatement> pstmt(
            con->prepareStatement(
                "SELECT class "
                "FROM Courses "
                "GROUP BY class "
                "HAVING COUNT(student) >= 5"
            )
        );

        // Execute query
        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

        // Process results
        while (res->next()) {
            std::cout << "Class: " << res->getString("class") << std::endl;
        }

    } catch (sql::SQLException &e) {
        std::cout << "SQL Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}