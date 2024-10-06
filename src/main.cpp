//
// Created by Jean-Michel on 2024-10-06.
//

#include "utils/file_operations.hpp"
#include "problems.hpp"
#include "fmt/core.h"
#include <vector>


int main(){
    // problem 1
    const std::vector<std::string> lines = utils::FileOperations::readFileLines("../in.txt");
    const unsigned long result = utils::Problems::calculate(lines);
    fmt::print("Result: {} \n", result);
    std::string str{"  dwedw   "};
    // problem 2
    const std::string token = "|ACC=123|AX=12|AC=124|wedwdewe|dewddwed|dweddwed|wdeedowwedwedwed|ddddddddddddde|dowmedomwoe|weomdowed|dewdedwed|dwed|dwedwed|wedwed|wedew|AC=198|";
    fmt::println(" {} - {}", utils::Problems::calculateLength(token), utils::Problems::calculateChecksum(std::move(token)));

    return 0;
}

