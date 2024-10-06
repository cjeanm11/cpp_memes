cmake_minimum_required(VERSION 3.29)
project(untitled3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Ensure the C++ standard is enforced

# Include FetchContent module
include(FetchContent)

# 1. Fetch Abseil
FetchContent_Declare(
        abseil
        GIT_REPOSITORY https://github.com/abseil/abseil-cpp.git
        GIT_TAG master # You may specify a specific tag or branch; consider using a stable release
)

# Ensure C++ standard is propagated to Abseil
set(ABSL_PROPAGATE_CXX_STD ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(abseil)

# Fetch fmt library
FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG master  # You can specify a release tag here
)
FetchContent_MakeAvailable(fmt)


# Add executable
add_executable(untitled3 src/main.cpp src/utils/file_operations.cpp
        src/problems.cpp
        src/problems.cpp
        src/etl/data_pipeline.cpp
        src/etl/data_pipeline.hpp)

# Link libraries
target_link_libraries(untitled3
        PRIVATE
        absl::base
        absl::strings
        fmt::fmt
)

# Specify include directories
target_include_directories(untitled3 PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)