cmake_minimum_required(VERSION 3.16)
project(custom-operator-viz)


# find things

include_directories(/opt/spinnaker/include)
link_directories(/opt/spinnaker/lib)

# main executable

add_executable(
  acquisition
  acquisition.cpp
)
target_link_libraries(
  acquisition
  PUBLIC
  Spinnaker
)