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
        
        // Prepare and execute the SQL query with CTE
        sql::PreparedStatement *pstmt;
        sql::ResultSet *res;
        
        pstmt = con->prepareStatement(
            "WITH FirstYearSales AS ("
            "    SELECT "
            "        product_id, "
            "        MIN(year) as first_year "
            "    FROM "
            "        Sales "
            "    GROUP BY "
            "        product_id "
            ") "
            "SELECT "
            "    s.product_id, "
            "    f.first_year, "
            "    s.quantity, "
            "    s.price "
            "FROM "
            "    sales s "
            "JOIN "
            "    FirstYearSales f ON s.product_id = f.product_id AND s.year = f.first_year"
        );
        
        res = pstmt->executeQuery();
        
        // Display the results
        std::cout << "Product ID\tFirst Year\tQuantity\tPrice" << std::endl;
        std::cout << "------------------------------------------------" << std::endl;
        
        while (res->next()) {
            std::cout << res->getInt("product_id") << "\t\t"
                      << res->getInt("first_year") << "\t\t"
                      << res->getInt("quantity") << "\t\t"
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