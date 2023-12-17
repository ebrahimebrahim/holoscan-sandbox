cmake_minimum_required(VERSION 3.21)
project(custom-operator-viz)


# find things

find_package(holoscan REQUIRED CONFIG PATHS "/opt/nvidia/holoscan")
include_directories(/opt/spinnaker/include)
link_directories(/opt/spinnaker/lib)


# custom operator

add_library(custom_op SHARED custom_op.cpp)

target_link_libraries(custom_op
    PUBLIC
      holoscan::core
      GXF::serialization
    PRIVATE
      Spinnaker
)


# main executable

add_executable(
  custom_operator_viz
  custom_operator_viz.cpp
)
target_link_libraries(
  custom_operator_viz
  PUBLIC
  holoscan::core
  custom_op
  holoscan::ops::holoviz
)


# copy config file

install(
  FILES "${CMAKE_CURRENT_SOURCE_DIR}/custom_op_config.yaml"
  DESTINATION $<TARGET_FILE_DIR:custom_operator_viz>
)