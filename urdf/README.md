## URDF - Uniform Robot Description Format

- xml based file, with extension `.urdf` and used to specify the visual, collision and inertial properties of different parts of a robot.
- parts -> aka `links`
- links are connected using joins -> `joint`

#### Links

- Main properties defined under this tag
  - `visual properites`
    - geometry (box, cylinder, sphere), origin, material
  - `Inertial properties`
    - defines the mass and its distribution
    - usefull for physics engine in the simulation softwares.
  - `Collision properties`
    - specify the collision detection properties of the robot
    - Contact coefficients
      - decides how the system behave when links come in contact 
      - Friction, Dampening, Stiffness coefficients. 
  
### Joints
- Defines how the links are connected and specifies the tranforms wrt the `base_link`.
- extras : `Caliberation` and `safety controller`. 

Note : The urdf transforms are published and made available to other parts of the system using the `joint state publisher`. It computes the relative change in the links when one or multiple part move(s).

## XACRO

- acronym for XML macro.
- Mainly used for two purpose :
  - Split the code in to multiple files, for easy maintainance.
  - avoid rewriting and promote reusing code.

The common base on spliting urdf can be following

- Core robot(links and joints).
- List of materials to used for display.
- Sensor links/joints and their corresponding gazebo points.
- Macros
