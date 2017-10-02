# About
This seed project gives a starting point to begin working on Task 3 of the CAT Vehicle Challenge

# Get started
Make sure to follow the information on the CPS-VO to install the dependency packages (http://cps-vo.org/group/CATVehicleChallenge)

## Install the CAT Vehicle Simulator
First, make a new workspace and initialize it, then add the catvehicle git repository:
```
cd ~
mkdir -p cvchallenge_task3_ws/src
cd cvchallenge_task3_ws/src
catkin_init_workspace
git clone https://github.com/sprinkjm/catvehicle.git
git clone https://github.com/sprinkjm/catvehicle_simulink.git
git clone https://github.com/sprinkjm/obstaclestopper.git
git clone https://github.com/sprinkjm/cvchallenge_task3.git
```
If you have need of other repositories, go ahead and clone them here. 

## How to run this seed
You will want to open up the catvehicle_simulink/stopafterdistance.slx file, and generate code into this workspace for the launch file to work. After you generate the code:
```
./build_ros_model.sh stopafterdistance.tgz ~/cvchallenge_task3_ws
```

You will want to launch into a less interesting world for the default seed: if you have your own velocity controllers, use whatever world you like. Otherwise, we suggest creating a world that has objects around the circle that the hoffmannfollower follows (see world5.world in this seed).
```
cd ~/cvchallenge_task3_ws/
catkin_make
source devel/setup.bash
roslaunch cvchallenge_task3 catvehicle_custom.launch worldfile:=world5.world
```
Obviously (or not?) you could still run worldfiles from other task packages you have. In a new tab:
```
cd ~/cvchallenge_task3_ws
source devel/setup.bash
rosrun rviz rviz
```
Once you have loaded the vehicle and can see its sensor data, you can now run the task3.launch to see how the car drives around. 

```
cd ~/cvchallenge_task3_ws
source devel/setup.bash
roslaunch cvchallenge_task3 task3.launch
```
This will fail if you have not generated the code for the hoffmannfollower and for the stopafterdistance models above.

# What do you do next?
Add your task2 solution that generated detections into the launch file, and your task3 solution that listens for a velocity of 0 and then publishes your Gazebo world. That's it!

When submitting task3, you will be archiving this seed alongside any other packages and/or nodes you create or need.

Good luck!

# Acknowledgments

## License
Copyright (c) 2016-2017 Arizona Board of Regents
All rights reserved

Permission is hereby granted, without written agreement and without 
license or royalty fees, to use, copy, modify, and distribute this
software and its documentation for any purpose, provided that the 
above copyright notice and the following two paragraphs appear in 
all copies of this software.
 
IN NO EVENT SHALL THE ARIZONA BOARD OF REGENTS BE LIABLE TO ANY PARTY 
FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES 
ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN 
IF THE ARIZONA BOARD OF REGENTS HAS BEEN ADVISED OF THE POSSIBILITY OF 
SUCH DAMAGE.

THE ARIZONA BOARD OF REGENTS SPECIFICALLY DISCLAIMS ANY WARRANTIES, 
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY 
AND FITNESS FOR A PARTICULAR PURPOSE. THE SOFTWARE PROVIDED HEREUNDER
IS ON AN "AS IS" BASIS, AND THE ARIZONA BOARD OF REGENTS HAS NO OBLIGATION
TO PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.

## Authors
* Jonathan Sprinkle (sprinkjm@email.arizona.edu)

## Support
This work was supported by the project "Cyber-Physical Systems Virtual Organization: Active Resources" NSF 1521617. Any opinions, findings, and conclusions or recommendations expressed in this material are those of the author(s) and do not necessarily reflect the views of the National Science Foundation. Additional support for the CAT Vehicle Challenge is provided by MathWorks.
