;; Auto-generated. Do not edit!


(when (boundp 'ambf_msgs::ObjectState)
  (if (not (find-package "AMBF_MSGS"))
    (make-package "AMBF_MSGS"))
  (shadow 'ObjectState (find-package "AMBF_MSGS")))
(unless (find-package "AMBF_MSGS::OBJECTSTATE")
  (make-package "AMBF_MSGS::OBJECTSTATE"))

(in-package "ROS")
;;//! \htmlinclude ObjectState.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass ambf_msgs::ObjectState
  :super ros::object
  :slots (_header _sim_step _name _wall_time _sim_time _mass _pInertia _pose _wrench _userdata_description _children_names _joint_names _userdata _joint_positions ))

(defmethod ambf_msgs::ObjectState
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:sim_step __sim_step) 0)
    ((:name __name) (instance std_msgs::String :init))
    ((:wall_time __wall_time) 0.0)
    ((:sim_time __sim_time) 0.0)
    ((:mass __mass) 0.0)
    ((:pInertia __pInertia) (instance geometry_msgs::Point :init))
    ((:pose __pose) (instance geometry_msgs::Pose :init))
    ((:wrench __wrench) (instance geometry_msgs::Wrench :init))
    ((:userdata_description __userdata_description) "")
    ((:children_names __children_names) (let (r) (dotimes (i 0) (push "" r)) r))
    ((:joint_names __joint_names) (let (r) (dotimes (i 0) (push "" r)) r))
    ((:userdata __userdata) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:joint_positions __joint_positions) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _header __header)
   (setq _sim_step (round __sim_step))
   (setq _name __name)
   (setq _wall_time (float __wall_time))
   (setq _sim_time (float __sim_time))
   (setq _mass (float __mass))
   (setq _pInertia __pInertia)
   (setq _pose __pose)
   (setq _wrench __wrench)
   (setq _userdata_description (string __userdata_description))
   (setq _children_names __children_names)
   (setq _joint_names __joint_names)
   (setq _userdata __userdata)
   (setq _joint_positions __joint_positions)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:sim_step
   (&optional __sim_step)
   (if __sim_step (setq _sim_step __sim_step)) _sim_step)
  (:name
   (&rest __name)
   (if (keywordp (car __name))
       (send* _name __name)
     (progn
       (if __name (setq _name (car __name)))
       _name)))
  (:wall_time
   (&optional __wall_time)
   (if __wall_time (setq _wall_time __wall_time)) _wall_time)
  (:sim_time
   (&optional __sim_time)
   (if __sim_time (setq _sim_time __sim_time)) _sim_time)
  (:mass
   (&optional __mass)
   (if __mass (setq _mass __mass)) _mass)
  (:pInertia
   (&rest __pInertia)
   (if (keywordp (car __pInertia))
       (send* _pInertia __pInertia)
     (progn
       (if __pInertia (setq _pInertia (car __pInertia)))
       _pInertia)))
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
  (:userdata_description
   (&optional __userdata_description)
   (if __userdata_description (setq _userdata_description __userdata_description)) _userdata_description)
  (:children_names
   (&optional __children_names)
   (if __children_names (setq _children_names __children_names)) _children_names)
  (:joint_names
   (&optional __joint_names)
   (if __joint_names (setq _joint_names __joint_names)) _joint_names)
  (:userdata
   (&optional __userdata)
   (if __userdata (setq _userdata __userdata)) _userdata)
  (:joint_positions
   (&optional __joint_positions)
   (if __joint_positions (setq _joint_positions __joint_positions)) _joint_positions)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint32 _sim_step
    4
    ;; std_msgs/String _name
    (send _name :serialization-length)
    ;; float32 _wall_time
    4
    ;; float32 _sim_time
    4
    ;; float32 _mass
    4
    ;; geometry_msgs/Point _pInertia
    (send _pInertia :serialization-length)
    ;; geometry_msgs/Pose _pose
    (send _pose :serialization-length)
    ;; geometry_msgs/Wrench _wrench
    (send _wrench :serialization-length)
    ;; string _userdata_description
    4 (length _userdata_description)
    ;; string[] _children_names
    (apply #'+ (mapcar #'(lambda (x) (+ 4 (length x))) _children_names)) 4
    ;; string[] _joint_names
    (apply #'+ (mapcar #'(lambda (x) (+ 4 (length x))) _joint_names)) 4
    ;; float32[] _userdata
    (* 4    (length _userdata)) 4
    ;; float32[] _joint_positions
    (* 4    (length _joint_positions)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint32 _sim_step
       (write-long _sim_step s)
     ;; std_msgs/String _name
       (send _name :serialize s)
     ;; float32 _wall_time
       (sys::poke _wall_time (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _sim_time
       (sys::poke _sim_time (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _mass
       (sys::poke _mass (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; geometry_msgs/Point _pInertia
       (send _pInertia :serialize s)
     ;; geometry_msgs/Pose _pose
       (send _pose :serialize s)
     ;; geometry_msgs/Wrench _wrench
       (send _wrench :serialize s)
     ;; string _userdata_description
       (write-long (length _userdata_description) s) (princ _userdata_description s)
     ;; string[] _children_names
     (write-long (length _children_names) s)
     (dolist (elem _children_names)
       (write-long (length elem) s) (princ elem s)
       )
     ;; string[] _joint_names
     (write-long (length _joint_names) s)
     (dolist (elem _joint_names)
       (write-long (length elem) s) (princ elem s)
       )
     ;; float32[] _userdata
     (write-long (length _userdata) s)
     (dotimes (i (length _userdata))
       (sys::poke (elt _userdata i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[] _joint_positions
     (write-long (length _joint_positions) s)
     (dotimes (i (length _joint_positions))
       (sys::poke (elt _joint_positions i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint32 _sim_step
     (setq _sim_step (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; std_msgs/String _name
     (send _name :deserialize buf ptr-) (incf ptr- (send _name :serialization-length))
   ;; float32 _wall_time
     (setq _wall_time (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _sim_time
     (setq _sim_time (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _mass
     (setq _mass (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; geometry_msgs/Point _pInertia
     (send _pInertia :deserialize buf ptr-) (incf ptr- (send _pInertia :serialization-length))
   ;; geometry_msgs/Pose _pose
     (send _pose :deserialize buf ptr-) (incf ptr- (send _pose :serialization-length))
   ;; geometry_msgs/Wrench _wrench
     (send _wrench :deserialize buf ptr-) (incf ptr- (send _wrench :serialization-length))
   ;; string _userdata_description
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _userdata_description (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string[] _children_names
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _children_names (make-list n))
     (dotimes (i n)
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setf (elt _children_names i) (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
     ))
   ;; string[] _joint_names
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _joint_names (make-list n))
     (dotimes (i n)
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setf (elt _joint_names i) (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
     ))
   ;; float32[] _userdata
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _userdata (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _userdata i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;; float32[] _joint_positions
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _joint_positions (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _joint_positions i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(setf (get ambf_msgs::ObjectState :md5sum-) "5c41957ade5befe08be9e8f0ca23c5c4")
(setf (get ambf_msgs::ObjectState :datatype-) "ambf_msgs/ObjectState")
(setf (get ambf_msgs::ObjectState :definition-)
      "Header header
uint32 sim_step
std_msgs/String name
float32 wall_time
float32 sim_time
float32 mass
geometry_msgs/Point pInertia
geometry_msgs/Pose pose
geometry_msgs/Wrench wrench
string userdata_description
string[] children_names
string[] joint_names
float32[] userdata
float32[] joint_positions

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
MSG: std_msgs/String
string data

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

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



(provide :ambf_msgs/ObjectState "5c41957ade5befe08be9e8f0ca23c5c4")


