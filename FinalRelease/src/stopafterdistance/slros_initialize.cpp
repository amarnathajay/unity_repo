#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "stopafterdistance";

// For Block stopafterdistance/Subscribe
SimulinkSubscriber<nav_msgs::Odometry, SL_Bus_stopafterdistance_nav_msgs_Odometry> Sub_stopafterdistance_1;

// For Block stopafterdistance/Subscribe1
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_stopafterdistance_geometry_msgs_Twist> Sub_stopafterdistance_33;

// For Block stopafterdistance/Publish
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_stopafterdistance_geometry_msgs_Twist> Pub_stopafterdistance_35;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

