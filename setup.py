# -*- coding: utf-8 -*-

from __future__ import print_function

import sys
from glob import glob

try:
    from skbuild import setup
except ImportError:
    print(
        "Please update pip, you need pip 10 or greater,\n"
        " or you need to install the PEP 518 requirements in pyproject.toml yourself",
        file=sys.stderr,
    )
    raise

from setuptools import find_packages


setup(
    name="python_bindings",
    version="0.0.1",
    packages=find_packages(where='python'),
    package_dir={"": "python"},
    # cmake_install_dir="python/cython_example",
    include_package_data = True,
    # extras_require={"test": ["pytest"]},
)