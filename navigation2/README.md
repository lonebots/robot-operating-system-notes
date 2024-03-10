# Navigation Stack or Nav2

### Behaviour Tree

- Used in most of the complex robotics task.
- tree structure of the tasks that are to be completed.

### Navigation Server

**Major types of navigation servers :**

- Planners : plan the optimal way to complete the objective function.
- Controllers : local planner that optimize local subtask to reach the global goal.
- behaviors : used to get the robot out of a bad situation.
- Smoother : additional quality improvements, additional path refinements.

**Waypoint Following :**

- tells our system how to use navigation to get to multiple destinations.
- **nav2_waypoint_follower**  

**CostMap layer:**

- It is the current environmental representation.
- 2D grid containing cost from unknown, free, occupied or inflated cost.

**CostMap Filter :**

- The anotated map is called a `filter mask`.
- anotation may be regarding :
  - keep out zone to avoid planning inside
  - have pixel belong to maximum speeds in marked areas
- main feature : is to provide an ability of marking areas on maps with some additional features or behavioural changes.

`Costmap filters` - is costmap layer based approach of applying spatial-dependent behavioral changes annotated in filter masks, into Nav2 stack

- implemented as costmap `plugins` aka `filters`.
- The robot's behavioral change is accomplished by using filter plugins to read data from the filter mask ( the data is being linearly transformed in to feature map in a filter space.)
- Then robot change it's behavior according to it's current coordinate filters along with the transformed feature map, map/costmap, sensor data etc.

**Other forms of environmental representation :**

- gradient maps
- 3D costmaps
- Mesh maps
- Vector space
