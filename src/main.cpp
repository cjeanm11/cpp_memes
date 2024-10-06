//
// Created by Jean-Michel on 2024-10-06.
//

#include "utils/file_operations.hpp"
#include "problems.hpp"
#include "fmt/core.h"
#include <vector>

int main(){
    const std::vector<std::string> lines = utils::FileOperations::readFileLines("../in.txt");
    const unsigned long result = utils::Problems::calculate(lines);
    fmt::print("Result: {}", result);
    return 0;
}

