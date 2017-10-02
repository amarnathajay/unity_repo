#include <gtest/gtest.h>
//Authors: Ajay Satishkumar Amarnath (amarnathajay@email.arizona.edu), Lenny Lopez (lennylopez17@email.arizona.edu)
/*Script to run the pathfinder algorithm of the catvehicle which will find a path with the euclidean distance
The A* algorithm used in this case finds the shortest path available between two points by using a value known as 'f' which is the cost metric used to determine the path which are 
determined by two other factors known as 'g' and 'h' where 'g' is the cost of movement from the starting point to the current point in the grid (Determined from the world file) and 'h'
is the movement cost that is estimated for the movement from the current point in the grid. 'h' is determined by the heuristic we use and in this case we will be using the euclidean heuristic.
The relationship between 'f', 'g' and 'h' is given by f = g + h.
Source - ECE 506 Reconfigurable computing lectures
*/
//Includes all the header files.
#include "ros/ros.h"
#include "geometry_msgs/PolygonStamped.h"
#include "std_msgs/Bool.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include <bits/stdc++.h>
#include <boost/thread/thread.hpp>

using namespace std;

//variables to store initial point values
float initPosX = 10000; 
float initPosY = 10000;
float initTheta = 0;
bool initPos = false;

//Variables for current catveicle location
float posX = 10000;
float posY = 10000;
float theta = 0;

int result = 0;
float Distance = 0.0;
float Time = 0.0;

//Defining an int pair type in order to store data about the points
typedef pair<int, int> Data;
//Creating a pair type in order to hold the data about the previously defined pair data
typedef pair<double, pair<int, int> > pData;
//Size of the current world
//TODO: Update a and b with the required values generated from the world file
const int a = 100;    //a = number of rows
const int b = 100;    //b = number of columns
int grid[a][b];

Data startPnt = make_pair(10, 10);
 
Data endPnt = make_pair(45, 40);

stack<Data> pathTaken;

//Variables for target position
int targetPosX = endPnt.first;
int targetPosY = endPnt.second;
float targetTheta = 0;
bool targetAreaReached = false;

//Callback to find the current location of the catvehicle
void pose_callback(const turtlesim::Pose& msgIn)
{
	if(!initPos)
	{
		initPosX = msgIn.x;
		initPosY = msgIn.y;
		initTheta = msgIn.theta;
		initPos = true;
		//ROS_INFO_STREAM("Initial Catvehicle position = (" << initPosX << ", " << initPosY << ")\nTheta: " << theta << "\n" );
	}
	posX = msgIn.x;
	posY = msgIn.y;
	theta = msgIn.theta;
	//ROS_INFO_STREAM("Catvehicle position = (" << posX << ", " << posY << ")\nTheta" << theta << "\n");
	
	targetTheta = atan((targetPosY - posY)/(targetPosX - posX));
	//ROS_INFO_STREAM("Target theta = " << targetTheta << "\n");	
}




//Create a structure to hold the data about the points
struct pointDataStructure
{
	//Parent co-ordinate data
	int p_x;
	int p_y;

	//Cost data
	double f;
	double g;
	double h;
};

