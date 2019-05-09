# slam_bot_foss

# Abstract
Mobile robots are expected to perform complicated tasks that require navigation in complex and dynamic indoor and outdoor environments without any human input. In order to autonomously navigate, path plan, and perform these tasks efficiently and safely, the robot needs to be able to localize itself in its environment based on the constructed maps. Mapping the spatial information of the environment is done online with no prior knowledge of the robot’s location; the built map is subsequently used by the robot for navigation. Recently, there has been considerable excitement about the use of technology from the robotics and autonomous vehicle industries for indoor mapping where GPS or GNSS are not available. This technology is called SLAM, Simultaneously Localization and Mapping. It is a process where a robot builds a map representing its spatial environment while keeping track of its position within the built map. The aim of the project is to build an robot capable of performing SLAM technique, using easily available low cost RGBD camera.


# Useful Repositories

ROS
https://github.com/ros  

OpenCV
https://github.com/opencv/opencv

FREENECT KINECT DRIVER
https://github.com/OpenKinect/libfreenect

LibreCAD CAD Modelling software
https://github.com/LibreCAD/LibreCAD

Point Cloud Library
https://github.com/PointCloudLibrary


# Serial Commands
The Arduino code serial_seperator.ino should be used to interface dc geared motor with arduino UNO. The program also consists of commands to create a required movement of robot, having control over the distance and speed of the bot.

Commands:
f: Forward
r: Reverse
fr: Forward Right
fl: Forward Left
st: stop

sample command:
f:<distance_to_be_covered>:<PWM_speed>
