#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("file.txt");
    std::string line;
    int lineCount = 0;

    // Read lines until we reach the 10th line
    while (std::getline(file, line)) {
        lineCount++;
        if (lineCount == 10) {
            std::cout << line << std::endl;
            break;
        }
    }

    // If the file contains fewer than 10 lines
    if (lineCount < 10) {
        std::cout << "File has fewer than 10 lines." << std::endl;
    }

    return 0;
}

//in bash: head -n 10 file.txt | tail -n 1