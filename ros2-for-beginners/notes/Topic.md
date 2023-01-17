# Topic
A named bus over which the nodes exchange messages.
- Here the data is unidirectional (always from publisher to the subscriber via a topic)
- publisher and subscriber are anonymous
- both publisher and subscriber should have use the message type of the topic inorder to send and receive data.(a topic as a message type)
- a node can have many publisher and subscriber from any number of topics


## Debugging topic with command line tools 

ROS2 provides various cli tools for debugging topics in a package. This mainly comes with the `ros2 topic` command's parameters/options/flags

The common options and their uses are list below

- `ros2 topic [options]`
    1. list - list all the currently available topics.
    2. info - give the informations about the mentioned topic, takes in arguement as the topic name.
    3. echo - print the message published by a node.
    4. type - display the type of message published by a node.
    5. hz - display the publishing frequency for a topic.
    6. bw - display the bandwidth.
    7. pub - publish message direcly in to a topic from the command line.