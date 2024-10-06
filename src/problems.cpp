#include "problems.hpp"

namespace utils {

unsigned long Problems::calculate(const std::vector<std::string>& lines) {
    unsigned long max{0L};
    unsigned long curr_sum{0L};

    for (const auto & line : lines) {
        if (line.empty()) {
            max = std::max(max, curr_sum);
            curr_sum = 0;
        } else {
            curr_sum += std::stol(line);
        }
    }

    max = std::max(max, curr_sum);

    return max;
}

} // namespace utils