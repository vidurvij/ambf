#include "Reinforce_tracking.h"

Reinforce_tracking::Reinforce_tracking(int argc, char* argv[]):interface(argc, argv){
}

bool Reinforce_tracking::arm_motion(){

  static int count = 0;
  static float speed = .1 / reference::AMBF_rate;
  ros::Rate loop_rate(reference::AMBF_rate);
  interface.move_to_posn(0, reference::home_joints);
  // ros::Duration s(10);
  // s.sleep();
  while (ros::ok()){
    // ROS_INFO("In_Loop2");
    cout<<"Command: ";
    for(int i = 0; i<reference::children_size; i++){
      interface.robo.arms[0].command.joint_cmds[i] = 1 * sin(speed * count) + reference::home_joints[i];
      // cout<<interface.robo.arms[0].command.joint_cmds[i]<<" ";
    }
    cout<<endl;
    interface.jp(0);
    count++;
    loop_rate.sleep();
  }
}

bool Reinforce_tracking::right_arm(){
  ros::Rate loop_rate(reference::AMBF_rate);
  while(interface.robo.arms[1].state.joint_positions.size()< 7){ros::spinOnce();}
  interface.move_to_posn(1, reference::home_joints);
  while(ros::ok()){
  //   // cout<<interface.robo.arms[1].state.joint_positions.size();
  vector<float> command = {0, 0,0,0,0,-0.0001,0};
  // interface.jp(1);
  interface.ep2(1,command);
  ros::spinOnce();
  loop_rate.sleep();
  }
}

bool Reinforce_tracking::AC2(){
int steps = 0;
int episode = 0;
while(episode < reference::EPISODES){
  vector<torch::Tensor> logprobs, rewards, values, qvalues;
  interface.reset(1); // TO be implemente
  auto state = this -> to_tensor(interface.robo.arms[0].state.joint_positions);
  while(steps < reference::T_steps){
    // float value;
    // vector<float> actions_dist; //Potential Tensor
    auto action_dist = policy->forward(state);
    auto value = vnet->forward(state);
    values.push_back(value);
    rewards.push_back(this -> reward_function(state));
    int action_idx = choice_weighted(action_dist.detach()); //Clear it out
    auto logprob = at::log(action_dist[action_idx]);
    logprobs.push_back(logprob);
    interface.ep2(1,this->action_list[action_idx]);
    state =  to_tensor(interface.robo.arms[0].state.joint_positions);
    torch::Tensor qvalue;
    if (this -> end_condition(state)){
      qvalue = vnet->forward(state); //Detach
      break;
    }
  for(int i = reference::T_steps - 1; i >= 0; i--){
    qvalue = rewards[i] + gamma * qvalue;
    qvalues.insert(qvalues.begin(), qvalue);
  }
  }
  // vector<float> qvalues;
  // for
}
}

void Reinforce_tracking::neural_networks(int input, int output){
  this -> vnet = new value_network(INPUT);
  this -> policy = new policy_network(INPUT, OUTPUT);
}

torch::Tensor Reinforce_tracking::to_tensor(vector<float>& a){
  torch::Tensor b = torch::empty(a.size());
  for(int i = 0; i < (int)a.size(); i++)
    b[i] = a[i];
  return b;
}

int Reinforce_tracking::choice_weighted(torch::Tensor& list){
  uniform_real_distribution<float> distribution(0.0,1.0);
  default_random_engine generator;
  float sum = 0;
  for(int i = 0; i < list.size(); i++)
    sum += lsit[i];
  distance = distribution(generator) * sum;
  int idx = 0;
  for(auto i: list){
    distance -= i;
    if (distance < 0)
      return idx;
    else
      idx++;
  }
}

torch::Tensor Reinforce_tracking::reward_function(torch::Tensor& state){
  float reward;
  for(int i = 0; i < (int)this -> goal.size(); i++)
    reward += float(state[i] - goal[i],2);
  torch::Tensor r = torch::ones(1);
  r[0] = sqrt(reward);
  return r;
}

bool Reinforce_tracking::end_condition(torch::Tensor& state){
  float epsilon = .000001;
  for(int i = 0; i < goal.size(); i++)
    if(state[i] - goal[i] > epsilon)
      return false
  return true;
}
