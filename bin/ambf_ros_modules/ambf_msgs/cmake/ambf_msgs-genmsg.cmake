# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "ambf_msgs: 4 messages, 0 services")

set(MSG_I_FLAGS "-Iambf_msgs:/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg;-Igeometry_msgs:/opt/ros/melodic/share/geometry_msgs/cmake/../msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(ambf_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/ObjectState.msg" NAME_WE)
add_custom_target(_ambf_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ambf_msgs" "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/ObjectState.msg" "std_msgs/String:geometry_msgs/Vector3:geometry_msgs/Pose:std_msgs/Header:geometry_msgs/Quaternion:geometry_msgs/Wrench:geometry_msgs/Point"
)

get_filename_component(_filename "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/ObjectCmd.msg" NAME_WE)
add_custom_target(_ambf_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ambf_msgs" "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/ObjectCmd.msg" "geometry_msgs/Vector3:geometry_msgs/Pose:std_msgs/Header:geometry_msgs/Quaternion:geometry_msgs/Wrench:geometry_msgs/Point"
)

get_filename_component(_filename "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/WorldState.msg" NAME_WE)
add_custom_target(_ambf_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ambf_msgs" "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/WorldState.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/WorldCmd.msg" NAME_WE)
add_custom_target(_ambf_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ambf_msgs" "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/WorldCmd.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(ambf_msgs
  "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/ObjectState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/String.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Wrench.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ambf_msgs
)
_generate_msg_cpp(ambf_msgs
  "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/ObjectCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Wrench.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ambf_msgs
)
_generate_msg_cpp(ambf_msgs
  "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/WorldState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ambf_msgs
)
_generate_msg_cpp(ambf_msgs
  "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/WorldCmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ambf_msgs
)

### Generating Services

### Generating Module File
_generate_module_cpp(ambf_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ambf_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(ambf_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(ambf_msgs_generate_messages ambf_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/ObjectState.msg" NAME_WE)
add_dependencies(ambf_msgs_generate_messages_cpp _ambf_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/ObjectCmd.msg" NAME_WE)
add_dependencies(ambf_msgs_generate_messages_cpp _ambf_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/WorldState.msg" NAME_WE)
add_dependencies(ambf_msgs_generate_messages_cpp _ambf_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/WorldCmd.msg" NAME_WE)
add_dependencies(ambf_msgs_generate_messages_cpp _ambf_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ambf_msgs_gencpp)
add_dependencies(ambf_msgs_gencpp ambf_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ambf_msgs_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(ambf_msgs
  "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/ObjectState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/String.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Wrench.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ambf_msgs
)
_generate_msg_eus(ambf_msgs
  "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/ObjectCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Wrench.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ambf_msgs
)
_generate_msg_eus(ambf_msgs
  "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/WorldState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ambf_msgs
)
_generate_msg_eus(ambf_msgs
  "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/WorldCmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ambf_msgs
)

### Generating Services

### Generating Module File
_generate_module_eus(ambf_msgs
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ambf_msgs
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(ambf_msgs_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(ambf_msgs_generate_messages ambf_msgs_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/ObjectState.msg" NAME_WE)
add_dependencies(ambf_msgs_generate_messages_eus _ambf_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/ObjectCmd.msg" NAME_WE)
add_dependencies(ambf_msgs_generate_messages_eus _ambf_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/WorldState.msg" NAME_WE)
add_dependencies(ambf_msgs_generate_messages_eus _ambf_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/WorldCmd.msg" NAME_WE)
add_dependencies(ambf_msgs_generate_messages_eus _ambf_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ambf_msgs_geneus)
add_dependencies(ambf_msgs_geneus ambf_msgs_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ambf_msgs_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(ambf_msgs
  "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/ObjectState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/String.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Wrench.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ambf_msgs
)
_generate_msg_lisp(ambf_msgs
  "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/ObjectCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Wrench.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ambf_msgs
)
_generate_msg_lisp(ambf_msgs
  "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/WorldState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ambf_msgs
)
_generate_msg_lisp(ambf_msgs
  "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/WorldCmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ambf_msgs
)

### Generating Services

### Generating Module File
_generate_module_lisp(ambf_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ambf_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(ambf_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(ambf_msgs_generate_messages ambf_msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/ObjectState.msg" NAME_WE)
add_dependencies(ambf_msgs_generate_messages_lisp _ambf_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/ObjectCmd.msg" NAME_WE)
add_dependencies(ambf_msgs_generate_messages_lisp _ambf_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/WorldState.msg" NAME_WE)
add_dependencies(ambf_msgs_generate_messages_lisp _ambf_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/WorldCmd.msg" NAME_WE)
add_dependencies(ambf_msgs_generate_messages_lisp _ambf_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ambf_msgs_genlisp)
add_dependencies(ambf_msgs_genlisp ambf_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ambf_msgs_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(ambf_msgs
  "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/ObjectState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/String.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Wrench.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ambf_msgs
)
_generate_msg_nodejs(ambf_msgs
  "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/ObjectCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Wrench.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ambf_msgs
)
_generate_msg_nodejs(ambf_msgs
  "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/WorldState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ambf_msgs
)
_generate_msg_nodejs(ambf_msgs
  "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/WorldCmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ambf_msgs
)

### Generating Services

### Generating Module File
_generate_module_nodejs(ambf_msgs
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ambf_msgs
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(ambf_msgs_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(ambf_msgs_generate_messages ambf_msgs_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/ObjectState.msg" NAME_WE)
add_dependencies(ambf_msgs_generate_messages_nodejs _ambf_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/ObjectCmd.msg" NAME_WE)
add_dependencies(ambf_msgs_generate_messages_nodejs _ambf_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/WorldState.msg" NAME_WE)
add_dependencies(ambf_msgs_generate_messages_nodejs _ambf_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/WorldCmd.msg" NAME_WE)
add_dependencies(ambf_msgs_generate_messages_nodejs _ambf_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ambf_msgs_gennodejs)
add_dependencies(ambf_msgs_gennodejs ambf_msgs_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ambf_msgs_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(ambf_msgs
  "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/ObjectState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/String.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Wrench.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ambf_msgs
)
_generate_msg_py(ambf_msgs
  "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/ObjectCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Wrench.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ambf_msgs
)
_generate_msg_py(ambf_msgs
  "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/WorldState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ambf_msgs
)
_generate_msg_py(ambf_msgs
  "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/WorldCmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ambf_msgs
)

### Generating Services

### Generating Module File
_generate_module_py(ambf_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ambf_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(ambf_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(ambf_msgs_generate_messages ambf_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/ObjectState.msg" NAME_WE)
add_dependencies(ambf_msgs_generate_messages_py _ambf_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/ObjectCmd.msg" NAME_WE)
add_dependencies(ambf_msgs_generate_messages_py _ambf_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/WorldState.msg" NAME_WE)
add_dependencies(ambf_msgs_generate_messages_py _ambf_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg/WorldCmd.msg" NAME_WE)
add_dependencies(ambf_msgs_generate_messages_py _ambf_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ambf_msgs_genpy)
add_dependencies(ambf_msgs_genpy ambf_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ambf_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ambf_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ambf_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(ambf_msgs_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(ambf_msgs_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ambf_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ambf_msgs
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(ambf_msgs_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(ambf_msgs_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ambf_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ambf_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(ambf_msgs_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(ambf_msgs_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ambf_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ambf_msgs
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(ambf_msgs_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(ambf_msgs_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ambf_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ambf_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ambf_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(ambf_msgs_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(ambf_msgs_generate_messages_py std_msgs_generate_messages_py)
endif()
