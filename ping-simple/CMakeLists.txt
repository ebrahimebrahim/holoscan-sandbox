cmake_minimum_required(VERSION 3.21)
project(ping-simple)
find_package(holoscan REQUIRED CONFIG PATHS "/opt/nvidia/holoscan")

add_executable(ping_simple
  ping_simple.cpp
)
target_link_libraries(ping_simple
  PUBLIC
  holoscan::core
  holoscan::ops::ping_tx
  holoscan::ops::ping_rx
)