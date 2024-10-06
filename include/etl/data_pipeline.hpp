//
// Created by Jean-Michel on 2024-10-06.
//

#ifndef UNTITLED3_DATA_PIPELINE_HPP
#define UNTITLED3_DATA_PIPELINE_HPP
#include <vector>
#include <string>
#include "../status.hpp"

namespace etl {

class ETL {
public:
    virtual ~ETL() = default; // Properly define the destructor.
    virtual std::vector<std::string> extract() = 0;
    virtual Status process(std::string& dp) = 0;
    virtual Status load(const std::vector<std::string>& data) = 0; // Use std::vector<std::string>
};

class FileDataPipeline : public ETL { // Inherit publicly
public:
    ~FileDataPipeline() override; // Ensure proper override
    std::vector<std::string> extract() override;
    Status process(std::string& dp) override;
    Status load(const std::vector<std::string>& data) override; // Consistent return type
};

} // namespace etl#endif//UNTITLED3_DATA_PIPELINE_HPP

#endif //  UNTITLED3_DATA_PIPELINE_HPP