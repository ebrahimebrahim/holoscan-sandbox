cmake_minimum_required(VERSION 3.21)
project(video-replayer)
find_package(holoscan REQUIRED CONFIG PATHS "/opt/nvidia/holoscan")

add_executable(
  video_replayer
  video_replayer.cpp
)
target_link_libraries(
  video_replayer
  PUBLIC
  holoscan::core
  holoscan::ops::video_stream_replayer
  holoscan::ops::holoviz
)

install(
  FILES "${CMAKE_CURRENT_SOURCE_DIR}/replayer_config.yaml"
  DESTINATION $<TARGET_FILE_DIR:video_replayer>
)