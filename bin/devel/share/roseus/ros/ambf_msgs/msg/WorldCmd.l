;; Auto-generated. Do not edit!


(when (boundp 'ambf_msgs::WorldCmd)
  (if (not (find-package "AMBF_MSGS"))
    (make-package "AMBF_MSGS"))
  (shadow 'WorldCmd (find-package "AMBF_MSGS")))
(unless (find-package "AMBF_MSGS::WORLDCMD")
  (make-package "AMBF_MSGS::WORLDCMD"))

(in-package "ROS")
;;//! \htmlinclude WorldCmd.msg.html


(defclass ambf_msgs::WorldCmd
  :super ros::object
  :slots (_enable_step_throttling _step_clock _n_skip_steps ))

(defmethod ambf_msgs::WorldCmd
  (:init
   (&key
    ((:enable_step_throttling __enable_step_throttling) nil)
    ((:step_clock __step_clock) nil)
    ((:n_skip_steps __n_skip_steps) 0)
    )
   (send-super :init)
   (setq _enable_step_throttling __enable_step_throttling)
   (setq _step_clock __step_clock)
   (setq _n_skip_steps (round __n_skip_steps))
   self)
  (:enable_step_throttling
   (&optional __enable_step_throttling)
   (if __enable_step_throttling (setq _enable_step_throttling __enable_step_throttling)) _enable_step_throttling)
  (:step_clock
   (&optional __step_clock)
   (if __step_clock (setq _step_clock __step_clock)) _step_clock)
  (:n_skip_steps
   (&optional __n_skip_steps)
   (if __n_skip_steps (setq _n_skip_steps __n_skip_steps)) _n_skip_steps)
  (:serialization-length
   ()
   (+
    ;; bool _enable_step_throttling
    1
    ;; bool _step_clock
    1
    ;; uint8 _n_skip_steps
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _enable_step_throttling
       (if _enable_step_throttling (write-byte -1 s) (write-byte 0 s))
     ;; bool _step_clock
       (if _step_clock (write-byte -1 s) (write-byte 0 s))
     ;; uint8 _n_skip_steps
       (write-byte _n_skip_steps s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _enable_step_throttling
     (setq _enable_step_throttling (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _step_clock
     (setq _step_clock (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; uint8 _n_skip_steps
     (setq _n_skip_steps (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get ambf_msgs::WorldCmd :md5sum-) "6941ddbc8f8196cff4beb0278a6ad79d")
(setf (get ambf_msgs::WorldCmd :datatype-) "ambf_msgs/WorldCmd")
(setf (get ambf_msgs::WorldCmd :definition-)
      "bool enable_step_throttling
bool step_clock
uint8 n_skip_steps

")



(provide :ambf_msgs/WorldCmd "6941ddbc8f8196cff4beb0278a6ad79d")


