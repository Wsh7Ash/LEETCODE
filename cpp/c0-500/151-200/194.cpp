#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    std::ifstream file("file.txt");
    std::string line;
    std::vector<std::vector<std::string>> matrix;

    // Read the file and store each line as a row in the matrix
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string word;
        std::vector<std::string> row;
        
        // Split the line into words and store them in a row
        while (ss >> word) {
            row.push_back(word);
        }
        matrix.push_back(row);
    }

    // Transpose the matrix and print the result
    for (size_t col = 0; col < matrix[0].size(); ++col) {
        for (size_t row = 0; row < matrix.size(); ++row) {
            std::cout << matrix[row][col];
            if (row != matrix.size() - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    file.close();
    return 0;
}
//IN BASH cmd:: -> // awk '{for(i=1;i<=NF;i++) a[i]=a[i]" "$i} END {for(i=1;i<=length(a);i++) print substr(a[i],2)}' file.txt
