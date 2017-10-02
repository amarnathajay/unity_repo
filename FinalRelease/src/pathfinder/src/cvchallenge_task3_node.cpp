//Author: Megha Agarwal

//Includes all the header files.
#include "ros/ros.h"
#include "geometry_msgs/PolygonStamped.h"
#include "std_msgs/Bool.h"
#include "std_msgs/String.h"
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstdlib>

using namespace std;

vector<geometry_msgs::Point32> points;

//Callback method for the /detections subscriber.
void detectionsCallback(const geometry_msgs::PolygonStamped::ConstPtr& msg)
{
  points.push_back(msg->polygon.points[0]);
}

//Callback method for the /doit subscriber.
void doItCallback(const std_msgs::Bool::ConstPtr& msg)
{
  if(msg->data == true) {
    ROS_INFO_STREAM("Generating World File");
    ofstream outputFile;
    outputFile.open("myworld.world");
    outputFile << "<?xml version=\"1.0\" ?>" << endl;
    outputFile << "<sdf version=\"1.4\">" << endl;
    outputFile << "<world name=\"default\">" << endl;
    outputFile << "<include><uri>model://ground_plane</uri><name>ground_plane</name></include>" << endl;
    outputFile << "<include><uri>model://sun</uri><name>sun</name></include>" << endl;
    for(int i=0;i<points.size();i++) {
      outputFile << "<include><uri>model://number1</uri><name>number1</name><pose>" << points[i].x << " " << points[i].y << " " << points[i].z << " 0 0 0</pose></include>" << endl;
    }
  outputFile << "</world>" << endl;
  outputFile << "</sdf>" << endl;
  outputFile.close();
  }
}

int main(int argc, char **argv)
{
  //Initializing the ros node.
  ros::init(argc, argv, "cvchallenge_task3_node");

  ros::NodeHandle n("~");

  //Subscribing to detections topic.
  ros::Subscriber detections_sub = n.subscribe("/detections", 1000, detectionsCallback);

  //Subscribing to doit topic.
  ros::Subscriber doIt_sub = n.subscribe("/doIt", 1000, doItCallback);

  ros::Rate loop_rate(1);

  while (ros::ok())
  {
    ros::spinOnce();

    loop_rate.sleep();
  }

  return 0;
}
