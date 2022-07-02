#include "ros/ros.h"
#include "std_msgs/String.h"
#include<string>
#include<bits/stdc++.h>
class SubscribeAndPublish
{
public:
  SubscribeAndPublish()
  {
    //Topic you want to publish
    _pub = n_.advertise<std_msgs::String>("/output", 1000);

    //Topic you want to subscribe
    sub_ = n_.subscribe("input", 1, &SubscribeAndPublish::callback, this);
  }

  void callback( const std_msgs::String::ConstPtr& msg)
  {
     
    //  std::cout<<msg -> data<<std::endl;
     
    // std::cout<<msg ->data<<std::endl;
    std::string str_val = msg->data;
    std::sort(str_val.begin(),str_val.end());
    // std::cout << typeid(msg -> data).name() << std::endl;
    std::cout<<str_val<<std::endl;
    std_msgs::String reversed_msg;
    reversed_msg.data = str_val;
    _pub.publish(reversed_msg);
  }

private:
  ros::NodeHandle n_; 
  ros::Publisher _pub;
  ros::Subscriber sub_;

};//End of class SubscribeAndPublish

int main(int argc, char **argv)
{
  //Initiate ROS
  ros::init(argc, argv, "subscribe_and_publish");

  //Create an object of class SubscribeAndPublish that will take care of everything
  SubscribeAndPublish SAPObject;

  ros::spin();

  return 0;
}