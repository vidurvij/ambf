;; Auto-generated. Do not edit!


(when (boundp 'ambf_msgs::WorldState)
  (if (not (find-package "AMBF_MSGS"))
    (make-package "AMBF_MSGS"))
  (shadow 'WorldState (find-package "AMBF_MSGS")))
(unless (find-package "AMBF_MSGS::WORLDSTATE")
  (make-package "AMBF_MSGS::WORLDSTATE"))

(in-package "ROS")
;;//! \htmlinclude WorldState.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass ambf_msgs::WorldState
  :super ros::object
  :slots (_header _dynamic_loop_freq _n_devices _sim_step _wall_time _sim_time ))

(defmethod ambf_msgs::WorldState
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:dynamic_loop_freq __dynamic_loop_freq) 0)
    ((:n_devices __n_devices) 0)
    ((:sim_step __sim_step) 0)
    ((:wall_time __wall_time) 0.0)
    ((:sim_time __sim_time) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _dynamic_loop_freq (round __dynamic_loop_freq))
   (setq _n_devices (round __n_devices))
   (setq _sim_step (round __sim_step))
   (setq _wall_time (float __wall_time))
   (setq _sim_time (float __sim_time))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:dynamic_loop_freq
   (&optional __dynamic_loop_freq)
   (if __dynamic_loop_freq (setq _dynamic_loop_freq __dynamic_loop_freq)) _dynamic_loop_freq)
  (:n_devices
   (&optional __n_devices)
   (if __n_devices (setq _n_devices __n_devices)) _n_devices)
  (:sim_step
   (&optional __sim_step)
   (if __sim_step (setq _sim_step __sim_step)) _sim_step)
  (:wall_time
   (&optional __wall_time)
   (if __wall_time (setq _wall_time __wall_time)) _wall_time)
  (:sim_time
   (&optional __sim_time)
   (if __sim_time (setq _sim_time __sim_time)) _sim_time)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint64 _dynamic_loop_freq
    8
    ;; uint8 _n_devices
    1
    ;; uint32 _sim_step
    4
    ;; float32 _wall_time
    4
    ;; float32 _sim_time
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint64 _dynamic_loop_freq
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _dynamic_loop_freq (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _dynamic_loop_freq) (= (length (_dynamic_loop_freq . bv)) 2)) ;; bignum
              (write-long (ash (elt (_dynamic_loop_freq . bv) 0) 0) s)
              (write-long (ash (elt (_dynamic_loop_freq . bv) 1) -1) s))
             ((and (class _dynamic_loop_freq) (= (length (_dynamic_loop_freq . bv)) 1)) ;; big1
              (write-long (elt (_dynamic_loop_freq . bv) 0) s)
              (write-long (if (>= _dynamic_loop_freq 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _dynamic_loop_freq s)(write-long (if (>= _dynamic_loop_freq 0) 0 #xffffffff) s)))
     ;; uint8 _n_devices
       (write-byte _n_devices s)
     ;; uint32 _sim_step
       (write-long _sim_step s)
     ;; float32 _wall_time
       (sys::poke _wall_time (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _sim_time
       (sys::poke _sim_time (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint64 _dynamic_loop_freq
     
#+(or :alpha :irix6 :x86_64)
      (setf _dynamic_loop_freq (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _dynamic_loop_freq (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; uint8 _n_devices
     (setq _n_devices (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint32 _sim_step
     (setq _sim_step (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float32 _wall_time
     (setq _wall_time (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _sim_time
     (setq _sim_time (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get ambf_msgs::WorldState :md5sum-) "19e71cae5899074bfba211b483c66a1f")
(setf (get ambf_msgs::WorldState :datatype-) "ambf_msgs/WorldState")
(setf (get ambf_msgs::WorldState :definition-)
      "Header  header
uint64  dynamic_loop_freq
uint8   n_devices
uint32  sim_step
float32 wall_time
float32 sim_time


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

")



(provide :ambf_msgs/WorldState "19e71cae5899074bfba211b483c66a1f")


