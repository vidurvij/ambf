#include "Definitions.h"


const int reference::V = -1;
const string reference::robot_name = "raven_2";
const vector<float> reference::zero_joints = {          0,           0,           0,        0,       0,        0,         0};
const int reference::children_size = 7;
const int reference::arms = 2;
const int reference::raven_iksols = 8;
const vector<string> reference::base_names = {"base_link_L", "base_link_R"};
const string reference::prefix = "/ambf/env/";
const string reference::command_string = "Command";
const string reference::state_string = "State";
const vector<string> reference::end_effector_name = {"wrist_L", "wrist_R"};
const int reference::AMBF_rate = 1000;

const vector<vector<float>>   reference::raven_joint_limit    = {{         0,    M_PI*1/4,       -0.17,  -M_PI*2,      -2,       -2,        -2},
                                                               {  M_PI*1/2,    M_PI*3/4,        0.10,   M_PI*2,       2,        2,         2}};  // TODO: finalize this
const vector<vector<float>>   reference::raven_dh_alpha       = {{         0, -75 Deg2Rad, 128 Deg2Rad,        0,  M_PI/2,   M_PI/2,         0},
                                                               {      M_PI,  75 Deg2Rad,  52 Deg2Rad,        0,  M_PI/2,   M_PI/2,         0}};
const vector<vector<float>>   reference::raven_dh_a           = {{         0,           0,           0,        0,       0,    0.013,         0},
                                                               {         0,           0,           0,        0,       0,    0.013,         0}};
const vector<vector<float>>   reference::raven_dh_d           = {{         0,           0,           V,    -0.47,       0,        0,         0},
                                                               {         0,           0,           V,    -0.47,       0,        0,         0}};
const vector<vector<float>>   reference::raven_dh_theta       = {{         V,           V,      M_PI/2,        V,       V,        V,         0},
                                                               {         V,           V,     -M_PI/2,        V,       V,        V,         0}};

const vector<float>           reference::raven_ikin_param     = { (float)sin(reference::raven_dh_alpha[0][1]),     // 0: GM1
                                                                (float)cos(reference::raven_dh_alpha[0][1]),     // 1: GM2
                                                                (float)sin(reference::raven_dh_alpha[1][2]),     // 2: GM3
                                                                (float)cos(reference::raven_dh_alpha[1][2]),     // 3: GM4
                                                                reference::raven_dh_d[0][3]                ,     // 4: d4 = -0.47
                                                                reference::raven_dh_a[0][5]               };     // 5: Lw = 0.013
const vector<float>           reference::home_joints          = {   M_PI*1/3,    M_PI*3/5,       -0.09, M_PI*3/4,       0,   M_PI/6,    M_PI/6};

const vector<tf::Transform>   reference::raven_T_B0           = { tf::Transform(tf::Matrix3x3(0,0,1,0,-1,0,1,0,0),tf::Vector3(0.30071, 0.061, -0.007)),
                                                                tf::Transform(tf::Matrix3x3(0,0,-1,0,1,0,1,0,0),tf::Vector3(-0.30071, 0.061, -0.007))};
const tf::Transform           reference::raven_T_CB           =   tf::Transform(tf::Quaternion(tf::Vector3(0,0,1),-M_PI/2),tf::Vector3(0,0,0));

const vector<unsigned char>   reference::true_joints          = {          1,           1,           1,        1,       1,        1,         1};
const vector<unsigned char>   reference::false_joints         = {          0,           0,           0,        0,       0,        0,         0};
