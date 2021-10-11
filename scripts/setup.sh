#!/bin/bash
# Generates .pyi files for better autocomplete

PYTHON_SITE_PACKAGES_PATH=`python -c 'import sysconfig; print(sysconfig.get_paths()["purelib"])'`
echo $PYTHON_SITE_PACKAGES_PATH
stubgen -p pybind11_example -o $PYTHON_SITE_PACKAGES_PATH