import os
from glob import glob
from setuptools import setup

package_name = 'tf2_python_package'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'),
         glob(os.path.join('launch', '*.launch.py'))),

    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='jishnu',
    maintainer_email='jishnusurajila@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "static_turtle_tf2_broadcaster = tf2_python_package.stf_publisher:main",
            "turtle_tf2_broadcaster = tf2_python_package.dtf_broadcaster:main",
            "turtle_tf2_listener = tf2_python_package.turtle_tf2_listener:main",
        ],
    },
)
