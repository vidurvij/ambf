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

class ObjectState {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.sim_step = null;
      this.name = null;
      this.wall_time = null;
      this.sim_time = null;
      this.mass = null;
      this.pInertia = null;
      this.pose = null;
      this.wrench = null;
      this.userdata_description = null;
      this.children_names = null;
      this.joint_names = null;
      this.userdata = null;
      this.joint_positions = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('sim_step')) {
        this.sim_step = initObj.sim_step
      }
      else {
        this.sim_step = 0;
      }
      if (initObj.hasOwnProperty('name')) {
        this.name = initObj.name
      }
      else {
        this.name = new std_msgs.msg.String();
      }
      if (initObj.hasOwnProperty('wall_time')) {
        this.wall_time = initObj.wall_time
      }
      else {
        this.wall_time = 0.0;
      }
      if (initObj.hasOwnProperty('sim_time')) {
        this.sim_time = initObj.sim_time
      }
      else {
        this.sim_time = 0.0;
      }
      if (initObj.hasOwnProperty('mass')) {
        this.mass = initObj.mass
      }
      else {
        this.mass = 0.0;
      }
      if (initObj.hasOwnProperty('pInertia')) {
        this.pInertia = initObj.pInertia
      }
      else {
        this.pInertia = new geometry_msgs.msg.Point();
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
      if (initObj.hasOwnProperty('userdata_description')) {
        this.userdata_description = initObj.userdata_description
      }
      else {
        this.userdata_description = '';
      }
      if (initObj.hasOwnProperty('children_names')) {
        this.children_names = initObj.children_names
      }
      else {
        this.children_names = [];
      }
      if (initObj.hasOwnProperty('joint_names')) {
        this.joint_names = initObj.joint_names
      }
      else {
        this.joint_names = [];
      }
      if (initObj.hasOwnProperty('userdata')) {
        this.userdata = initObj.userdata
      }
      else {
        this.userdata = [];
      }
      if (initObj.hasOwnProperty('joint_positions')) {
        this.joint_positions = initObj.joint_positions
      }
      else {
        this.joint_positions = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ObjectState
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [sim_step]
    bufferOffset = _serializer.uint32(obj.sim_step, buffer, bufferOffset);
    // Serialize message field [name]
    bufferOffset = std_msgs.msg.String.serialize(obj.name, buffer, bufferOffset);
    // Serialize message field [wall_time]
    bufferOffset = _serializer.float32(obj.wall_time, buffer, bufferOffset);
    // Serialize message field [sim_time]
    bufferOffset = _serializer.float32(obj.sim_time, buffer, bufferOffset);
    // Serialize message field [mass]
    bufferOffset = _serializer.float32(obj.mass, buffer, bufferOffset);
    // Serialize message field [pInertia]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.pInertia, buffer, bufferOffset);
    // Serialize message field [pose]
    bufferOffset = geometry_msgs.msg.Pose.serialize(obj.pose, buffer, bufferOffset);
    // Serialize message field [wrench]
    bufferOffset = geometry_msgs.msg.Wrench.serialize(obj.wrench, buffer, bufferOffset);
    // Serialize message field [userdata_description]
    bufferOffset = _serializer.string(obj.userdata_description, buffer, bufferOffset);
    // Serialize message field [children_names]
    bufferOffset = _arraySerializer.string(obj.children_names, buffer, bufferOffset, null);
    // Serialize message field [joint_names]
    bufferOffset = _arraySerializer.string(obj.joint_names, buffer, bufferOffset, null);
    // Serialize message field [userdata]
    bufferOffset = _arraySerializer.float32(obj.userdata, buffer, bufferOffset, null);
    // Serialize message field [joint_positions]
    bufferOffset = _arraySerializer.float32(obj.joint_positions, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ObjectState
    let len;
    let data = new ObjectState(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [sim_step]
    data.sim_step = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [name]
    data.name = std_msgs.msg.String.deserialize(buffer, bufferOffset);
    // Deserialize message field [wall_time]
    data.wall_time = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [sim_time]
    data.sim_time = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [mass]
    data.mass = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [pInertia]
    data.pInertia = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    // Deserialize message field [pose]
    data.pose = geometry_msgs.msg.Pose.deserialize(buffer, bufferOffset);
    // Deserialize message field [wrench]
    data.wrench = geometry_msgs.msg.Wrench.deserialize(buffer, bufferOffset);
    // Deserialize message field [userdata_description]
    data.userdata_description = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [children_names]
    data.children_names = _arrayDeserializer.string(buffer, bufferOffset, null)
    // Deserialize message field [joint_names]
    data.joint_names = _arrayDeserializer.string(buffer, bufferOffset, null)
    // Deserialize message field [userdata]
    data.userdata = _arrayDeserializer.float32(buffer, bufferOffset, null)
    // Deserialize message field [joint_positions]
    data.joint_positions = _arrayDeserializer.float32(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += std_msgs.msg.String.getMessageSize(object.name);
    length += object.userdata_description.length;
    object.children_names.forEach((val) => {
      length += 4 + val.length;
    });
    object.joint_names.forEach((val) => {
      length += 4 + val.length;
    });
    length += 4 * object.userdata.length;
    length += 4 * object.joint_positions.length;
    return length + 164;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ambf_msgs/ObjectState';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '5c41957ade5befe08be9e8f0ca23c5c4';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
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
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ObjectState(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.sim_step !== undefined) {
      resolved.sim_step = msg.sim_step;
    }
    else {
      resolved.sim_step = 0
    }

    if (msg.name !== undefined) {
      resolved.name = std_msgs.msg.String.Resolve(msg.name)
    }
    else {
      resolved.name = new std_msgs.msg.String()
    }

    if (msg.wall_time !== undefined) {
      resolved.wall_time = msg.wall_time;
    }
    else {
      resolved.wall_time = 0.0
    }

    if (msg.sim_time !== undefined) {
      resolved.sim_time = msg.sim_time;
    }
    else {
      resolved.sim_time = 0.0
    }

    if (msg.mass !== undefined) {
      resolved.mass = msg.mass;
    }
    else {
      resolved.mass = 0.0
    }

    if (msg.pInertia !== undefined) {
      resolved.pInertia = geometry_msgs.msg.Point.Resolve(msg.pInertia)
    }
    else {
      resolved.pInertia = new geometry_msgs.msg.Point()
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

    if (msg.userdata_description !== undefined) {
      resolved.userdata_description = msg.userdata_description;
    }
    else {
      resolved.userdata_description = ''
    }

    if (msg.children_names !== undefined) {
      resolved.children_names = msg.children_names;
    }
    else {
      resolved.children_names = []
    }

    if (msg.joint_names !== undefined) {
      resolved.joint_names = msg.joint_names;
    }
    else {
      resolved.joint_names = []
    }

    if (msg.userdata !== undefined) {
      resolved.userdata = msg.userdata;
    }
    else {
      resolved.userdata = []
    }

    if (msg.joint_positions !== undefined) {
      resolved.joint_positions = msg.joint_positions;
    }
    else {
      resolved.joint_positions = []
    }

    return resolved;
    }
};

module.exports = ObjectState;
