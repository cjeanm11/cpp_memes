#ifndef UNTITLED3_PROBLEMS_HPP
#define UNTITLED3_PROBLEMS_HPP

#include <string>
#include <vector> // Include vector
#include <algorithm> // For std::max

namespace utils { // Use a namespace for better organization

class Problems {
public:
    static unsigned long calculate(const std::vector<std::string>& lines); // Declaration
    static bool calculateLength(const std::string& token);
    static bool calculateChecksum(const std::string& token);
};

} // namespace utils

#endif // UNTITLED3_PROBLEMS_HPP