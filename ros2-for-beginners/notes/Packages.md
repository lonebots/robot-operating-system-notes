# Package :

Packages are containers for the code that we write. It can be created using two build types namely :

- ament_cmake --> for C++
- ament_python --> for python

The basics folder structure for both the build types differs from each other and some of the common files that we can find in both of them are following

1. package.xml

Other folder structure is given below

**C++ package**

```
    |--> include/
            |--> <package_name>/
    |--> src/
    |--> CMakeList.txt
    |--> package.xml
```

**Python package**

```
    |--> <package_name>/
    |--> resource/
    |--> test/
    |--> package.xml
    |--> setup.cfg
    |--> setup.py
```

### Building a package :

The packages are generally build using the `colcon` build tool, the command for building the package is given below

```bash
colcon build --select-packages <package_name>
```

here use the <package_name> which you are suppose to build, for example lets build the package created earlier both python and C++. here we use `--packages-select` flag to specify the package name that we want to build

```bash
# build python package
colcon build --packages-select my_py_pkg

# build C++ package
colcon build --packages-select my_cpp_pkg
```

### updating changes during Developement time without colcon build!

We can use the `--symlink-install` flag along with `colcon build` command to update the changes that we make in a node to reflect during `ros2 run` without the need of building the package every time we make changes. It works by creating a symlink to the file directly without having the need to build and install the executable inside the package.

- This comes handy during the developement period.
- The command is given below

```bash
colcon build --packages-select my_py_pkg --symlink-install
```

**Note:** when using this flag make sure to make the program file executable using the `chmod +x <file_name>` command else it will result in error.
