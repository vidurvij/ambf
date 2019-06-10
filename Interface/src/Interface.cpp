// System Setup functions
#include "intermain.h"
Interface::Interface(int argc, char** argv ){
  // ROS_INFO("ROS IS ALIVE");
  // while(!init_ros(argc, argv))
  //   init_ros(argc, argv);
  if (init_ros(argc, argv))
    {ROS_INFO("ROS IS ALIVE");}
  else
    exit(0);
  setup();
}

// bool Interface::thread_start(){
//   thread test(&Interface::publish_process, this);
//   test.join();
// }

bool Interface::init_ros(int argc, char** argv){
  ROS_INFO("Yu hi chala chal");
  // ros::init(argc,argv,"Start");
  if (ros::ok())
    {ROS_INFO("Friday is Alive");return true;}
  else
    return false;
  // thread_start();
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
// System Publish Commands. Still need to publish body control commands


// void Interface::jw(int arm_no){
//   if(arm_no > robo.arms.size()){cout<<"Invalid Arm"; exit(0);}
//   // ambf_msgs::ObjectCmd msg;
//   // msg.header.stamp = ros::Time::now();
//   // msg.joint_cmds = joint;
//   // msg.position_controller_mask = reference::false_joints;
//   robo.arms[arm_no].pub.publish(msg);
// }

void Interface::jp(int arm_no){
  if(arm_no > robo.arms.size()){cout<<"Invalid Arm"; exit(0);}
  // cout<<"\nStruck"<<endl;
  robo.arms[arm_no].command.header.stamp = ros::Time::now();
  // cout<<"\nStruck"<<endl;

  // ambf_msgs::ObjectCmd msg;
  // msg.header.stamp = ros::Time::now();
  // robo.arms[arm_no].command.pose = tf::Transform();
  robo.arms[arm_no].command.position_controller_mask = reference::true_joints;
  // cout<<"\nStruck"<<endl;

  robo.arms[arm_no].pub.publish(robo.arms[arm_no].command);
  // cout<<"\nStruck"<<endl;

}

void Interface::manual_command(int arm_no, vector<float> joint, vector<unsigned char> mask){
  if(arm_no > robo.arms.size()){cout<<"Invalid Arm"; exit(0);}
  ambf_msgs::ObjectCmd msg;
  msg.header.stamp = ros::Time::now();
  msg.joint_cmds = joint;
  msg.position_controller_mask = mask;
  robo.arms[arm_no].pub.publish(msg);
}

// void Interface::ep(int arm_no, vector<float>& cmd){
//   if(arm_no > robo.arms.size()){cout<<"Invalid Arm"; exit(0);}
//   tf::Vector3 origin = robo.end_effector[arm_no].state.pose.getOrigin();
//   tf::Quaternion rotation = robo.end_effector[arm_no].state.pose.getRotation();
//   // origin.setX(origin.x() + cmd[0])
//   // origin.setX(origin.y() + cmd[2])
//   // origin.setX(origin.z() + cmd[1]);
//   // rotation.x += cmd[3];
//   // rotation.y += cmd[4];
//   // rotation.z += cmd[5];
//   // rotation.w += cmd[6];
//   robo.end_effector[arm_no].command.state.pose = tf::Transform(origin,rotation);
//   robo.end_effector[arm_no].command.joint_cmds = vector<float>();
//   // kine.inv_kinematics(robo.arms[arm_no].state.joint_positions, arm_no, end_loc, robo.arms[arm_no].state.joint_positions[5] + robo.arms[arm_no].state.joint_positions[6], command);
//   robo.end_effector[arm_no].command.header.stamp = ros::Time::now();
//   // msg.joint_cmds = command;
//   robo.end_effector[arm_no].command.enable_position_controller = true;
//   robo.end_effector[arm_no].pub.publish(robo.end_effector[arm_no].command);
// }

void Interface::ep2(int arm_no, vector<float>& cmd){
  if(arm_no > robo.arms.size()){cout<<"Invalid Arm"; exit(0);}
  tf::Transform current;
  kine.fwd_kinematics(arm_no, robo.arms[1].command.joint_cmds, current);
  tf::Vector3 origin = current.getOrigin();
  tf::Quaternion rotation = current.getRotation();
  cout<<"Input: ";
  for(auto i : robo.arms[1].state.joint_positions )
    cout <<i <<" ";
  cout<<endl;
  float roll, pitch, yaw;
  toEulerAngle(rotation, roll, pitch, yaw);
  origin.setX(origin.x() + cmd[0]);
  origin.setY(origin.y() + cmd[1]);
  origin.setZ(origin.z() + cmd[2]);
  // tf::Vector3 change(cmd[0],cmd[1],cmd[2]);
  // current.setOrigin(origin);
  // roll += cmd[3];
  // pitch += cmd[4];
  // yaw += cmd[5];
  rotation.setRPY(cmd[3],cmd[4],cmd[5]);
  // rotation.w += cmd[6];
  // cout<<roll<<endl;
  current.setRotation((rotation*current.getRotation()).normalize());
  vector<float> res(7);
  kine.inv_kinematics(robo.arms[arm_no].command.joint_cmds, arm_no, current, robo.arms[arm_no].command.joint_cmds[5] + robo.arms[arm_no].command.joint_cmds[6], res);
  cout<<"Output: "<<origin.x()<<" "<<origin.y()<<" "<<origin.z();
  // for(auto i : res)
  //  cout<<i<<" ";
  cout<<endl;
  robo.arms[arm_no].command.joint_cmds = res;
  jp(arm_no);
}

void Interface::toEulerAngle(const tf::Quaternion& rot, float& roll, float& pitch, float& yaw)
{
	// roll (x-axis rotation)
  float w = rot.getW();
  tf::Vector3 vec = rot.getAxis();
	float sinr_cosp = +2.0 * (w * vec.x() + vec.y() * vec.z());
	float cosr_cosp = +1.0 - 2.0 * (vec.x() * vec.x() + vec.y() * vec.y());
	roll = atan2(sinr_cosp, cosr_cosp);

	// pitch (y-axis rotation)
	float sinp = +2.0 * (w * vec.y() - vec.z() * vec.x());
	if (fabs(sinp) >= 1)
		pitch = copysign(M_PI / 2, sinp); // use 90 degrees if out of range
	else
		pitch = asin(sinp);

	// yaw (z-axis rotation)
	float siny_cosp = +2.0 * (w * vec.z() + vec.x() * vec.y());
	float cosy_cosp = +1.0 - 2.0 * (vec.y() * vec.y() + vec.z() * vec.z());
	yaw = atan2(siny_cosp, cosy_cosp);
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
    // ROS_INFO("name ",name,end.part_name);
    if(end.part_name == name){
      end.state = *(msg.getMessage());
    }}

}

