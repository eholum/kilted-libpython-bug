# Pixi Kilted Bug

On kilted:

```
# Statically linked...
$ pixi run -e kilted check
✨ Pixi task (check in kilted): bash -c "file ${CONDA_PREFIX}/lib/libunique_identifier_msgs__rosidl_generator_py.so && readelf -d ${CONDA_PREFIX}/lib/libunique_identifier_msgs__rosidl_generator_py.so | grep NEEDED"
/home/parallels/ROS/robostack/kilted-libpython-bug/.pixi/envs/kilted/lib/libunique_identifier_msgs__rosidl_generator_py.so: ELF 64-bit LSB shared object, ARM aarch64, version 1 (SYSV), static-pie linked, not stripped

# See the crash
$ pixi run -e kilted repro
✨ Pixi task (repro in kilted): bash -c "gcc -o test src/main.cpp -ldl -L${CONDA_PREFIX}/lib -Wl,-rpath,${CONDA_PREFIX}/lib && ./test"
dlopen failed: /home/parallels/ROS/robostack/kilted-libpython-bug/.pixi/envs/kilted/lib/libunique_identifier_msgs__rosidl_generator_py.so: undefined symbol: PyObject_GetAttrString
```

On jazzy:

```
# Note the library is dynamically linked
$ pixi run -e jazzy check
✨ Pixi task (check in jazzy): bash -c "file ${CONDA_PREFIX}/lib/libunique_identifier_msgs__rosidl_generator_py.so && readelf -d ${CONDA_PREFIX}/lib/libunique_identifier_msgs__rosidl_generator_py.so | grep NEEDED"
/home/parallels/ROS/robostack/kilted-libpython-bug/.pixi/envs/jazzy/lib/libunique_identifier_msgs__rosidl_generator_py.so: ELF 64-bit LSB shared object, ARM aarch64, version 1 (SYSV), dynamically linked, not stripped
 0x0000000000000001 (NEEDED)             Shared library: [libpython3.12.so.1.0]
 0x0000000000000001 (NEEDED)             Shared library: [libc.so.6]
 0x0000000000000001 (NEEDED)             Shared library: [ld-linux-aarch64.so.1]

# Works fine
$ pixi run -e jazzy repro
✨ Pixi task (repro in jazzy): bash -c "gcc -o test src/main.cpp -ldl -L${CONDA_PREFIX}/lib -Wl,-rpath,${CONDA_PREFIX}/lib && ./test"
OK
```
