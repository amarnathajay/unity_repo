% Author: Jonathan Sprinkle
% Copyright (c) 2017 Arizona Board of Regents
% License: BSD
function task3validation(filename)
% This file demonstrates how to ingest data from a ros bag into MATLAB, and
% how to plot those data as polygons using MATLAB's native fill function. 
%
% Note that this tutorial will work ONLY if you have installed the Robotics
% System Toolbox from MathWorks

if(nargin == 0)
    filename='~/Desktop/ros.bag';
    disp(['Using default bagfile at location ' filename]);
end

%% Load the Task 3 bagfile into MATLAB; you should get this file as a 
% download from your CPS-VO simulation in the cloud

% load the bagfile into MATLAB
% YMMV, change the location of the download directory for your own benefit
bag = rosbag(filename)

%% Plot Task 3 validation results using the reference frame in which they
% are given as the origin of our plot.

% PolygonStamped messages are not a simple type, so we need to read each
% message into a cell array so that we can iterate over them for analysis
msgs = readMessages(select(bag,'Topic','/detections'));

% rotate through colors for different shapes we have seen: this makes the
% plot a little easier to understand, but if the car moves it will look
% strange.
colors = {'red','green','blue','black','yellow','magenta','cyan'};

% let's plot all the points we generated
figure
hold on
axis([-10 10 -10 10])
axis equal
title('Task 3 validation plot');
xlabel('x axis (m)')
ylabel('y axis (m)')

for i=1:length(msgs)
    shape = zeros(length(msgs{i}.Polygon.Points),3);
    for jj=1:length(msgs{i}.Polygon.Points)
        shape(jj,1) = msgs{i}.Polygon.Points(jj).X;
        shape(jj,2) = msgs{i}.Polygon.Points(jj).Y;
        shape(jj,3) = msgs{i}.Polygon.Points(jj).Z;
    end
    fill3(shape(:,1),shape(:,2),shape(:,3),colors{mod(i,length(colors))+1});
    xval = mean(shape(:,1));
    yval = mean(shape(:,2));
    % draw 20m around each point
    xlim([xval-20 xval+20]);
    ylim([yval-20 yval+20]);
    % wait for just a bit before plotting the next point
    pause(0.05)
end

% success! we're done

