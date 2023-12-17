This is built mostly following the tutorial [here](https://docs.nvidia.com/holoscan/sdk-user-guide/examples/video_replayer.html).

It is meant to be built directly on an NVIDIA AGX devkit, as a demo of a standalone C++ application that can be built on the device.
It is assumed that the device has the holoscan SDK deb pacakage installed, i.e. at `/opt/nvidia/holoscan`.

```sh
mkdir build
cd build
cmake ..
make install
./video_replayer
```