// void Interface::ros_process(){
//   ros::Rate(reference::AMBF_rate);
//   while(ros::ok()){
//     for(int i = 0; i < reference::arms; i++)
//       switch(robo.arms[i].CTRL_mode){
//         case joint:
//           jp(i);
//           break;
//         case end:
//           // end_loc(i,robo.arms[i].delta);
//           break;
//       }
//   }
// }

bool Interface::move_to_posn(int arm, vector<float> destination){
  ROS_INFO("\nALIVE and staring");
  int duration = 5;
  // vector<float> destination = reference::home_joints;
  int count = 0;
  while(robo.arms[0].state.joint_positions.size() < 7)
    {ros::spinOnce();continue ;}
  vector<float> delta, start = robo.arms[arm].state.joint_positions;
  delta.resize(reference::children_size);
  for(int j = 0; j < reference::children_size; j++)
  {delta[j] = (destination[j] - start[j]);}
  // exit(0);
  int iterations = reference::AMBF_rate * duration;
  ros::Rate loop_rate(1000);
  vector<float> command(reference::children_size);
  while(count < iterations){
    ROS_INFO("In_Loop");
    cout<<"lol1"<<command.size()<<endl;
    for(int j = 0; j<reference::children_size; j++)
      command[j] = ((((float)count/(float)iterations)* delta[j])  + start[j]);
    robo.arms[arm].command.joint_cmds = command;
    // cout<<"Command : ";
    // for(int i = 0; i< 7; i++)
    //   cout<<command[i]<<" ";
    // cout<<(float)count/(float)iterations<<endl;
    jp(arm);
    // ros::spinOnce();
    count++;
    loop_rate.sleep();
    ros::spinOnce();
  }
  // robo.arms[arm].command.joint_cmds = reference::home_joints;
  // jp(arm);
  // while(true)
}

void Interface::reset(int arm_no){
  vector<float> random_position(reference::children_size);
  std::default_random_engine generator;
  // int seed = rand();
  for(int i = 0 ; i < reference::children_size; i++){
    uniform_real_distribution<double> distribution(reference::raven_joint_limit[0][i],reference::raven_joint_limit[1][i]);
    random_position[i] = distribution(generator);
  }
  this -> move_to_posn(arm_no,random_position);
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
