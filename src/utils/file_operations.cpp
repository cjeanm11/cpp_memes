#include "utils/file_operations.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <absl/strings/strip.h>
#include <stdexcept>

namespace utils {


FileOperations::FileOperations() = default;

std::vector<std::string> FileOperations::readFileLines(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string line;

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filePath);
    }

    size_t lineCount = 0;
    while (std::getline(file, line)) {
        lineCount++;
    }

    std::vector<std::string> lines;
    lines.reserve(lineCount);

    file.clear();
    file.seekg(0, std::ios::beg);

    while (std::getline(file, line)) {
        line = absl::StripAsciiWhitespace(line);
        lines.emplace_back(line);
    }

    return lines;
}

} // namespace utils