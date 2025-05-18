#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>

int main() {
    try {
        // Initialize MySQL driver
        sql::mysql::MySQL_Driver *driver;
        driver = sql::mysql::get_mysql_driver_instance();

        // Establish connection
        std::unique_ptr<sql::Connection> con(driver->connect("tcp://127.0.0.1:3306", "your_username", "your_password"));

        // Set schema (database)
        con->setSchema("your_database");

        // Create statement
        std::unique_ptr<sql::Statement> stmt(con->createStatement());

        // Execute the query
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery(
            "SELECT id, movie, description, rating "
            "FROM Cinema "
            "WHERE id % 2 = 1 AND description != 'boring' "
            "ORDER BY rating DESC"
        ));

        // Fetch and display results
        std::cout << "ID\tMovie\tDescription\tRating" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        while (res->next()) {
            std::cout << res->getInt("id") << "\t"
                      << res->getString("movie") << "\t"
                      << res->getString("description") << "\t"
                      << res->getDouble("rating") << std::endl;
        }

        // Check if no results were returned
        if (res->rowsCount() == 0) {
            std::cout << "No movies found matching the criteria." << std::endl;
        }

    } catch (sql::SQLException &e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
        std::cerr << "SQLState: " << e.getSQLState() << std::endl;
        std::cerr << "Error Code: " << e.getErrorCode() << std::endl;
        return 1;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}