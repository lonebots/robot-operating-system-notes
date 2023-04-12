# Actions

- A communication type in ROS (built on top of topics and services).
- used for long running task.
- Three major parts :
  - Goal
  - Feedback
  - Result
- It gives a steady feedback to the client until the goal is completed.
- It can be cancelled in the middle of execution*.
- better described via a client/server model :
  - Action server
  - ACtion client

## General Action Commands

```bash
ros2 node info /<node_name>           # display all the informations regarding the node.

ros2 action list                      # list all the actions currently running.

ros2 action list -t                   # -t , flag for listing the action type along with the action name.

ros2 action infor <action_name>       # list action details, action servers, clients etc.

ros2 interface show <action_name>     # list info of interface of mentioned action.

ros2 action send_goal <action_name> <action_type> <values>  # send action goal from the command line.

```
