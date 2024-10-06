//
// Created by Jean-Michel on 2024-10-06.
//

#ifndef UNTITLED3_FILE_OPERATIONS_HPP
#define UNTITLED3_FILE_OPERATIONS_HPP
#include <array>

namespace utils {
class FileOperations {
public:
    static std::vector<std::string> readFileLines(const std::string& filePath);

private:
    FileOperations(); // Prevent instantiation
};


}// namespace utils

#endif//UNTITLED3_FILE_OPERATIONS_HPP
