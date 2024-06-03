#include <ros/ros.h>
#include <std_msgs/String.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "hello_world_publisher");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("hello_world_topic", 10);
    ros::Rate loop_rate(10);

    while (ros::ok()) {
        std_msgs::String msg;
        msg.data = "Hello World!";
        pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
