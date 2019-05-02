#  Software License Agreement (BSD License)
#  Copyright (c) 2019, AMBF.
#  (www.aimlab.wpi.edu)
#
#  All rights reserved.
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions
#  are met:
#
#  * Redistributions of source code must retain the above copyright
#  notice, this list of conditions and the following disclaimer.
#
#  * Redistributions in binary form must reproduce the above
#  copyright notice, this list of conditions and the following
#  disclaimer in the documentation and/or other materials provided
#  with the distribution.
#
#  * Neither the name of authors nor the names of its contributors may
#  be used to endorse or promote products derived from this software
#  without specific prior written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
#  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
#  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
#  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
#  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
#  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
#  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
#  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
#  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
#  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
#  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
#  POSSIBILITY OF SUCH DAMAGE.
#
#  $Author: seb $
#  $Date: $
#  $Rev:  $


# compute paths
get_filename_component(AMBF_FRAMEWOR_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(AMBF_INCLUDE_DIRS "/home/vidur/Desktop/ambf/src;/home/vidur/Desktop/ambf/external/bullet/src;/home/vidur/Desktop/ambf/external/Eigen;/home/vidur/Desktop/ambf/external/glew/include;/usr/include;/home/vidur/Desktop/ambf/bin/devel/include;/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_comm/include;/home/vidur/Desktop/ambf/ambf_ros_modules/dvrk_arm/include;/opt/ros/melodic/include;/usr/include")
set(AMBF_DEFINITIONS  -DBT_USE_DOUBLE_PRECISION)

# library dependencies (contains definitions for IMPORTED targets)
if(NOT TARGET AMBF AND NOT AMBF_BINARY_DIR)
  include("${AMBF_CMAKE_DIR}/AMBFTargets.cmake")
endif()

# IMPORTED target created by CHAI3D-BULLETTargets.cmake
set(AMBF_LIBRARIES AMBF)
