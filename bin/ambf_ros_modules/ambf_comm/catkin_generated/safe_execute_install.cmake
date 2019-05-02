execute_process(COMMAND "/home/vidur/Desktop/ambf/bin/ambf_ros_modules/ambf_comm/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/vidur/Desktop/ambf/bin/ambf_ros_modules/ambf_comm/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
