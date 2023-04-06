# Tranforms in ROS2

### Tranforms (Coordinate Tranformation)

- The position and orientation of robots in space (2D or 3D) needs to be defined( done using `frames`).
- This helps in understanding the relative position of different parts within a robot or one robot with other robots in its premise.
- `Tranforms` are mathematical tool that defines how we change from one frame to another frame.
- Frames consist of `x`,`y` and `z` axis usually respresented using `red`, `green` and `blue` colours respectively.
- The defined tranforms forms a `tree` structure, to avoid conflicts.
  - Each frame is defined with respect to only one another frame.
  - Each frame has only one arrow pointing towards it.
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

1. 