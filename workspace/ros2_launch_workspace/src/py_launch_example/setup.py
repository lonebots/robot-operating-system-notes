import os
from glob import glob
from setuptools import setup

package_name = "py_launch_example"

setup(
    # Other parameters ...
    data_files=[
        # ... Other data files
        # Include all launch files.
        (os.path.join("share", package_name), glob("launch/*launch.[pxy][yma]*"))
    ]
)
