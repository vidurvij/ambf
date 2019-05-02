;; Auto-generated. Do not edit!


(when (boundp 'ambf_msgs::ObjectCmd)
  (if (not (find-package "AMBF_MSGS"))
    (make-package "AMBF_MSGS"))
  (shadow 'ObjectCmd (find-package "AMBF_MSGS")))
(unless (find-package "AMBF_MSGS::OBJECTCMD")
  (make-package "AMBF_MSGS::OBJECTCMD"))

(in-package "ROS")
;;//! \htmlinclude ObjectCmd.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass ambf_msgs::ObjectCmd
  :super ros::object
  :slots (_header _enable_position_controller _pose _wrench _joint_cmds _position_controller_mask _publish_children_names _publish_joint_names _publish_joint_positions ))

(defmethod ambf_msgs::ObjectCmd
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:enable_position_controller __enable_position_controller) nil)
    ((:pose __pose) (instance geometry_msgs::Pose :init))
    ((:wrench __wrench) (instance geometry_msgs::Wrench :init))
    ((:joint_cmds __joint_cmds) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:position_controller_mask __position_controller_mask) (let (r) (dotimes (i 0) (push nil r)) r))
    ((:publish_children_names __publish_children_names) nil)
    ((:publish_joint_names __publish_joint_names) nil)
    ((:publish_joint_positions __publish_joint_positions) nil)
    )
   (send-super :init)
   (setq _header __header)
   (setq _enable_position_controller __enable_position_controller)
   (setq _pose __pose)
   (setq _wrench __wrench)
   (setq _joint_cmds __joint_cmds)
   (setq _position_controller_mask __position_controller_mask)
   (setq _publish_children_names __publish_children_names)
   (setq _publish_joint_names __publish_joint_names)
   (setq _publish_joint_positions __publish_joint_positions)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:enable_position_controller
   (&optional __enable_position_controller)
   (if __enable_position_controller (setq _enable_position_controller __enable_position_controller)) _enable_position_controller)
  (:pose
   (&rest __pose)
   (if (keywordp (car __pose))
       (send* _pose __pose)
     (progn
       (if __pose (setq _pose (car __pose)))
       _pose)))
  (:wrench
   (&rest __wrench)
   (if (keywordp (car __wrench))
       (send* _wrench __wrench)
     (progn
       (if __wrench (setq _wrench (car __wrench)))
       _wrench)))
  (:joint_cmds
   (&optional __joint_cmds)
   (if __joint_cmds (setq _joint_cmds __joint_cmds)) _joint_cmds)
  (:position_controller_mask
   (&optional __position_controller_mask)
   (if __position_controller_mask (setq _position_controller_mask __position_controller_mask)) _position_controller_mask)
  (:publish_children_names
   (&optional __publish_children_names)
   (if __publish_children_names (setq _publish_children_names __publish_children_names)) _publish_children_names)
  (:publish_joint_names
   (&optional __publish_joint_names)
   (if __publish_joint_names (setq _publish_joint_names __publish_joint_names)) _publish_joint_names)
  (:publish_joint_positions
   (&optional __publish_joint_positions)
   (if __publish_joint_positions (setq _publish_joint_positions __publish_joint_positions)) _publish_joint_positions)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; bool _enable_position_controller
    1
    ;; geometry_msgs/Pose _pose
    (send _pose :serialization-length)
    ;; geometry_msgs/Wrench _wrench
    (send _wrench :serialization-length)
    ;; float32[] _joint_cmds
    (* 4    (length _joint_cmds)) 4
    ;; bool[] _position_controller_mask
    (* 1    (length _position_controller_mask)) 4
    ;; bool _publish_children_names
    1
    ;; bool _publish_joint_names
    1
    ;; bool _publish_joint_positions
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; bool _enable_position_controller
       (if _enable_position_controller (write-byte -1 s) (write-byte 0 s))
     ;; geometry_msgs/Pose _pose
       (send _pose :serialize s)
     ;; geometry_msgs/Wrench _wrench
       (send _wrench :serialize s)
     ;; float32[] _joint_cmds
     (write-long (length _joint_cmds) s)
     (dotimes (i (length _joint_cmds))
       (sys::poke (elt _joint_cmds i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; bool[] _position_controller_mask
     (write-long (length _position_controller_mask) s)
     (dotimes (i (length _position_controller_mask))
       (if (elt _position_controller_mask i) (write-byte -1 s) (write-byte 0 s))
       )
     ;; bool _publish_children_names
       (if _publish_children_names (write-byte -1 s) (write-byte 0 s))
     ;; bool _publish_joint_names
       (if _publish_joint_names (write-byte -1 s) (write-byte 0 s))
     ;; bool _publish_joint_positions
       (if _publish_joint_positions (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; bool _enable_position_controller
     (setq _enable_position_controller (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; geometry_msgs/Pose _pose
     (send _pose :deserialize buf ptr-) (incf ptr- (send _pose :serialization-length))
   ;; geometry_msgs/Wrench _wrench
     (send _wrench :deserialize buf ptr-) (incf ptr- (send _wrench :serialization-length))
   ;; float32[] _joint_cmds
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _joint_cmds (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _joint_cmds i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;; bool[] _position_controller_mask
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _position_controller_mask (make-list n))
     (dotimes (i n)
     (setf (elt _position_controller_mask i) (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
     ))
   ;; bool _publish_children_names
     (setq _publish_children_names (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _publish_joint_names
     (setq _publish_joint_names (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _publish_joint_positions
     (setq _publish_joint_positions (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get ambf_msgs::ObjectCmd :md5sum-) "091c255bd5039de21056e952538cf83c")
(setf (get ambf_msgs::ObjectCmd :datatype-) "ambf_msgs/ObjectCmd")
(setf (get ambf_msgs::ObjectCmd :definition-)
      "Header header
bool enable_position_controller
geometry_msgs/Pose pose
geometry_msgs/Wrench wrench
float32[] joint_cmds
bool[] position_controller_mask
bool publish_children_names
bool publish_joint_names
bool publish_joint_positions

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

================================================================================
MSG: geometry_msgs/Wrench
# This represents force in free space, separated into
# its linear and angular parts.
Vector3  force
Vector3  torque

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z
")



(provide :ambf_msgs/ObjectCmd "091c255bd5039de21056e952538cf83c")


