# C++ Python bindings
![Status: in progress](https://img.shields.io/badge/Status-in%20progress-blue) 

Project shows way to make C++ bindings for python using cython and pybind11, which divide C++ libraries 
from Python packages and bindings. That structure makes it possible to reuse created code in C++ and also in Python.
The project also uses [scikit-build](https://github.com/scikit-build/scikit-build) to build Python packages with cmake.

## Project structure
```bash
CMakeLists.txt
├── examples # Examples folder contain examples of C++ which should 
|   |        # be wrapp up to Python package
│   ├── CMakeLists.txt
│   ├── cython_example
│   │   ├── CMakeLists.txt
│   │   ├── include
│   │   │   └── cython_example
│   │   │       ├── player.h
│   │   │       └── simple_functions.h
│   │   └── src
│   │       ├── player.cpp
│   │       └── simple_functions.cpp
│   └── pybind11_example
│       ├── CMakeLists.txt
│       ├── include
│       │   └── pybind11_example
│       │       ├── player.h
│       │       └── simple_functions.h
│       └── src
│           ├── player.cpp
│           └── simple_functions.cpp
├── lib # contain external as well as internal libraries
│   ├── CMakeLists.txt
│   └── pybind11
├── python # Python folder contain of all python packages 
|   |      # and bindings
│   ├── CMakeLists.txt
│   ├── cython_example # bindings
│   │   ├── CMakeLists.txt
│   │   ├── __init__.py
│   │   └── simple_functions.pyx
│   ├── pybind11_example # bindings
│   │   ├── CMakeLists.txt
│   │   ├── __init__.py
│   │   └── simple_functions_py.cpp
├── scripts # Here all bash or other scripts should be put in.
│   └── setup.sh
└── setup.py
```

## Setup && Run
1. Create virtual env (I highly recommend conda but it's up to you)
```bash 
conda create --name=pybind python=3.8
conda acitvate pybind
```
2. Install Python packages
```bash
git clone https://github.com/RocketFan/python_bindings.git --recursive
cd python_bindings
pip install -r requirements.txt
pip install .
```

The project is now only available to run each of the bind examples at the same time
which is caused by cmake library naming conflict (I am still trying to find walk around).  

To change bind example: 
```bash
cd python
vim CMakeLists.txt
```
```cmake
cmake_minimum_required(VERSION 3.4)

# To change bind example:
add_subdirectory(pybind11_example) # comment this line
# add_subdirectory(cython_example) # uncomment this line
```

3. Test
```bash
cd python/test_examples
python <bind_example>_test.py
```
