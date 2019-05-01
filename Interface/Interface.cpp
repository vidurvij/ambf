// System Setup functions

void Interface::setup(){
    while (ros::ok()){
      robo.name = reference::robot_name;
    for (string name:reference::base_names){
      topic = reference::prefix + reference::robot + '/' + name + '/';
      ros::Publisher p = nh_.advertise<ambf_msgs::ObjectState>(topic + reference::command, 1);
      ros::Subscriber s = nh_.subscribe<ambf_msgs::ObjectState>(topic + reference::state, 1, boost::bind(&Interface::pb, _1, name)) //Callback a placeholder. To be improved
      robo.arms.emplace_back(p, s, name);
    }
  }
  this -> adjust_setting();
}

void adjust_setting(){
  ambf_msgs::ObjectCmd msg;
  msg.header.stamp = ros::Time::now();
  msg.publish_children_names = true;
  msg.publish_joint_names = true;
  msg.publish_joint_positions = true;
  for(auto arm: robo.arms)
    arm.publish(msg);
}
// System Publish Commands. Stil;l need to publish body control commands


void Interface::jw(int arm_no, vector<float> joint){
  if(arm_no > robo.arms.size()){cout<<"Invalid Arm"; exit(0);}
  ambf_msgs::ObjectCmd msg;
  msg.header.stamp = ros::Time::now();
  msg.joint_cmds = joint;
  msg.position_controller_mask = wrench_vector(reference::children_size);
  robo.arms[arm_no - 1].publish(msg);
}

void Interface::jp(int arm_no, vector<float> joint){
  if(arm_no > robo.arms.size()){cout<<"Invalid Arm"; exit(0);}
  ambf_msgs::ObjectCmd msg;
  msg.header.stamp = ros::Time::now();
  msg.joint_cmds = joint;
  msg.position_controller_mask = pose_vector(reference::children_size);
  robo.arms[arm_no - 1].publish(msg);
}

void Interface::manual_command(int arm_no, vector<int> joint, vector<bool> mask){
  if(arm_no > robo.arms.size()){cout<<"Invalid Arm"; exit(0);}
  ambf_msgs::ObjectCmd msg;
  msg.header.stamp = ros::Time::now();
  msg.joint_cmds = mask;
  msg.position_controller_mask = pose_vector(reference::children_size);
  robo.arms[arm_no - 1].publish(msg);
}

// Subscribing

void Interface::cb(const ros::MessageEvent<ambf::ObjectState> msg, string& name){
  for(auto arm: robo.arms)
    if(arm.part_name == name){
      arm.state = msg.getConstMessage();
    }
}
