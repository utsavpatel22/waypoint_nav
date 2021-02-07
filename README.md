# Current:
Still in development phase. Need to check if these changes work. [GPSIntegration](http://docs.ros.org/en/kinetic/api/robot_localization/html/integrating_gps.html)
[x] Check for driver used to integrate GPS
[x] Can the name of the gps publisher be changed?
- Check for broadcasting UTM from navsat params file
[x] To debug just IMU, orient robot in east (CCW is +ve) and move the robot to check if the sensor readings increase, else provide yaw_offset in params
- Similarly checkout for magnetic_declination [link](https://www.ngdc.noaa.gov/geomag/calculators/magcalc.shtml#declination) in radians

# GPS launch command: 
```
roslaunch ublox_gps ublox_device_nmea.launch
```
Do test these as well:
```
roslaunch ublox_gps ublox_device_nmea.launch param_file_name:=m8u_rover.yaml
```
Check for gps issues? else run this.
```
roslaunch ublox_gps ublox_device_nmea.launch param_file_name:=m8u_rover_new.yaml
```

# Known Issues:
If you receive the ASIO read input buffer error then please restart the gps launch file, it will work well!
This relates to the change in baud rate specified in param files.

# References:
- [Setup_Robot_localization](https://www.robotandchisel.com/2020/05/01/outdoor-navigation/)
- [UserGuide](https://www.generationrobots.com/media/Jackal_Clearpath_Robotics_Userguide.pdf)
- [UBlox M8U GPS](https://github.com/MrBanannaMan/NEO-M8U-Configuration-Files)

## waypoint_nav (Intro from original)

This package performs outdoor GPS waypoint navigation. It can navigate while building a map, avoiding obstacles, and can navigate continuously between each goal or stop at each goal. 

This repo is made to run on a Clearpath Husky with IMU, Novatel GPS, and Sick lms111 lidar.

This package uses a combination of the following packages:

	- ekf_localization to fuse odometry data with IMU and GPS data

	- navsat_transform to convert GPS data to odometry and to convert latitude and longitude points to the robot's odometry coordinate system

	- GMapping to create a map and detect obstacles
	
	- move_base to navigate to the goals while avoiding obstacles (goals are set using recorded or inputted waypoints)

The outdoor_waypoint_nav package within waypoint_nav includes the following custom nodes:
	
	- gps_waypoint to read the waypoint file, convert waypoints to points in the map frame and then send the goals to move_base
	
	- gps_waypoint_continuous1 and gps_waypoint_continuous2 for continuous navigation between waypoints using two seperate controllers
	
	- collect_gps_waypoint to allow the user to drive the robot around and collect their own waypoints
	
	- calibrate_heading to set the heading of the robot at startup and fix issues with poor magnetometer data
	
	- plot_gps_waypoints to save raw data from the GPS for plotting purposes
	
	- gps_waypoint_mapping to combine waypoint navigation with Mandala Robotics' 3D mapping software for autonomous 3D mapping
  
  For additional information and instructions on how to use the package, see Clearpath Robotic's blog post and tutorial 
  
  	Tutorial: http://www.clearpathrobotics.com/assets/guides/husky/HuskyGPSWaypointNav.html
  	Blog: to be posted soon.
  
Video demonstrations can be found at my Youtube Channel: https://www.youtube.com/channel/UC3FoqSLn12-dKOQ1Sn0xbFQ/videos

## IMPORTANT NOTES:
----------------
 - Please DO NOT contact Clearpath Robotics with questions about this package. Instead, email me at nicholas.c.charron@gmail.com.
 
 - Regarding the calibration node: the heading calibration node is not required if your magnetometer is calibrated correctly. Instructions for performing magnetometer calibration are hard to come by, so often they are not calibrated correctly. Use this "hack" heading calibration node only if your heading is not correct when launching the waypoint navigation node (see this video: https://youtu.be/jsR8gYgeDG0). This will only temporarily solve your problem and must be run every time you start this package. We recommend instead to perform proper magnetometer calibration.
 
 - The continuous waypoint navigation software was tested in simulation and works well in simulation, however it still doesn't work properly with our tests outdoor.
 
 - Please submit pull requests if you update this package and/or fix bugs.
 
 - This code is meant as a tutorial to perform waypoint navigation using common ROS packages. It has not been tested for robustness and should not be used as a final product. If you are looking for a final working GPS waypoint navigation solution, please contact Clearpath Robotics, as they have recently developped a more commercial solution.
