// System Setup functions
#include "intermain.h"
Interface::Interface(int argc, char** argv ){
  if (init_ros(argc, argv))
    {ROS_INFO("ROS IS ALIVE");}
  else
    exit(0);
  setup();
}

bool Inteface::thread_start(){
  thread test(&Interface::publish_process, &I);
  test.join();
}

bool Interface::init_ros(int argc, char** argv){
  ros::init(argc,argv,"Start");
  if (ros::ok())
    {ROS_INFO("Friday is Alive");return true;}
  else
    return false;
  thread_start();
}

void Interface::setup(){
    if (ros::ok()){
      robo.robot_name = reference::robot_name;
    for (string name:reference::base_names){
      string topic = reference::prefix + reference::robot_name + '/' + name + '/';
      ros::Publisher p = nh_.advertise<ambf_msgs::ObjectCmd>(topic + reference::command_string, 1);
      ros::Subscriber s = nh_.subscribe<ambf_msgs::ObjectState>(topic + reference::state_string, 1, boost::bind(&Interface::pb, this,_1, name)); //Callback a placeholder. To be improved
      robo.arms.emplace_back(p, s, name);
    }
    for (string name: reference::end_effector_name){
      string topic = reference::prefix + reference::robot_name + '/' + name + '/';
      ros::Publisher p = nh_.advertise<ambf_msgs::ObjectCmd>(topic + reference::command_string, 1);
      ros::Subscriber s = nh_.subscribe<ambf_msgs::ObjectState>(topic + reference::state_string, 1, boost::bind(&Interface::endpb, this,_1, name)); //Callback a placeholder. To be improved
      robo.end_effector.emplace_back(p, s, name);
    }
  }
  ROS_INFO("Alive");
  adjust_setting();
}

void Interface::adjust_setting(){
  ambf_msgs::ObjectCmd msg1;
  msg1.header.stamp = ros::Time::now();
  msg1.publish_children_names = false;
  msg1.publish_joint_names = false;
  // msg1.joint_cmds = reference::home_joints;
  // msg1.position_controller_mask = reference::true_joints;
  msg1.publish_joint_positions = true;
  // ros::Rate r(1000000);
  for(int i = 0; i<reference::arms; i++)
    {robo.arms[i].pub.publish(msg1);robo.end_effector[i].pub.publish(msg1);}
}
// System Publish Commands. Stil;l need to publish body control commands


void Interface::jw(int arm_no, ambf_msgs::ObjectCmd& cmd){
  if(arm_no > robo.arms.size()){cout<<"Invalid Arm"; exit(0);}
  ambf_msgs::ObjectCmd msg;
  msg.header.stamp = ros::Time::now();
  msg.joint_cmds = joint;
  msg.position_controller_mask = reference::false_joints;
  robo.arms[arm_no - 1].pub.publish(msg);
}

void Interface::jp(int arm_no){
  if(arm_no > robo.arms.size()){cout<<"Invalid Arm"; exit(0);}
  robo.arms[arm_no].command.header.stamp = ros::Time::now();
  // ambf_msgs::ObjectCmd msg;
  // msg.header.stamp = ros::Time::now();
  robo.arms[arm_no].command.pose = tf::Transform();
  robo.arms[arm_no].command.position_controller_mask = reference::true_joints;
  robo.arms[arm_no].pub.publish(robo.arms[arm_no].command);
}

void Interface::manual_command(int arm_no, vector<float> joint, vector<unsigned char> mask){
  if(arm_no > robo.arms.size()){cout<<"Invalid Arm"; exit(0);}
  ambf_msgs::ObjectCmd msg;
  msg.header.stamp = ros::Time::now();
  msg.joint_cmds = joint;
  msg.position_controller_mask = mask;
  robo.arms[arm_no - 1].pub.publish(msg);
}

void Interface::ep(int arm_no){
  if(arm_no > robo.arms.size()){cout<<"Invalid Arm"; exit(0);}
  tf::Vector3 origin = robo.end_effector[arm_no].state.pose.getOrigin();
  tf::Quaternion rotation = robo.end_effector[arm_no].state.pose.getRotation();
  origin.x += vector[0];
  origin.y += vector[1];
  origin.z += vector[2];
  rotation.x += vector[3];
  rotation.y += vector[4];
  rotation.z += vector[5];
  rotation.w += vector[6];
  robo.end_effector[arm_no].command.state.pose = tf::Transform(origin,rotation);
  robo.end_effector[arm_no].command.joint_cmds = vector<float>();
  // kine.inv_kinematics(robo.arms[arm_no - 1].state.joint_positions, arm_no - 1, end_loc, robo.arms[arm_no - 1].state.joint_positions[5] + robo.arms[arm_no - 1].state.joint_positions[6], command);
  robo.end_effector[arm_no].command.header.stamp = ros::Time::now();
  // msg.joint_cmds = command;
  robo.end_effector[arm_no].command.enable_position_control = true;
  robo.end_effector[arm_no].pub.publish(robo.end_effector[arm_no].command);
}

