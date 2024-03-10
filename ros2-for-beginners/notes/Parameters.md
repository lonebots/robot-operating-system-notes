# Paramters in ROS

[ref](https://docs.ros.org/en/humble/Concepts/Basic/About-Parameters.html)

- These are prorperties associated with individual nodes.
- It configures the node at startup(or during runtime) without changes in code.
- Node can be implemented to persist values of parameters on reload
- It's address by node name, paramter name, node namespace and parameter namespace (optional)
- has as `key : value` and a `descriptor`. 

#### Types: 
- By default parameter type cannot be changed during runtime.
    - it can be changed by setting `dynamic_typing : true` in code during declaration.

#### Callbacks (optional) : 
- Two types of paramter callbacks 
    - **set parameter** callback 
        - enables the ability to inspect the upcoming changes to a parameter and explicitly reject the changes 
        - can be set by calling `add_on_set_parameter_callback`.

    - **on parameter event** callback 
        - called after all parameters in the input event have been declared, changed, or deleted. 
        - used react to changes on a parameter that are successfully accepted.
        - can be set by calling `on_parameter_event`.

#### Interactions 
- Done via parameter events, which are automactically created on instantiating a node.
    - Eg : `get_parameters`, `get_parameter_types`, `set_parameters`, `set_parameters_automatically`, `describe_parameters`, `list_parameters`

#### Setting initial values 
- can be set using `command line`or `yaml` file durning run or launch time.
- Manipulating parameters at run-time can be handled using `ros2 param` cmd line tool.

Notes : 
    - Global parameter blackboard is not available in ROS2 
    - It was available in ROS1 and was handled by `roscore`
    - paramter blackboard : a centralized parameter getter and setter for all nodes. 
    - In ROS2 this can be achieved by manually running `parameter_blackboard` from `demo_node_cpp` package.