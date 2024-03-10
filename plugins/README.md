# Plugin in ROS2

- **Plugin** : 
    - dynamically loadable classes that are loaded from a runtime library(shared objects/ dynamically linked libraries).
    - we use a C++ library called `pluginlib`. Enables to use external classes without explicitly linking libraries.


#### Add a custom plugin 

- create base class package 
    - define abstract base class header file (virtual functions),
    - make it available to the other packages by specifying `install` and `ament_export_include_directories` 
- create the plugin package
    - define the plugin source
        - important part is given below.  
        - it registers the classes as actual plugins.
        ```cpp

        #include <pluginlib/class_list_macros.hpp>
        PLUGINLIB_EXPORT_CLASS(fully_qualified_plugin_class, fully_qualified_base_class)
        ```

        - provide plugin declaration in xml file within the package
            - this allows a way to find that library and to know what to reference within than library. 

            ```xml
            <libary path="relative__path_to_library">
                <class type="fully_qualified_plugin_class" base_class_type="fully_qualified_base_class">
                    <description> some_actual_description_for_the_plugin </description>
                </class>
            </library>
            ```

        - register the above `.xml` file in `CmakeList.txt` file of plugin package
            ```txt
            pluginlib_export_plugin_description_file(pkg_name path/to/xml_file)
            ```

        - The plugin is ready to use any of the other classes 
        - The loading of the plugin class is automatically handled by the `pluginlib` C++ library.

#### Use the plugin 

- In any regular class use the `pluginlib::ClassLoader` to create a `loader` for the plugin 
    - it is templated with the `<base_class>` and loader is passed with two additional paramters 
        1. pkg name of the base_class
        2. fully qualified base class type for the plugin 

        ```cpp
            pluginlib::ClassLoader<polygon_base::RegularPolygon> poly_loader("polygon_base", "polygon_base::RegularPolygon");
        ```

    - The plugin instances are created using this loader as given below using regular `std:shared_ptr` and loader's `createSharedInstance` method

Note : 
    The class in which the plugin is used doesn't have any dependencies on the class which the actual plugin is defined. It is dynamically loaded and also parameters can also be used here.

#### Build and run 

- build the packages with `colcon build` and run them using `ros2 run` commands respectively after sourcing properly.