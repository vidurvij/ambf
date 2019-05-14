#ifndef MAIN_H
#define MAIN_H
#include "RaveKine.h"


class Interface{
private:
  kinematics kine;
  Robot robo;
  ros::NodeHandle nh_;
  // ambf_msgs::ObjectState;
public:
  void interface_setup();
  void adjust_setting();
  void jw(int, vector<float>);
  void jp(int, vector<float>);
  void manual_command(int, vector<float>,vector<unsigned char>);
  void ep(int, tf::Transform&);
  void pb(const ros::MessageEvent<ambf_msgs::ObjectState>&, string&);
  void endpb(const ros::MessageEvent<ambf_msgs::ObjectState>&, string&);
  void setup();
  void publish_process();
  bool init_ros(int , char**);
  Interface(int , char**);
  // Interface()
};

#endif
