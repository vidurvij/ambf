// Auto-generated. Do not edit!

// (in-package ambf_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class ObjectCmd {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.enable_position_controller = null;
      this.pose = null;
      this.wrench = null;
      this.joint_cmds = null;
      this.position_controller_mask = null;
      this.publish_children_names = null;
      this.publish_joint_names = null;
      this.publish_joint_positions = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('enable_position_controller')) {
        this.enable_position_controller = initObj.enable_position_controller
      }
      else {
        this.enable_position_controller = false;
      }
      if (initObj.hasOwnProperty('pose')) {
        this.pose = initObj.pose
      }
      else {
        this.pose = new geometry_msgs.msg.Pose();
      }
      if (initObj.hasOwnProperty('wrench')) {
        this.wrench = initObj.wrench
      }
      else {
        this.wrench = new geometry_msgs.msg.Wrench();
      }
      if (initObj.hasOwnProperty('joint_cmds')) {
        this.joint_cmds = initObj.joint_cmds
      }
      else {
        this.joint_cmds = [];
      }
      if (initObj.hasOwnProperty('position_controller_mask')) {
        this.position_controller_mask = initObj.position_controller_mask
      }
      else {
        this.position_controller_mask = [];
      }
      if (initObj.hasOwnProperty('publish_children_names')) {
        this.publish_children_names = initObj.publish_children_names
      }
      else {
        this.publish_children_names = false;
      }
      if (initObj.hasOwnProperty('publish_joint_names')) {
        this.publish_joint_names = initObj.publish_joint_names
      }
      else {
        this.publish_joint_names = false;
      }
      if (initObj.hasOwnProperty('publish_joint_positions')) {
        this.publish_joint_positions = initObj.publish_joint_positions
      }
      else {
        this.publish_joint_positions = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ObjectCmd
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [enable_position_controller]
    bufferOffset = _serializer.bool(obj.enable_position_controller, buffer, bufferOffset);
    // Serialize message field [pose]
    bufferOffset = geometry_msgs.msg.Pose.serialize(obj.pose, buffer, bufferOffset);
    // Serialize message field [wrench]
    bufferOffset = geometry_msgs.msg.Wrench.serialize(obj.wrench, buffer, bufferOffset);
    // Serialize message field [joint_cmds]
    bufferOffset = _arraySerializer.float32(obj.joint_cmds, buffer, bufferOffset, null);
    // Serialize message field [position_controller_mask]
    bufferOffset = _arraySerializer.bool(obj.position_controller_mask, buffer, bufferOffset, null);
    // Serialize message field [publish_children_names]
    bufferOffset = _serializer.bool(obj.publish_children_names, buffer, bufferOffset);
    // Serialize message field [publish_joint_names]
    bufferOffset = _serializer.bool(obj.publish_joint_names, buffer, bufferOffset);
    // Serialize message field [publish_joint_positions]
    bufferOffset = _serializer.bool(obj.publish_joint_positions, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ObjectCmd
    let len;
    let data = new ObjectCmd(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [enable_position_controller]
    data.enable_position_controller = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [pose]
    data.pose = geometry_msgs.msg.Pose.deserialize(buffer, bufferOffset);
    // Deserialize message field [wrench]
    data.wrench = geometry_msgs.msg.Wrench.deserialize(buffer, bufferOffset);
    // Deserialize message field [joint_cmds]
    data.joint_cmds = _arrayDeserializer.float32(buffer, bufferOffset, null)
    // Deserialize message field [position_controller_mask]
    data.position_controller_mask = _arrayDeserializer.bool(buffer, bufferOffset, null)
    // Deserialize message field [publish_children_names]
    data.publish_children_names = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [publish_joint_names]
    data.publish_joint_names = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [publish_joint_positions]
    data.publish_joint_positions = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += 4 * object.joint_cmds.length;
    length += object.position_controller_mask.length;
    return length + 116;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ambf_msgs/ObjectCmd';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '091c255bd5039de21056e952538cf83c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
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
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ObjectCmd(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.enable_position_controller !== undefined) {
      resolved.enable_position_controller = msg.enable_position_controller;
    }
    else {
      resolved.enable_position_controller = false
    }

    if (msg.pose !== undefined) {
      resolved.pose = geometry_msgs.msg.Pose.Resolve(msg.pose)
    }
    else {
      resolved.pose = new geometry_msgs.msg.Pose()
    }

    if (msg.wrench !== undefined) {
      resolved.wrench = geometry_msgs.msg.Wrench.Resolve(msg.wrench)
    }
    else {
      resolved.wrench = new geometry_msgs.msg.Wrench()
    }

    if (msg.joint_cmds !== undefined) {
      resolved.joint_cmds = msg.joint_cmds;
    }
    else {
      resolved.joint_cmds = []
    }

    if (msg.position_controller_mask !== undefined) {
      resolved.position_controller_mask = msg.position_controller_mask;
    }
    else {
      resolved.position_controller_mask = []
    }

    if (msg.publish_children_names !== undefined) {
      resolved.publish_children_names = msg.publish_children_names;
    }
    else {
      resolved.publish_children_names = false
    }

    if (msg.publish_joint_names !== undefined) {
      resolved.publish_joint_names = msg.publish_joint_names;
    }
    else {
      resolved.publish_joint_names = false
    }

    if (msg.publish_joint_positions !== undefined) {
      resolved.publish_joint_positions = msg.publish_joint_positions;
    }
    else {
      resolved.publish_joint_positions = false
    }

    return resolved;
    }
};

module.exports = ObjectCmd;