//Define helper functions to check if certain conditions have been met
//Function 1: Function to check the validity of the point being used where x and y are the co-ordinates of the point being used
bool validPoint(int x, int y)
{
	if ((x >= 0) && (x < a) && (y >= 0) && (y < b))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Function 2: Function to check if an obstacle is present at a given point. If an obstacle is absent, it returns true. If an obstacle is present it returns false.
bool noObstacle(int grid[a][b], int x, int y)
{
	if (grid[x][y] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Function 3: Function to check if the algortihm has reached the end point 
bool endPointReached(int x, int y, Data endPt)
{
	if ((x == endPt.first) && (y == endPt.second))
	{
		return true;
	}
	else 
	{
		return false;
	}
}

//Function 4: Function to compute the distance for the heuristic.
double heuristicDistance(int x, int y, Data endPt)
{
	return ((double)sqrt(pow((x - endPt.first), 2) + pow((y - endPt.second), 2)));
}

//Function 5: Function to output the path from the A* algorithm to the user
void displayPath(pointDataStructure pointDetails[][b], Data endPt)
{
	cout << "\nThe path given by the algorithm is ";
	
	//Use x and y to hold the required values
	int x = endPt.first;
	int y = endPt.second;

	//store the route data points in a stack
	stack<Data> Route;

	//Traverse through the points
	while(!(pointDetails[x][y].p_x == x && pointDetails[x][y].p_y == y))
	{
		Route.push(make_pair(x,y));
		//Store the values in temporary variables because for some reason it does not allow me to assign directly :/
		int xTemp = pointDetails[x][y].p_x;
		int yTemp = pointDetails[x][y].p_y;

		//Set the x and y values
		x = xTemp;
		y = yTemp;
	}

	Route.push(make_pair(x,y));
	pair<int, int> pth;
	pair<int, int> pth2;
	//vector<pair<int,int> > pth2;
	//Print the values from the stack and pop
	pathTaken = Route;
	while(!Route.empty())
	{
		pth = Route.top();
		Route.pop();
		//cout << "--> (" << pth.first << ", " << pth.second << ") " ;
		if(!Route.empty()){
			
			pth2 = Route.top();
		}
		else
			break;
		//Route.pop();
	//	sleep();
		//pth2 = Route.top();
		
		//pth2.push_back(pth); 

		//distance formula
		Distance = Distance + sqrt(pow((pth2.first - pth.first) , 2) + pow((pth2.second - pth.second), 2));
		
	}
	
	/*while(!pth2.empty())
	{
		pair<int, int> pointXY = pth2.back();
		pth2.pop_back();
		cout << "--> (" << pointXY.first << ", " << pointXY.second << ") " ;
		//pair<int, int> pointXY2 = pth2.back();
		//pth2.pop_back();
		
		//Distance = Distance + sqrt(pow((pointXY2.first - pointXY.first) , 2) + pow((pointXY2.second - pointXY.second), 2));
	}*/
	
	//time
	Time = Distance/5.0;
	//printing the final distance
	cout <<"\nDistance = "<<Distance<<endl;
	cout <<"Time = "<<Time<<endl;
	return;
}

//Function to run the A* pathfinding algorithm
void pathfinderAlgorithm(int grid[][b], Data startPt, Data endPt)
{
	//Check if the start point and end point are out of range. It shouldn't be considering we are setting the bounds based on the world but it is a good prcatice to check
	if (!validPoint(startPt.first, startPt.second))
	{
		cout << "Invalid start point" << endl;
		return;
	}

	if (!validPoint(endPt.first, endPt.second))
	{
		cout << "Invalid end point" << endl;
		return;
	}

	//Check if there is an obstacle at the start point or the end point
	if(!noObstacle(grid, startPt.first, startPt.second))
	{
		cout << "There is an obstacle at the start point" << endl;
		return;
	}

	if(!noObstacle(grid, endPt.first, endPt.second))
	{
		cout << "There is an obstacle at the end point" << endl;
		return;
	}

	//Setting up a closed array to signify that no point has been worked on
	bool closedArray[a][b];
	//Initialize them all to false to show that there is no visited node
	memset(closedArray, false, sizeof(closedArray));

	//Making the same dimension array to hold details of each node
	pointDataStructure pointDetails[a][b];

	//flag to help find the destination
	bool endPtFound = false;

	//Variables to help traverse through the data
	int x, y;

	//Initialize all data points to a default value
	for(x = 0; x < a; x++)
	{
		for (y = 0; y < b; y++)
		{
			pointDetails[x][y].f = FLT_MAX;
			pointDetails[x][y].g = FLT_MAX;
			pointDetails[x][y].h = FLT_MAX;

			pointDetails[x][y].p_x = -1;
			pointDetails[x][y].p_y = -1;
		}
	}

	//Set the zero value for the start point
	x = startPt.first;
	y = startPt.second;

	pointDetails[x][y].f = 0.0;
	pointDetails[x][y].g = 0.0;
	pointDetails[x][y].h = 0.0;

	pointDetails[x][y].p_x = x;
	pointDetails[x][y].p_y = y;

	//Creating a list of pairs to keep a track of the potential points to be traversed
	set<pData> openArray;

	openArray.insert(make_pair(0.0, make_pair(x,y)));

	while(!openArray.empty())
	{
		pData pt = *openArray.begin();

		//Remove the old point from the list
		openArray.erase(openArray.begin());

		//Adding the current point to the list
		x = pt.second.first;
		y = pt.second.second;
		closedArray[x][y] = true;

		//There are 8 possible directions of movement based on the x and y coordinates. We cover each possibility in the following section
		//Temporary values of f, g and h for each of the point's successors
		double fSuccessor;
		double gSuccessor;
		double hSuccessor;

		/*Successor point where x decreases and y remains constant*/
		//Check for the validity of the new point in the space
		if (validPoint(x - 1, y))
		{
			//Check if the end point has been reached, stop traversing if end point has been reached
			if (endPointReached(x - 1, y, endPt))
			{
				//End point reached, perform required operations
				pointDetails[x - 1][y].p_x = x;
				pointDetails[x - 1][y].p_y = y;

				cout << "The end point has been found" << endl;
				displayPath(pointDetails, endPt);
				endPtFound = true;
				return;
			}
			else if ((!closedArray[x - 1][y]) && (noObstacle(grid, x - 1, y)))
			{
				//End point not found. Traverse through list and update
				gSuccessor = 1.0 + pointDetails[x][y].g;
				hSuccessor = heuristicDistance(x - 1, y, endPt);
				//f = g + h from the the top comment
				fSuccessor = gSuccessor + hSuccessor;

				//Adding the point to the open list
				if(pointDetails[x - 1][y].f == FLT_MAX || pointDetails[x - 1][y].f > fSuccessor)
				{
					openArray.insert(make_pair(fSuccessor, make_pair(x - 1, y)));

					//Set the point with the new information
					pointDetails[x - 1][y].f = fSuccessor;
					pointDetails[x - 1][y].g = gSuccessor;
					pointDetails[x - 1][y].h = hSuccessor;
					pointDetails[x - 1][y].p_x = x;
					pointDetails[x - 1][y].p_y = y;
				}
			}

		}

		/*Successor point where x increases and y remains constant*/
		if (validPoint(x + 1, y))
		{
			//Check if the end point has been reached, stop traversing if end point has been reached
			if (endPointReached(x + 1, y, endPt))
			{
				//End point reached, perform required operations
				pointDetails[x + 1][y].p_x = x;
				pointDetails[x + 1][y].p_y = y;

				cout << "The end point has been found" << endl;
				displayPath(pointDetails, endPt);
				endPtFound = true;
				return;
			}
			else if ((!closedArray[x + 1][y]) && (noObstacle(grid, x + 1, y)))
			{
				//End point not found. Traverse through list and update
				gSuccessor = 1.0 + pointDetails[x][y].g;
				hSuccessor = heuristicDistance(x + 1, y, endPt);
				//f = g + h from the the top comment
				fSuccessor = gSuccessor + hSuccessor;

				//Adding the point to the open list
				if(pointDetails[x + 1][y].f == FLT_MAX || pointDetails[x + 1][y].f > fSuccessor)
				{
					openArray.insert(make_pair(fSuccessor, make_pair(x + 1, y)));

					//Set the point with the new information
					pointDetails[x + 1][y].f = fSuccessor;
					pointDetails[x + 1][y].g = gSuccessor;
					pointDetails[x + 1][y].h = hSuccessor;
					pointDetails[x + 1][y].p_x = x;
					pointDetails[x + 1][y].p_y = y;
				}
			}

		}


		/*Successor point where x remains constant and y decreases*/
		if (validPoint(x, y - 1))
		{
			//Check if the end point has been reached, stop traversing if end point has been reached
			if (endPointReached(x, y - 1, endPt))
			{
				//End point reached, perform required operations
				pointDetails[x][y - 1].p_x = x;
				pointDetails[x][y - 1].p_y = y;

				cout << "The end point has been found" << endl;
				displayPath(pointDetails, endPt);
				endPtFound = true;
				return;
			}
			else if ((!closedArray[x][y - 1]) && (noObstacle(grid, x, y - 1)))
			{
				//End point not found. Traverse through list and update
				gSuccessor = 1.0 + pointDetails[x][y].g;
				hSuccessor = heuristicDistance(x, y - 1, endPt);
				//f = g + h from the the top comment
				fSuccessor = gSuccessor + hSuccessor;

				//Adding the point to the open list
				if(pointDetails[x][y - 1].f == FLT_MAX || pointDetails[x][y - 1].f > fSuccessor)
				{
					openArray.insert(make_pair(fSuccessor, make_pair(x, y - 1)));

					//Set the point with the new information
					pointDetails[x][y - 1].f = fSuccessor;
					pointDetails[x][y - 1].g = gSuccessor;
					pointDetails[x][y - 1].h = hSuccessor;
					pointDetails[x][y - 1].p_x = x;
					pointDetails[x][y - 1].p_y = y;
				}
			}

		}

		/*Successor point where x remains constant and y increases*/
		if (validPoint(x, y + 1))
		{
			//Check if the end point has been reached, stop traversing if end point has been reached
			if (endPointReached(x, y + 1, endPt))
			{
				//End point reached, perform required operations
				pointDetails[x][y + 1].p_x = x;
				pointDetails[x][y + 1].p_y = y;

				cout << "The end point has been found" << endl;
				displayPath(pointDetails, endPt);
				endPtFound = true;
				return;
			}
			else if ((!closedArray[x][y + 1]) && (noObstacle(grid, x, y + 1)))
			{
				//End point not found. Traverse through list and update
				gSuccessor = 1.0 + pointDetails[x][y].g;
				hSuccessor = heuristicDistance(x, y + 1, endPt);
				//f = g + h from the the top comment
				fSuccessor = gSuccessor + hSuccessor;

				//Adding the point to the open list
				if(pointDetails[x][y + 1].f == FLT_MAX || pointDetails[x][y + 1].f > fSuccessor)
				{
					openArray.insert(make_pair(fSuccessor, make_pair(x, y + 1)));

					//Set the point with the new information
					pointDetails[x][y + 1].f = fSuccessor;
					pointDetails[x][y + 1].g = gSuccessor;
					pointDetails[x][y + 1].h = hSuccessor;
					pointDetails[x][y + 1].p_x = x;
					pointDetails[x][y + 1].p_y = y;
				}
			}

		}

		/*Successor point where x decreases and y increases*/
		if (validPoint(x - 1, y + 1))
		{
			//Check if the end point has been reached, stop traversing if end point has been reached
			if (endPointReached(x - 1, y + 1, endPt))
			{
				//End point reached, perform required operations
				pointDetails[x - 1][y + 1].p_x = x;
				pointDetails[x - 1][y + 1].p_y = y;

				cout << "The end point has been found" << endl;
				displayPath(pointDetails, endPt);
				endPtFound = true;
				return;
			}
			else if ((!closedArray[x - 1][y + 1]) && (noObstacle(grid, x - 1, y + 1)))
			{
				//End point not found. Traverse through list and update
				//Diagonal distance covered is sqrt(2)
				gSuccessor = sqrt(2.0) + pointDetails[x][y].g;
				hSuccessor = heuristicDistance(x - 1, y + 1, endPt);
				//f = g + h from the the top comment
				fSuccessor = gSuccessor + hSuccessor;

				//Adding the point to the open list
				if(pointDetails[x - 1][y + 1].f == FLT_MAX || pointDetails[x - 1][y + 1].f > fSuccessor)
				{
					openArray.insert(make_pair(fSuccessor, make_pair(x - 1, y + 1)));

					//Set the point with the new information
					pointDetails[x - 1][y + 1].f = fSuccessor;
					pointDetails[x - 1][y + 1].g = gSuccessor;
					pointDetails[x - 1][y + 1].h = hSuccessor;
					pointDetails[x - 1][y + 1].p_x = x;
					pointDetails[x - 1][y + 1].p_y = y;
				}
			}

		}	


		/*Successor point where x decreases and y decreases*/
		if (validPoint(x - 1, y - 1))
		{
			//Check if the end point has been reached, stop traversing if end point has been reached
			if (endPointReached(x - 1, y - 1, endPt))
			{
				//End point reached, perform required operations
				pointDetails[x - 1][y - 1].p_x = x;
				pointDetails[x - 1][y - 1].p_y = y;

				cout << "The end point has been found" << endl;
				displayPath(pointDetails, endPt);
				endPtFound = true;
				return;
			}
			else if ((!closedArray[x - 1][y - 1]) && (noObstacle(grid, x - 1, y - 1)))
			{
				//End point not found. Traverse through list and update
				//Diagonal distance covered is sqrt(2)
				gSuccessor = sqrt(2.0) + pointDetails[x][y].g;
				hSuccessor = heuristicDistance(x - 1, y - 1, endPt);
				//f = g + h from the the top comment
				fSuccessor = gSuccessor + hSuccessor;

				//Adding the point to the open list
				if(pointDetails[x - 1][y - 1].f == FLT_MAX || pointDetails[x - 1][y - 1].f > fSuccessor)
				{
					openArray.insert(make_pair(fSuccessor, make_pair(x - 1, y - 1)));

					//Set the point with the new information
					pointDetails[x - 1][y - 1].f = fSuccessor;
					pointDetails[x - 1][y - 1].g = gSuccessor;
					pointDetails[x - 1][y - 1].h = hSuccessor;
					pointDetails[x - 1][y - 1].p_x = x;
					pointDetails[x - 1][y - 1].p_y = y;
				}
			}

		}	

		/*Successor point where x increases and y increases*/
		if (validPoint(x + 1, y + 1))
		{
			//Check if the end point has been reached, stop traversing if end point has been reached
			if (endPointReached(x + 1, y + 1, endPt))
			{
				//End point reached, perform required operations
				pointDetails[x + 1][y + 1].p_x = x;
				pointDetails[x + 1][y + 1].p_y = y;

				cout << "The end point has been found" << endl;
				displayPath(pointDetails, endPt);
				endPtFound = true;
				return;
			}
			else if ((!closedArray[x + 1][y + 1]) && (noObstacle(grid, x + 1, y + 1)))
			{
				//End point not found. Traverse through list and update
				//Diagonal distance covered is sqrt(2)
				gSuccessor = sqrt(2.0) + pointDetails[x][y].g;
				hSuccessor = heuristicDistance(x + 1, y + 1, endPt);
				//f = g + h from the the top comment
				fSuccessor = gSuccessor + hSuccessor;

				//Adding the point to the open list
				if(pointDetails[x + 1][y + 1].f == FLT_MAX || pointDetails[x + 1][y + 1].f > fSuccessor)
				{
					openArray.insert(make_pair(fSuccessor, make_pair(x + 1, y + 1)));

					//Set the point with the new information
					pointDetails[x + 1][y + 1].f = fSuccessor;
					pointDetails[x + 1][y + 1].g = gSuccessor;
					pointDetails[x + 1][y + 1].h = hSuccessor;
					pointDetails[x + 1][y + 1].p_x = x;
					pointDetails[x + 1][y + 1].p_y = y;
				}
			}

		}	

		/*Successor point where x increases and y decreases*/
		if (validPoint(x + 1, y - 1))
		{
			//Check if the end point has been reached, stop traversing if end point has been reached
			if (endPointReached(x + 1, y - 1, endPt))
			{
				//End point reached, perform required operations
				pointDetails[x + 1][y - 1].p_x = x;
				pointDetails[x + 1][y - 1].p_y = y;

				cout << "The end point has been found" << endl;
				displayPath(pointDetails, endPt);
				endPtFound = true;
				return;
			}
			else if ((!closedArray[x + 1][y - 1]) && (noObstacle(grid, x + 1, y - 1)))
			{
				//End point not found. Traverse through list and update
				//Diagonal distance covered is sqrt(2)
				gSuccessor = sqrt(2.0) + pointDetails[x][y].g;
				hSuccessor = heuristicDistance(x + 1, y - 1, endPt);
				//f = g + h from the the top comment
				fSuccessor = gSuccessor + hSuccessor;

				//Adding the point to the open list
				if(pointDetails[x + 1][y - 1].f == FLT_MAX || pointDetails[x + 1][y - 1].f > fSuccessor)
				{
					openArray.insert(make_pair(fSuccessor, make_pair(x + 1, y - 1)));

					//Set the point with the new information
					pointDetails[x + 1][y - 1].f = fSuccessor;
					pointDetails[x + 1][y - 1].g = gSuccessor;
					pointDetails[x + 1][y - 1].h = hSuccessor;
					pointDetails[x + 1][y - 1].p_x = x;
					pointDetails[x + 1][y - 1].p_y = y;
				}
			}
		}

	}

	//If the openArray is empty and the end point is not found, there is no route to the end point
	if (!endPtFound)
	{
		result = 1;
		cout << "No route to the end point" << endl;
	}
	return;
}

void detections_callback(const geometry_msgs::PolygonStamped::ConstPtr& msgIn)
{
	//Used to set the points in the grid
	int detMinX = msgIn->polygon.points[0].x;
	int detMinY = msgIn->polygon.points[0].y;
	int detMaxX = msgIn->polygon.points[0].x;
	int detMaxY = msgIn->polygon.points[0].y;

	for (int ii = 0; ii < msgIn->polygon.points.size(); ii++)
	{
		if(msgIn->polygon.points[ii].x < detMinX)
		{
			detMinX = msgIn->polygon.points[ii].x;
		}

		if(msgIn->polygon.points[ii].x > detMaxX)
		{
			detMaxX = msgIn->polygon.points[ii].x;
		}

		if(msgIn->polygon.points[ii].y > detMaxY)
		{
			detMaxY = msgIn->polygon.points[ii].y;
		}

		if(msgIn->polygon.points[ii].y < detMinY)
		{
			detMinY = msgIn->polygon.points[ii].y;
		}
	}	

	//cout << "Debug info: " << detMinX << ", " << detMinY << ", " << detMaxX << ", " << detMaxY << endl;

	int i,j;

	if((detMinX >= 0) && (detMinX < 100) && (detMinY >=0) && (detMinY < 100) && (detMaxX >=0) && (detMaxX < 100) && (detMaxY >= 0) && (detMaxY < 100))
	{
		for(i = detMinX; i < detMaxX; i++)
		{
			for (j = detMinY; i < detMaxY; i++)
			{
				grid[i][j] = 0;
			}
		}
	}

	/*int c, d;
    for(c = 0; c < a; c++)
    {
    	for(d = 0; d < b; d++)
    	{
    		cout << grid[c][d];
    	}
    	cout << endl;
    }*/

}

int main(int argc, char **argv)
{
	//Initializing the ros node.
	ros::init(argc, argv, "pathfinder_node");

	ros::NodeHandle n("~");
testing::InitGoogleTest(&argc, argv);
	//Publish to the cmd_vel topic to move the catvehicle
	ros::Publisher geometry_pub = n.advertise<geometry_msgs::Twist>("/catvehicle/cmd_vel", 1);
	ros::Rate loop_rate(10);

    std::fill(grid[0], grid[0] + a * b, 1);
grid[20][20] = 0;
	//Used to get the pose of the catvehicle
	ros::Subscriber catvehicle_position = n.subscribe("/turtle1/pose", 1, pose_callback);
	ros::Subscriber detections = n.subscribe("/detections", 1, detections_callback);

	geometry_msgs::Twist velocity;
	velocity.linear.x = 0.0;
	velocity.linear.y = 0.0;
	velocity.linear.z = 0.0;
	velocity.angular.x = 0.0;
	velocity.angular.y = 0.0;
	velocity.angular.z = 0.0;

	if(posX != 10000)
	{
		ROS_INFO_STREAM("Catvehicle position = (" << posX << ", " << posY << ")\n");
	}
	//boost::this_thread::sleep( boost::posix_time::seconds(1) );
    //boost::this_thread::sleep( boost::posix_time::milliseconds(1000) );
    //boost::shared_ptr< M const > 	waitForMessage ("detections", n);
    //grid[45][40] = 0;
    if(!noObstacle(grid, endPnt.first, endPnt.second))
	{
		cout << "There is an obstacle at the end point, the path is not generated and the car will not move" << endl;
		return 0;
	}

    /*int i, j;
    for(i = 0; i < a; i++)
    {
    	for(j = 0; j < b; j++)
    	{
    		cout << grid[i][j];
    	}
    	cout << endl;
    }*/
 
    pathfinderAlgorithm(grid, startPnt, endPnt);

    /*while(!pathTaken.empty())
	{
		pair<int, int>  myPoint = pathTaken.top();
		pathTaken.pop();
		cout << "--> (" << myPoint.first << ", " << myPoint.second << ") " ;
		//Distance = Distance + sqrt(pow((pth2.first - pth.first) , 2) + pow((pth2.second - pth.second), 2));
		
	}*/

	pair<int, int> currentPoint;

	if(!pathTaken.empty())
	{
		pathTaken.pop();
		currentPoint = pathTaken.top();
	}
 	while (ros::ok())
	{
		//ROS_INFO_STREAM("Catvehicle position = (" << posX << ", " << posY << ")\n");
		
		//velocity.linear.y = 0;
		//velocity.angular.z = 0;
		targetPosX = currentPoint.first;
		targetPosY = currentPoint.second;

		if((abs(targetPosX - posX) < 1) && (abs(targetPosY - posY) < 1))
		{
			targetAreaReached = true;
		}

		if(!targetAreaReached)
		{
			velocity.linear.x = 1;

			if((targetTheta - theta) > 0)
			{
				//velocity.angular.z = 0.1;
				velocity.angular.z = targetTheta - theta;
			}
			else if((targetTheta - theta) < 0)
			{
				//velocity.angular.z = -0.1;
				velocity.angular.z = targetTheta - theta;
			}
			else
			{
				velocity.angular.z = 0;
			}	
		}
		else
		{
			if (currentPoint.first == endPnt.first && currentPoint.second == endPnt.second)
			{
				velocity.linear.x = 0;
				velocity.angular.z = 0;
			}
			else
			{
				if(!pathTaken.empty())
				{
					pathTaken.pop();
					currentPoint = pathTaken.top();
					targetAreaReached = false;
					cout << "Reached point (" << targetPosX << ", " << targetPosY << ")" << endl;
				}
			}
		}
	

		geometry_pub.publish(velocity);
		ros::spinOnce();

		loop_rate.sleep();
	}

	return RUN_ALL_TESTS();
}
//End of file

TEST(MyTest34_2, MyTest34_2){
  EXPECT_EQ(result, 0);
}
