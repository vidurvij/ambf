#include "intermain.h"
// #include "chai3d.h"
// #include "ambf.h"
// //---------------------------------------------------------------------------
// #include <GLFW/glfw3.h>
// #include <boost/program_options.hpp>
// #include <mutex>
// #include <thread>
// #include <map>
// #include <termios.h>
// //---------------------------------------------------------------------------
// using namespace ambf;
// using namespace chai3d;
// using namespace std;
// //------------------------------

int main(int argc, char* argv[]){
  // ros::init(argc, argv, "my_node_nam/e");
  ros::init(argc,argv,"FridayisAlive");
  Interface I(argc, argv);
  thread test(&Interface::publish_process, &I);
  test.join();
  return 0;
}
