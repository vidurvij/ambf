struct robot_part{
  ros::Publisher pub;
  ros::Subscriber subs;
  string part_name;
  ambf_msgs::ObjectState state;
  robot_part()
  robot_part(ros::Publisher_sub p, ros::Subscriber s, string name): pub(p), subs(s), part_name(name){}
}
