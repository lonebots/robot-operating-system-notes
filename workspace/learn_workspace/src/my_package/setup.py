from setuptools import setup

package_name = "my_package"

setup(
    name=package_name,
    version="0.0.0",
    packages=[package_name],
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml"]),
    ],
    install_requires=["setuptools"],
    zip_safe=True,
    maintainer="jishnu",
    maintainer_email="jishnusurajila@gmail.com",
    description="Beginner client libraries tutorials practice package",
    license="Apache License 2.0",
    tests_require=["pytest"],
    entry_points={
        "console_scripts": ["my_node = my_package.my_node:main"],
    },
)
