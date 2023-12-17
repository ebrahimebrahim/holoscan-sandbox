This is a duplicate of the video-replayer example except the operator definition has been moved to the local project.
The purpose of this is to show how a build system can compile a locally defined operator to a library which can then be linked against by the project's holoscan application.

This is meant to be built directly on an NVIDIA AGX devkit, as a demo of a standalone C++ application that can be built on the device.
It is assumed that the device has the holoscan SDK deb pacakage installed, i.e. at `/opt/nvidia/holoscan`.

```sh
mkdir build
cd build
cmake ..
make install
./custom_operator_viz
```
