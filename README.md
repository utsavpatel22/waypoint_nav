jackal
======

Common packages for Jackal, including messages and robot description. These are packages relevant
to all Jackal workspaces, whether simulation, desktop, or on the robot's own headless PC.

## ToDo
- Tune ekf for better localization
- Incomplete setup for outdoor

## Run
- Simulation jackal:
```
roslaunch jackal_gazebo jackal_world.launch config:=front_laser
```

- Real world jackal:
Need to launch the following-
->Jackal
->GPS (jackal original currently)
->Lidar
->IMU
Control is through teleop which we can ssh through other device.

- Waypoint Navigation:
```
roslaunch outdoor_waypoint_nav outdoor_waypoint_nav_sim.launch
```

## References:
- [Husky Localization](https://github.com/nickcharron/waypoint_nav/)
- [Initial lab experiment](https://github.com/utsavpatel22/waypoint_nav/)
- [Jackal Tutorials](https://www.clearpathrobotics.com/assets/guides/kinetic/jackal/index.html)
- [Jackal user Guide](https://www.generationrobots.com/media/Jackal_Clearpath_Robotics_Userguide.pdf)
- [Original Jackal Repo](https://github.com/jackal/jackal/tree/kinetic-devel)