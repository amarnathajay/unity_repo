#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block stopafterdistance/Subscribe
extern SimulinkSubscriber<nav_msgs::Odometry, SL_Bus_stopafterdistance_nav_msgs_Odometry> Sub_stopafterdistance_1;

// For Block stopafterdistance/Subscribe1
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_stopafterdistance_geometry_msgs_Twist> Sub_stopafterdistance_33;

// For Block stopafterdistance/Publish
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_stopafterdistance_geometry_msgs_Twist> Pub_stopafterdistance_35;

void slros_node_init(int argc, char** argv);

#endif
