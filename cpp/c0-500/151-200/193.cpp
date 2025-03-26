// grep -E '^\([0-9]{3}\) [0-9]{3}-[0-9]{4}$|^[0-9]{3}-[0-9]{3}-[0-9]{4}$' file.txt
#include <iostream>
#include <fstream>
#include <regex>
#include <string>

int main() {
    std::ifstream file("file.txt");  // Open the file containing phone numbers
    std::string line;
    
    // Define a regular expression for valid phone numbers
    std::regex pattern(R"(^\([0-9]{3}\) [0-9]{3}-[0-9]{4}$|^[0-9]{3}-[0-9]{3}-[0-9]{4}$)");

    // Read each line from the file
    while (std::getline(file, line)) {
        // Check if the line matches the pattern
        if (std::regex_match(line, pattern)) {
            std::cout << line << std::endl;  // Print valid phone numbers
        }
    }

    file.close();  // Close the file
    return 0;
}
