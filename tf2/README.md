# Tranforms in ROS2

### Tranforms (Coordinate Tranformation)

- The position and orientation of robots in space (2D or 3D) needs to be defined( done using `frames`).
- This helps in understanding the relative position of different parts within a robot or one robot with other robots in its premise.
- `Tranforms` are mathematical tool that defines how we change from one frame to another frame.
- Frames consist of `x`,`y` and `z` axis usually respresented using `red`, `green` and `blue` colours respectively.
- The defined tranforms forms a `tree` structure, to avoid conflicts.
  - Each frame is defined with respect to only one another frame.
  - Each frame has only one arrow pointing towards it ( arrow pointing from child to parent).
  - The frame doesnot form any closed loops.

The ROS abstract these concepts and the underlying maths to simplify the usage of tranforms with `tf`libraries (tranforms, presently its version 2.0 aka `tf2`) and provides us with easy to use APIs.

Using `tf2`

- Broadcasting and listening to tranforms from one frame to another.
- This creates something we call as a `transform-tree`.
- The tranforms are mainly two types :
  - Static - remains constant wrt time.
  - Dynamic - varies wrt time.
- under the hood, `tf2` uses `topics` and `messages` (`tf` and `tf_static`) for communications.
- We call it `broadcast` and `listen` since we never bother about publishing and subscribing to topics explicitly.

ROS comes with inbuild nodes responsible for common broadcasting tasks (we can create our own custom nodes also).

1. static_transform_publisher : specifies the tranform as in translation and rotations (in rad).

   ```bash
   # example
   # ros2 run tf2_ros static_transform_publisher x y z yaw pitch roll parent_frame child_frame

   # run below commands in separate shells

   ros2 run tf2_ros static_transform_publisher 1 2 0 1.57 0 0 world robot_1     # publishes static transform b/w world and robot_1

   ros2 run tf2_ros static_transform_publisher 1 0 0 0 0 0 robot_1 robot_2      # publishes static transform b/w robot_1 and robot_2

   rviz2                                                                        # run rviz to visualize the transforms

   ```

In order to visualize the frames and transforms set the `fixed frame` to `world` and add `TF` frame to the display. 2. Dynamic Transform : For this we require a urdf file specifying the physical characteristics of the robot's components.

For making this process easier ROS has an in-built node for pubishing all tranforms from a `urdf` file its called the `robot_state_publisher`. It publishes `/tf`, `/tf_static` and `/robot_description`. The **robot_state_publisher** node subscribes to `/joint_state` topic that is published by the real actuators or simulations.

The `robot_state_publisher` node takes in `urdf` file as parameter called the `/robot_description`, we can start that node using below command

```bash
 ros2 run robot_state_publisher robot_state_publisher --ros-args -p robot_description:="$(xacro ./example_robot.urdf.xacro)"

 # open rviz in another terminal
 rviz2

 # change fixed frame : world
 # add TF transform
 # robot model and set topic to /robot_description
```

### Debugging Transformations

We can use `view_frames` as a debugging tool to find out errors in tranforms and frames.
In ROS 1 we had a tool called `rqt_tf_tree` for debugging tranformations but it's not currently supported for ROS2.

```bash
 ros2 run tf2_tools view_frames.py      # runs for 5 sec and produce two files (.pdf, .gv) giving details about the frames and their tranformations as a tree.
```
