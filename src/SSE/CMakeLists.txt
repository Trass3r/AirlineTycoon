cmake_minimum_required (VERSION 3.8)

include_directories(${PROJECT_SOURCE_DIR})

# Add source to this project's library.
add_library (SSE
    SSE.cpp
)
