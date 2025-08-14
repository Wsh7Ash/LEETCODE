#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <iostream>

int main() {
    try {
        // Create a connection to the database
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *con;
        
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "username", "password");
        
        // Connect to the specific database
        con->setSchema("your_database_name");
        
        // Prepare and execute the SQL query
        sql::PreparedStatement *pstmt;
        sql::ResultSet *res;
        
        pstmt = con->prepareStatement(
            "SELECT p.product_name, s.year, s.price "
            "FROM Sales s "
            "JOIN Product p ON s.product_id = p.product_id"
        );
        
        res = pstmt->executeQuery();
        
        // Display the results
        std::cout << "Product Name\tYear\tPrice" << std::endl;
        std::cout << "--------------------------------" << std::endl;
        
        while (res->next()) {
            std::cout << res->getString("product_name") << "\t"
                      << res->getInt("year") << "\t"
                      << res->getDouble("price") << std::endl;
        }
        
        // Clean up
        delete res;
        delete pstmt;
        delete con;
        
    } catch (sql::SQLException &e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
    
    return 0;
}