# Node

Node is the basic unit of a ros program. It handles everthing related to a particular part of a robot for eg, a gear-mortor, servo, sensor, camera etc.

Nodes make it easy to handle things related to single entity or object

Take an example of a camera pkg it may contain the following node
- camera driver node : for capturing the image
- image processing node : to do the basic image processing job
- some more extra programs 

For motion planning package we may have
- motion planning node 
- path correction node : continuously interact with the motion planning node. 

For the Hardware control we may have
- state publisher
- Main control loop
- drivers : for handling the motors, controlled by the main control loop

Each node can be launched separately and they communicate each other via topics, sevice or actions. 

### Characteristics of Node
- reduce the code complexity
- Node provide good debugging capablities(fault tolerance)
- support for multiple programming languges
  