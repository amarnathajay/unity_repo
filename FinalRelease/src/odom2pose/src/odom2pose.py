#!/usr/bin/env python

# Author: Jonathan Sprinkle
# Copyright (c) 2017 Arizona Board of Regents
# All rights reserved
#
# Permission is hereby granted, without written agreement and without 
# license or royalty fees, to use, copy, modify, and distribute this
# software and its documentation for any purpose, provided that the 
# above copyright notice and the following two paragraphs appear in 
# all copies of this software.
# 
# IN NO EVENT SHALL THE ARIZONA BOARD OF REGENTS BE LIABLE TO ANY PARTY 
# FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES 
# ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN 
# IF THE ARIZONA BOARD OF REGENTS HAS BEEN ADVISED OF THE POSSIBILITY OF 
# SUCH DAMAGE.
# 
# THE ARIZONA BOARD OF REGENTS SPECIFICALLY DISCLAIMS ANY WARRANTIES, 
# INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY 
# AND FITNESS FOR A PARTICULAR PURPOSE. THE SOFTWARE PROVIDED HEREUNDER
# IS ON AN "AS IS" BASIS, AND THE ARIZONA BOARD OF REGENTS HAS NO OBLIGATION
# TO PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.

# What does this file do?
# THE purpose of this file is to transform an odometry message into a turtlesim
# pose message, to enable code prototyped to use the turtlesim
# to be applied to a different robot that uses pose style messages.

import rospy
import math
from math import sin, cos, floor, ceil
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Pose
from turtlesim.msg import Pose
import sys, getopt, tf, tf.transformations

class odom2pose:

    def __init__(self):
        rospy.init_node('odom2pose', anonymous=True)

        self.ns_odom = rospy.get_param("~ns_odom","catvehicle")
        self.ns_pose = rospy.get_param("~ns_pose","turtle1")
        self.velmax = rospy.get_param("~velmax",3)

        self.pose = Pose()
        self.odom = Odometry()

        rospy.loginfo(rospy.get_caller_id() + " startup in ns_odom={0},ns_pose={1}".format(self.ns_odom,self.ns_pose))

        rospy.Subscriber('{0}/odom'.format(self.ns_odom), Odometry, self.callback)
        self.pub = rospy.Publisher('{0}/pose'.format(self.ns_pose), Pose, queue_size=1)

        # the pose information that gets overwritten
        self.pose.x = 0
        self.pose.y = 0
        self.pose.theta = 0
        self.pose.linear_velocity = 0
        self.pose.angular_velocity = 0

    def callback(self,message):
        # takes information from odometry and passes it along
        self.pose.x = message.pose.pose.position.x
        self.pose.y = message.pose.pose.position.y

        # get angular pose by using quaternion math
        _O = message.pose.pose.orientation
        quaternion = (_O.x,_O.y,_O.z,_O.w)
        euler = tf.transformations.euler_from_quaternion(quaternion)
        self.pose.theta = euler[2]
        # in order to be like the turtle, we must always be betwen [0,2*pi)
        if self.pose.theta < 0:
            self.pose.theta = self.pose.theta + 2*math.pi
        elif self.pose.theta > 2*math.pi:
            self.pose.theta = self.pospe.theta - 2*math.pi

        # get twist information (which is in x/y) and get the norm to turn it 
        # into linear velocity
        xdot = message.twist.twist.linear.x
        ydot = message.twist.twist.linear.y
        self.pose.linear_velocity = math.sqrt(xdot**2 + ydot**2)

        # get angular velocity by taking directly from the message
        self.pose.angular_velocity = message.twist.twist.angular.z

        self.pub.publish(self.pose)


def main(argv):

    node = odom2pose()
    rate = rospy.Rate(1) # run at 1Hz
    while not rospy.is_shutdown():
#        node.publish()
        rate.sleep()

if __name__ == '__main__':
    main(sys.argv[1:])
