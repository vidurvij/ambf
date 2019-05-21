#ifndef AMBFDEFINES_H
#define AMBFDEFINES_H

//---------------------------------------------------------------------------
#include "chai3d.h"
#include "ambf.h"
//---------------------------------------------------------------------------
#include <GLFW/glfw3.h>
#include <boost/program_options.hpp>
#include <mutex>
#include <thread>
#include <map>
#include <termios.h>
//---------------------------------------------------------------------------
using namespace ambf;
using namespace chai3d;
using namespace std;
//---------------------------------------------------------------------------
#include "CBullet.h"
#define Eps       1.0e-05
#define Deg2Rad   * M_PI/180
#define Rad2Deg   *180/M_PI

enum CTRL_mode{end, joint};

struct reference{
  static const string robot_name;
  static const vector<float> zero_joints;
  static const int children_size;
  static const int arms;
  static const int raven_iksols;
  static const vector<string> base_names;
  static const string prefix;
  static const string command_string;
  static const string state_string;
  static const vector<string> end_effector_name;

  static const int         V;
  static const vector<vector<float>>   raven_joint_limit;
  static const vector<vector<float>>   raven_dh_alpha;
  static const vector<vector<float>>   raven_dh_a;
  static const vector<vector<float>>   raven_dh_d;
  static const vector<vector<float>>   raven_dh_theta;
  static const vector<float>           raven_ikin_param;
  static const vector<unsigned char>   true_joints;
  static const vector<unsigned char>   false_joints;
  static const vector<tf::Transform>   			raven_T_B0;
  static const tf::Transform                 raven_T_CB;
  static const vector<float>                  home_joints;
  static const int                       AMBF_rate;
};

struct robot_part{
  ros::Publisher pub;
  ros::Subscriber subs;
  string part_name;
  ambf_msgs::ObjectState state;
  CTRL_mode mode;
  vector<float> delta;
  ambf_msgs::ObjectCmd command
  bool cmd_updated;
  robot_part(){state_updated = false; delta = {0,0,0,0,0,0,0};}
  robot_part(ros::Publisher p, ros::Subscriber s, string name): pub(p), subs(s), part_name(name){state_updated = false;}

};


struct Robot{
  string robot_name;
  vector<robot_part> arms;
  vector<robot_part> end_effector;
  void joint_positions(vector<vector<float>>& result){
    for(robot_part arm : arms)
      result.push_back(arm.state.joint_positions);
  }
  void end_positions(vector<tf::Transform >& result){
    for(robot_part effector : end_effector)
      result.push_back(tf::Transform(tf::Quaternion(effector.state.pose.orientation.x, effector.state.pose.orientation.y,effector.state.pose.orientation.z, effector.state.pose.orientation.w), tf::Vector3(effector.state.pose.position.x,effector.state.pose.position.y,effector.state.pose.position.z)));
    // cout<<"Test:"<<end_effector[0].state.sim_step<<endl;
  }
  // vector<vector<robot_part>> children;  To be implemented
};

#endif
