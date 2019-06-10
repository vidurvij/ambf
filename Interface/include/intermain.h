#ifndef MAIN_H
#define MAIN_H
#include "RaveKine.h"


struct Interface{
  kinematics kine;
  Robot robo;
  ros::NodeHandle nh_;
  // ambf_msgs::ObjectState;
public:
  void interface_setup();
  void adjust_setting();
  void jw(int);
  void jp(int);
  void manual_command(int, vector<float>,vector<unsigned char>);
  void ep(int, vector<float>&);
  void ep2(int, vector<float>&);
  void pb(const ros::MessageEvent<ambf_msgs::ObjectState>&, string&);
  void endpb(const ros::MessageEvent<ambf_msgs::ObjectState>&, string&);
  void setup();
  void publish_process();
  void ros_process();
  void toEulerAngle(const tf::Quaternion&, float&,float&,float&);
  bool move_to_posn(int,vector<float>);
  bool init_ros(int , char**);
  void reset(int);
  Interface(int , char**);
  // Interface()
};

#endif
