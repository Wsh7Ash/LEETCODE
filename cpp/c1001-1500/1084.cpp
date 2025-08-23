#include <iostream>
#include <string>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>

int main() {
    try {
        // Create a MySQL driver instance
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *con;
        
        // Get driver instance and connect to database
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "username", "password");
        
        // Select the database
        con->setSchema("your_database_name");
        
        // Create SQL query string
        std::string query = R"(
            SELECT p.product_id, p.product_name
            FROM Product p
            JOIN Sales s ON p.product_id = s.product_id
            GROUP BY p.product_id, p.product_name
            HAVING MIN(s.sale_date) >= '2019-01-01' 
               AND MAX(s.sale_date) <= '2019-03-31'
        )";
        
        // Create statement and execute query
        sql::Statement *stmt;
        sql::ResultSet *res;
        
        stmt = con->createStatement();
        res = stmt->executeQuery(query);
        
        // Process the results
        std::cout << "Products sold exclusively between 2019-01-01 and 2019-03-31:\n";
        std::cout << "Product ID\tProduct Name\n";
        std::cout << "--------------------------------\n";
        
        while (res->next()) {
            int product_id = res->getInt("product_id");
            std::string product_name = res->getString("product_name");
            
            std::cout << product_id << "\t\t" << product_name << std::endl;
        }
        
        // Clean up
        delete res;
        delete stmt;
        delete con;
        
    } catch (sql::SQLException &e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
        std::cerr << "MySQL error code: " << e.getErrorCode() << std::endl;
        std::cerr << "SQLState: " << e.getSQLState() << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}