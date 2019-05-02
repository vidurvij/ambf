; Auto-generated. Do not edit!


(cl:in-package ambf_msgs-msg)


;//! \htmlinclude WorldCmd.msg.html

(cl:defclass <WorldCmd> (roslisp-msg-protocol:ros-message)
  ((enable_step_throttling
    :reader enable_step_throttling
    :initarg :enable_step_throttling
    :type cl:boolean
    :initform cl:nil)
   (step_clock
    :reader step_clock
    :initarg :step_clock
    :type cl:boolean
    :initform cl:nil)
   (n_skip_steps
    :reader n_skip_steps
    :initarg :n_skip_steps
    :type cl:fixnum
    :initform 0))
)

(cl:defclass WorldCmd (<WorldCmd>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <WorldCmd>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'WorldCmd)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ambf_msgs-msg:<WorldCmd> is deprecated: use ambf_msgs-msg:WorldCmd instead.")))

(cl:ensure-generic-function 'enable_step_throttling-val :lambda-list '(m))
(cl:defmethod enable_step_throttling-val ((m <WorldCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ambf_msgs-msg:enable_step_throttling-val is deprecated.  Use ambf_msgs-msg:enable_step_throttling instead.")
  (enable_step_throttling m))

(cl:ensure-generic-function 'step_clock-val :lambda-list '(m))
(cl:defmethod step_clock-val ((m <WorldCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ambf_msgs-msg:step_clock-val is deprecated.  Use ambf_msgs-msg:step_clock instead.")
  (step_clock m))

(cl:ensure-generic-function 'n_skip_steps-val :lambda-list '(m))
(cl:defmethod n_skip_steps-val ((m <WorldCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ambf_msgs-msg:n_skip_steps-val is deprecated.  Use ambf_msgs-msg:n_skip_steps instead.")
  (n_skip_steps m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <WorldCmd>) ostream)
  "Serializes a message object of type '<WorldCmd>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'enable_step_throttling) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'step_clock) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'n_skip_steps)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <WorldCmd>) istream)
  "Deserializes a message object of type '<WorldCmd>"
    (cl:setf (cl:slot-value msg 'enable_step_throttling) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'step_clock) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'n_skip_steps)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<WorldCmd>)))
  "Returns string type for a message object of type '<WorldCmd>"
  "ambf_msgs/WorldCmd")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'WorldCmd)))
  "Returns string type for a message object of type 'WorldCmd"
  "ambf_msgs/WorldCmd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<WorldCmd>)))
  "Returns md5sum for a message object of type '<WorldCmd>"
  "6941ddbc8f8196cff4beb0278a6ad79d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'WorldCmd)))
  "Returns md5sum for a message object of type 'WorldCmd"
  "6941ddbc8f8196cff4beb0278a6ad79d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<WorldCmd>)))
  "Returns full string definition for message of type '<WorldCmd>"
  (cl:format cl:nil "bool enable_step_throttling~%bool step_clock~%uint8 n_skip_steps~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'WorldCmd)))
  "Returns full string definition for message of type 'WorldCmd"
  (cl:format cl:nil "bool enable_step_throttling~%bool step_clock~%uint8 n_skip_steps~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <WorldCmd>))
  (cl:+ 0
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <WorldCmd>))
  "Converts a ROS message object to a list"
  (cl:list 'WorldCmd
    (cl:cons ':enable_step_throttling (enable_step_throttling msg))
    (cl:cons ':step_clock (step_clock msg))
    (cl:cons ':n_skip_steps (n_skip_steps msg))
))
