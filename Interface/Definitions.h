vector<bool> wrench_vector(int num){
  vector<bool> res;
  for(int i = 0; i < num; i++)
    res.emplace_back(false);
  return res;
}

vector<bool> pose_vector(int num){
  vector<bool> res;
  for(int i = 0; i < num; i++)
    res.emplace_back(true);
  return res;
}

truct reference{
  static const string robot_name;
  static const int children_size;
  static const int arms;
  static const vector<string> base_names;
  static const string prefix;
  static const command_string;
  static const state_string;
}
