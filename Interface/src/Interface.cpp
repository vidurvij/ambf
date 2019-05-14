// System Setup functions
#include "intermain.h"
Interface::Interface(int argc, char** argv ){
  if (init_ros(argc, argv))
    {ROS_INFO("ROS IS ALIVE");}
  else
    exit(0);
  setup();
}

bool Interface::init_ros(int argc, char** argv){
  if (ros::ok())
    return true;
  else
    return false;
}

void Interface::setup(){
    if (ros::ok()){
      robo.robot_name = reference::robot_name;
    for (string name:reference::base_names){
      string topic = reference::prefix + reference::robot_name + '/' + name + '/';
      cout<<topic + reference::command_string<<endl;
      ros::Publisher p = nh_.advertise<ambf_msgs::ObjectCmd>(topic + reference::command_string, 1);
      ros::Subscriber s = nh_.subscribe<ambf_msgs::ObjectState>(topic + reference::state_string, 1, boost::bind(&Interface::pb, this,_1, name)); //Callback a placeholder. To be improved
      robo.arms.emplace_back(p, s, name);
    }
    for (string name: reference::end_effector_name){
      string topic = reference::prefix + reference::robot_name + '/' + name + '/';
      ros::Publisher p = nh_.advertise<ambf_msgs::ObjectCmd>(topic + reference::command_string, 1);
      ros::Subscriber s = nh_.subscribe<ambf_msgs::ObjectState>(topic + reference::state_string, 1, boost::bind(&Interface::endpb, this,_1, name)); //Callback a placeholder. To be improved
      robo.arms.emplace_back(p, s, name);
    }
  }
  // exit(0);
  adjust_setting();
  // cout<<"HIT";
  // exit(0);
}

void Interface::adjust_setting(){
  // cout<<"Hit";
  ambf_msgs::ObjectCmd msg1;
  msg1.header.stamp = ros::Time::now();
  msg1.publish_children_names = false;
  msg1.publish_joint_names = false;
  msg1.publish_joint_positions = true;
  // ros::Rate r(1000000);
  for(int i = 0; i<reference::arms; i++)
    {robo.arms[i].pub.publish(msg1);}
  // cout<<"HIT";
  // exit(0);
}
// System Publish Commands. Stil;l need to publish body control commands


void Interface::jw(int arm_no, vector<float> joint){
  if(arm_no > robo.arms.size()){cout<<"Invalid Arm"; exit(0);}
  ambf_msgs::ObjectCmd msg;
  msg.header.stamp = ros::Time::now();
  msg.joint_cmds = joint;
  msg.position_controller_mask = reference::false_joints;
  robo.arms[arm_no - 1].pub.publish(msg);
}

void Interface::jp(int arm_no, vector<float> joint){
  if(arm_no > robo.arms.size()){cout<<"Invalid Arm"; exit(0);}
  ambf_msgs::ObjectCmd msg;
  msg.header.stamp = ros::Time::now();
  msg.joint_cmds = joint;
  msg.position_controller_mask = reference::true_joints;
  robo.arms[arm_no - 1].pub.publish(msg);
}

void Interface::manual_command(int arm_no, vector<float> joint, vector<unsigned char> mask){
  if(arm_no > robo.arms.size()){cout<<"Invalid Arm"; exit(0);}
  ambf_msgs::ObjectCmd msg;
  msg.header.stamp = ros::Time::now();
  msg.joint_cmds = joint;
  msg.position_controller_mask = mask;
  robo.arms[arm_no - 1].pub.publish(msg);
}

void Interface::ep(int arm_no, tf::Transform& end_loc){
  vector<float> command;
  ambf_msgs::ObjectCmd msg;
  kine.inv_kinematics(robo.arms[arm_no - 1].state.joint_positions, arm_no - 1, end_loc, robo.arms[arm_no - 1].state.joint_positions[5] + robo.arms[arm_no - 1].state.joint_positions[6], command);
  msg.header.stamp = ros::Time::now();
  msg.joint_cmds = command;
  msg.position_controller_mask = reference::true_joints;
}

// Subscribing

void Interface::pb(const ros::MessageEvent<ambf_msgs::ObjectState>& msg, string& name){
  for(auto &arm: robo.arms)
    if(arm.part_name == name){
      // ambf_msgs::ObjectState * a= msg.getMessage();
      // cout<<"Hit";
      arm.state = *(msg.getMessage());
      if(arm.state.joint_positions.size() == 0)
        adjust_setting();
    }
}

void Interface::endpb(const ros::MessageEvent<ambf_msgs::ObjectState>& msg, string& name){
  for(auto &end: robo.end_effector)
    if(end.part_name == name){
      end.state = *(msg.getMessage());
    }
}

void Interface::publish_process(){
  ros::Rate loop_rate(1000);
  while(ros::ok()){
    vector<vector<float>> display;
    robo.joint_positions(display);
    for(int i = 0 ; i< reference::arms ; i++){
      cout<<"Arm "<<i+1<<" [";
      for(float j : display[i])
        cout<<j<<" ";
      cout<<"]"<<endl;
    }
    tf::Trasnform end_pose;
    kine.fwd_kinematics(0,display[0], end_pose);
    tf::Vector3 	cp_pos = end_pose.getOrigin();
  	tf::Quaternion 	cp_ori = end_pose.getRotation();
    
    cout<<"Sim_step : "<<robo.arms[1].state.sim_step<<endl;
    ros::spinOnce();
    loop_rate.sleep();
  }
}
