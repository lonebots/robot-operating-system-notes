# ROS2 Parameters

- The configuration value for a node which is used to set different settings in the node is known as a **parameter**.
- We should declare those parameters in the code and the values are assigned during the **runtime**.
- We don't need to compile the node every time, since the parameter values are provided at the run time and it is specific to a node.
- A ros2 parameter has a name and a data type.
- The informations about the parameters of the currently running node can be understood using the following commands;
- Using parameters makes the application more **scalable**.

```bash
ros2 param list # list all the parameters
ros2 param delete
ros2 param describe
ros2 param dump
ros2 param get
ros2 param list
ros2 param load
ros2 param set
```

## Declaring a parameter :

We can declare a parameter within a node using the `Node.declare_parameter(parameter_name, default_value)` method.

## Get parameter

We can get the value of a parametere within a node using `Node.get_parameter(parameter_name).value` method.
