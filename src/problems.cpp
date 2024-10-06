#include "problems.hpp"

#include "fmt/core.h"
#include "fmt/core.h"
#include <vector>
#include <numeric>

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

bool Problems::calculateLength(const std::string& token) {
    const std::string target_header_key = "|AC=";
    size_t i_header_key = token.find(target_header_key);

    if (i_header_key != std::string::npos) {
        size_t i_end_value = token.find('|', i_header_key + target_header_key.size());
        if (i_end_value == std::string::npos) {
            i_end_value = token.size();
        }

        size_t value_start = i_header_key + target_header_key.size();
        size_t value_length = i_end_value - value_start;

        size_t value = std::stoul(token.substr(value_start, value_length));

        size_t body_size = token.size() - (i_end_value + 1);
        fmt::println("header value: {}, body size: {}", value, body_size);

        return value == body_size;
    }

    return false;
}


bool Problems::calculateChecksum(const std::string& token) {
    const std::string target_header_key = "|AC=";
    size_t i_header_key = token.rfind(target_header_key);

    if (i_header_key != std::string::npos) {
        size_t i_end_value = token.find('|', i_header_key + target_header_key.size());
        if (i_end_value == std::string::npos) {
            i_end_value = token.size();
        }

        size_t value_start = i_header_key + target_header_key.size();
        size_t value_length = i_end_value - value_start;

        size_t value = std::stoul(token.substr(value_start, value_length));
        const size_t checksum_value = std::accumulate(token.begin(), token.begin() + i_header_key, 0 );
        fmt::println("header value : {}, checksum value: {}", value, checksum_value % 256);
        return value == (checksum_value % 256);
    }

    return false;
}

} // namespace utils