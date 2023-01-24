# ROS bag file

Bag files are used to store data that are published by topic on running a particular node. These informations are usefull for

- debugging
- replay the recorded data

The database inside the file is **Sqllite**

### Command used

The command used to access the `bag`s in ROS2 are following.

- once a bag file start recording, it creates a subscriber to the topic mentioned in the command.
- we can also record multiple topics at the same time.

```bash
ros2 bag -h # for help

 # convert  Given an input bag, write out a new bag with different settings
 # info     Print information about a bag to the screen
 # list     Print information about available plugins to the screen
 # play     Play back ROS data from a bag
 # record   Record ROS data to a bag
 # reindex  Reconstruct metadata file for a bag

# run number_publisher node and then run below command

ros2 bag record /number -o number_data
 # -o is used to specify the output file name
```
