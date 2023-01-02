from setuptools import find_packages
from setuptools import setup

setup(
    name='turtorial_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('turtorial_interfaces', 'turtorial_interfaces.*')),
)
