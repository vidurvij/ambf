// #ifndef REINFORCEMENT_H
// #define REINFORCEMENT_H
//
// #include "intermain.h"
// #include <torch/torch.h>
// #include <random>
// #include <math.h>
//
//
// struct policy_network: torch::nn::Module{
//   policy_network(int state, int output) {
//     fc1 = register_module("fc1", torch::nn::Linear(state, 64));
//     fc2 = register_module("fc2", torch::nn::Linear(64, 32));
//     fc3 = register_module("fc3", torch::nn::Linear(32, output));
//   }
//
//   torch::Tensor forward(torch::Tensor x) {
//     // Use one of many tensor manipulation functions.
//     x = torch::relu(fc1->forward(x.reshape({x.size(0), 784})));
//     // x = torch::dropout(x, /*p=*/0.5, /*train=*/is_training());
//     x = torch::relu(fc2->forward(x));
//     x = torch::log_softmax(fc3->forward(x), /*dim=*/1);
//     return x;
//   }
//
//   torch::nn::Linear fc1{nullptr}, fc2{nullptr}, fc3{nullptr};
//
// };
//
// struct value_network: torch::nn::Module{
//   value_network(int state) {
//     fc1 = register_module("fc1", torch::nn::Linear(state, 64));
//     fc2 = register_module("fc2", torch::nn::Linear(64, 32));
//     fc3 = register_module("fc3", torch::nn::Linear(32, 16));
//     fc4 = register_module("fc3", torch::nn::Linear(16, 1));
//   }
//
//   torch::Tensor forward(torch::Tensor x) {
//     // Use one of many tensor manipulation functions.
//     x = torch::relu(fc1->forward(x.reshape({x.size(0), 784})));
//     // x = torch::dropout(x, /*p=*/0.5, /*train=*/is_training());
//     x = torch::relu(fc2->forward(x));
//     x = fc3->forward(x);
//     x = fc4->forward(x);
//     return x;
//   }
//
//   torch::nn::Linear fc1{nullptr}, fc2{nullptr}, fc3{nullptr}, fc4{nullptr};
//
// };
//
// class Reinforce_tracking{
//   static vector<float> goal; //Replace it within the code
//   static vector<vector<float>> action_list;
// public:
//   float gamma = .9;
//   Interface interface;
//   Reinforce_tracking(int , char**);
//   torch::Tensor to_tensor(vector<float>&);
//   void neural_networks();
//   bool arm_motion();
//   bool arm_reinforce();
//   bool AC2();
//   bool right_arm();
//   torch::Tensor reward_function(torch::Tensor&);
//   int choice_weighted(torch::Tensor);
//   void neural_networks(int, int);
//   bool end_condition(torch::Tensor&);
//   value_network* vnet;
//   policy_network* policy;
// };
//
//
// #endif
