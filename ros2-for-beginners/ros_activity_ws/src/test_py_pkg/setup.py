from setuptools import setup

package_name = 'test_py_pkg'

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
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "number_publisher = test_py_pkg.number_publisher:main",
            "number_counter = test_py_pkg.number_counter:main",
            "led_panel_node = test_py_pkg.led_panel_node:main",
            "battery_node = test_py_pkg.battery_node:main"
        ],
    },
)
