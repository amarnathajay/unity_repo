Project Name
Autonomous car with path detection andobstacle avoidance

Team Name - MAL
Short Name - MAL

Youtube video link
https://youtu.be/i3IUZcv9RsM

Course
ECE 573 - Software Engineering Concepts
Spring 2017

Instructor
Matt Bunting

Team Members
Ajay Satishkumar Amarnath (amarnathajay@email.arizona.edu)
Lenny Lopez (lennylopez17@email.arizona.edu)
Megha Agarwal (meghaagarwal@email.arizona.edu)
______________________________________________________________________________________________________________________
Contents
1. Description
2. Installation Instructions
3. Running the code
4. Running the tests
______________________________________________________________________________________________________________________
Description
Automobiles have been constantly evolving ever since the introduction of the first automo-
bile in 1807. However, the one thing that has remained constant is the need for a driver
to operate the automobile. This is the reason that in recent times, there has been a desire
to reduce the dependence on drivers and introduce semi-autonomous and autonomous cars.
This could be one of the most significant and important changes in the automotive industry.
Well implemented autonomous cars have the potential to be extremely safe, well beyond
the capacity of the average human driver as well as make journeys a lot more efficient and
comfortable. Practically speaking, however, there must be an increase in the system capa-
bilities to be able to handle all the aspects of driving with a minimal margin of error. As
these systems gradually improve, we will see the role of the driver eventually become like
one of an aircraft pilot. The driver would only set the parameters of the journey like setting
the start and end points and leave the control to the computer which would interface with
the series of sensors connected and handle the driving aspect. There are many scenarios to
which autonomous driving can be applied. We discuss one such scenario below.
Our approach to this problem deals with cars that may be autonomous in the off-road ter-
rain. We take a car that may need to move from point A to point B in a certain off-road
area. Taking the example of the typical rocky desert terrain of Southern Arizona, we see that
there may be large rocks, protected cacti as well as terrain that cannot be climbed straight
on like cliffs. To move in the best possible path from point A to point B, we would need to
be aware of the position as well as the size of the obstacles that we encounter.
As we encounter obstacles in the range of the car, we store their dimensions and position
and decide on which direction we would need to move. Based on the information that we
have at that moment in time, we decide on the direction of the movement of the car using
a pathfinding algorithm. Our aim in this project is to find the best possible path between
two points in an uneven terrain by traversing through, discovering the obstacles and moving
around them.
If a system like this is brought to the market, we will see a great reduction in off-road acci-
dents, greater efficiency of fuel consumption and improved ease of use. This will also make
applications like hiker rescue much easier and improve the accessibility of locations.
______________________________________________________________________________________________________________________
Installation

1. Open terminal
2. use command 'cd' to change to the home directory of the user
3*. Clone the repository by using git clone git@git.engr.arizona.edu:ece473-573-2017S/mal.git
4. cd mal/FinalRelease
5. catkin_make
6. source devel/setup.bash

*You can alternately download the directory from the repository manually
______________________________________________________________________________________________________________________


Running the code
To run the point to point movement part of the code
1. Complete the installation shown above
2. Open terminal
3. source devel/setup.bash
4. roslaunch pathfinder betarelease_world.launch
5. Open new tab
6. source devel/setup.bash
7. 'gzclient' or 'rosrun rviz rviz' (to visualize the catvehicle)
8. Open new tab
9. source devel/setup.bash
10. roslaunch pathfinder finalrelease_path.launch
______________________________________________________________________________________________________________________

Running the tests

There are 4 test source and launch files along with 3 test world files which together covers all the 6 requirements of our project. In order to run all the tests, follow the following steps:

1. Open terminal
2. cd ~/mal/FinalRelease/
3. catkin_make
4. source devel/setup.bash
5. catkin_make run_tests

test12: Covers requirement 1 and 2. Uses a test world file (world_test12.world) with a single object of known dimensions and coordinates and runs the simplesolution node to determine the coordinates of the detections and the number of detections to make sure that the coordinates fall within a certain error limit of the original coordinates and the number of detections matches 1 (since single object is present in the world file).

test34_1: Covers part of the requirements 3 and 4. Uses a test world file (world_test34.world) with a single big object of known coordinates and runs the pathfinder node with the end coordinates enclosed within the big object and checks whether the node returns a no path found. If it does then the test passes and vice-versa.

test34_2: Covers rest of the part of the requirements 3 and 4. Uses the test12 world file (world_test12.world) and runs the pathfinder node and checks whether the node returns a path found. If it does then the test passes and vice-versa.

test56: Covers requirement 5 and 6. Uses a test world file (world_test56.world) with no objects and runs the pathfinder node with the initial and final coordinates and compares the distance and time values outputted to the expected distance and time values. If the outputs are within a certain percent of the expected output then the test passes.
______________________________________________________________________________________________________________________