void Interface::ep2(int arm_no){
  if(arm_no > robo.arms.size()){cout<<"Invalid Arm"; exit(0);}
  tf::Transform current;
  kine.fwd_kinematics(arm_no, robo.arms[i].state.joint_positions, current)
  tf::Vector3 origin = current.pose.getOrigin();
  tf::Quaternion rotation = current.pose.getRotation();
  origin.x += vector[0];
  origin.y += vector[1];
  origin.z += vector[2];
  rotation.x += vector[3];
  rotation.y += vector[4];
  rotation.z += vector[5];
  rotation.w += vector[6];
  current.setOrigin(origin);
  current.setRotation(rotation)
  kine.inv_kinematics(robo.arms[arm_no - 1].state.joint_positions, arm_no, current, robo.arms[arm_no - 1].state.joint_positions[5] + robo.arms[arm_no - 1].state.joint_positions[6], robo.arms[arm_no].command.joint_positions);
  jw(arm_no);
}

// Subscribing

void Interface::pb(const ros::MessageEvent<ambf_msgs::ObjectState>& msg, string& name){
  for(auto &arm: robo.arms)
    if(arm.part_name == name){

      arm.state = *(msg.getMessage());
      arm.state_updated = true;
      if(arm.state.joint_positions.size() == 0)
        adjust_setting();
    }
}

void Interface::endpb(const ros::MessageEvent<ambf_msgs::ObjectState>& msg, string& name){
  for(auto &end: robo.end_effector)
    {
    ROS_INFO("name ",name,end.part_name);
    if(end.part_name == name){
      end.state = *(msg.getMessage());
    }}

}

void ros_process(){
  ros::Rate(reference::AMBF_rate);
  while(ros::ok()){
    for(int i = 0; i < reference::arms; i++)
      switch(robo.arms[i].CTRL_mode){
        case joint:
          jp(i);
          break;
        case end:
          end_loc(i,robo.arms[i].delta);
          break;
      }
  }
}

void Interface::starting(){
  // ROS_INFO("\nALIVE and staring");
  int duration = 5;
  vector<float> destination = reference::home_joints;
  int count = 0;
  ROS_INFO("Detec1");
  while(robo.arms[0].state.joint_positions.size() < 7)
    {ros::spinOnce();continue ;}
  vector<vector<float>> delta, start = {robo.arms[0].state.joint_positions, robo.arms[1].state.joint_positions};
  delta.resize(reference::arms);
  ROS_INFO("Detec2");
  for(int i = 0; i<reference::arms; i++)
    for(int j = 0; j < reference::children_size; j++)
    {ROS_INFO("TING");delta[i].emplace_back(destination[j] - start[i][j]);}

  // ROS_INFO("\nALIVE and staring");
  int iterations = reference::AMBF_rate * duration;
  ros::Rate loop_rate(1000);
  while(count < iterations){
    for(int i = 0; i< reference::arms; i++){
      vector<float> command;
      for(int j = 0; j<reference::children_size; j++)
        command.emplace_back((((float)count/(float)iterations)* delta[i][j])  + start[i][j]);
      Interface::jp(i, command);

    }
    count++;
    loop_rate.sleep();
  }
}

void Interface::publish_process(){
  ros::Rate loop_rate(.5);
  while(ros::ok()){

    vector<vector<float>> display;
    robo.joint_positions(display);
    for(int i = 0 ; i< reference::arms ; i++){
      cout<<"Arm "<<i+1<<" [";
      for(float j : display[i])
        cout<<j<<" ";
      cout<<"]"<<endl;
    }
    vector<tf::Transform> end_status;
    // ROS_INFO("name ","yolo");
    robo.end_positions(end_status);
    tf::Transform end_pose1, end_pose2;
    kine.fwd_kinematics(0,display[0], end_pose1);
    kine.fwd_kinematics(1,display[1], end_pose2);
    tf::Vector3 	cp_pos = end_pose1.getOrigin();
  	tf::Quaternion 	cp_ori = end_pose1.getRotation();
    vector<float> inv_result = {0,0,0,0,0,0,0};
    vector<float> inv_result2 = {0,0,0,0,0,0,0};
    cout<<"Test: "<<robo.end_effector[0].state.sim_step<<endl;
    cout<<"Foward Kinematics "<<"posn: "<<cp_pos.x()<<" "<<cp_pos.y()<<" "<<cp_pos.z()<<" Orien: "<<cp_ori.x()<<" "<<cp_ori.y()<<" "<<cp_ori.z()<<" "<<cp_ori.w()<<endl;
    // for(auto end: end_status)
    //   {cp_pos = end.getOrigin();
    //   cp_ori = end.getRotation();
    //   cout<<"Actual Location "<<"posn: "<<cp_pos.x()<<" "<<cp_pos.y()<<" "<<cp_pos.z()<<" Orien: "<<cp_ori.x()<<" "<<cp_ori.y()<<" "<<cp_ori.z()<<" "<<cp_ori.w()<<endl;}
    if (display[0].size() > 0)
    {kine.inv_kinematics(display[0], 0 , end_pose1, display[0][5] + display[0][6], inv_result);
    kine.inv_kinematics(display[1], 1 , end_pose2, display[1][5] + display[1][6], inv_result2);}
    // cout<<"\nhiit";
    cout<<"Inv_results: [";
    for(float i: inv_result)
      cout<<i<<" ";
    cout<<"]"<<endl;
    cout<<"Inv_results2: [";
    for(float i: inv_result2)
      cout<<i<<" ";
    cout<<"]"<<endl;
    cout<<"Sim_step : "<<robo.arms[1].state.sim_step<<"\n\n";
    ros::spinOnce();
    loop_rate.sleep();
  }
}
