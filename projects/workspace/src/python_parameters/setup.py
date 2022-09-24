from setuptools import setup

package_name = 'python_parameters'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='jishnu',
    maintainer_email='jishnusurajila@gmail.com',
    description='python parameters implementation',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'param_talker = python_parameters:python_parameters_node:main',
        ],
    },
)
