//
// Created by Jean-Michel on 2024-10-06.
//

#include "etl/data_pipeline.hpp"

namespace etl {

FileDataPipeline::~FileDataPipeline() = default;

std::vector<std::string> FileDataPipeline::extract() {
    return {};
}

Status FileDataPipeline::process(std::string &dp) {
    return Status::OK();
}

Status FileDataPipeline::load(const std::vector<std::string> &data) {
    return Status::OK();
}

} // namespace etl