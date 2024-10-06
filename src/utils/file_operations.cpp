#include "utils/file_operations.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <absl/strings/strip.h>

namespace utils {
// Function to trim whitespace from both ends of a string
absl::string_view trim(const std::string& str) {
    return absl::StripAsciiWhitespace(str);
}


FileOperations::FileOperations() = default;



std::vector<std::string> FileOperations::readFileLines(const std::string& filePath) {
    std::vector<std::string> lines;
    std::ifstream file(filePath);
    std::string line;

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filePath);
    }

    while (std::getline(file, line)) {
        line = absl::StripAsciiWhitespace(line.erase(line.find_last_not_of('\n') + 1));
        lines.emplace_back(line);
    }
    return lines;
}

} // namespace utils
