#include <ros/ros.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>
#include <nav_msgs/Odometry.h>

std::string turtle_name;

void poseCallback(const nav_msgs::Odometry::ConstPtr& msg){
  static tf2_ros::TransformBroadcaster br;
  geometry_msgs::TransformStamped transformStamped;
  
  transformStamped.header.stamp = ros::Time::now();
  transformStamped.header.frame_id = "map";
  transformStamped.child_frame_id = "base_link";
  transformStamped.transform.translation.x = msg->pose.pose.position.x;
  transformStamped.transform.translation.y = msg->pose.pose.position.y;
  transformStamped.transform.translation.z = 0.0;
  // tf2::Quaternion q;
  // q.setRPY(0, 0, msg->theta);
  transformStamped.transform.rotation.x = msg->pose.pose.orientation.x;
  transformStamped.transform.rotation.y = msg->pose.pose.orientation.y;
  transformStamped.transform.rotation.z = msg->pose.pose.orientation.z;
  transformStamped.transform.rotation.w = msg->pose.pose.orientation.w;

  br.sendTransform(transformStamped);
}

int main(int argc, char** argv){
  ros::init(argc, argv, "map2base_link_broadcaster");
    
  ros::NodeHandle node;
  ros::Subscriber sub = node.subscribe("/odometry/filtered", 10, &poseCallback);

  ros::spin();
  return 0;
};