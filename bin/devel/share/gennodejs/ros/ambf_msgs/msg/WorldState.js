// Auto-generated. Do not edit!

// (in-package ambf_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class WorldState {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.dynamic_loop_freq = null;
      this.n_devices = null;
      this.sim_step = null;
      this.wall_time = null;
      this.sim_time = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('dynamic_loop_freq')) {
        this.dynamic_loop_freq = initObj.dynamic_loop_freq
      }
      else {
        this.dynamic_loop_freq = 0;
      }
      if (initObj.hasOwnProperty('n_devices')) {
        this.n_devices = initObj.n_devices
      }
      else {
        this.n_devices = 0;
      }
      if (initObj.hasOwnProperty('sim_step')) {
        this.sim_step = initObj.sim_step
      }
      else {
        this.sim_step = 0;
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
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type WorldState
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [dynamic_loop_freq]
    bufferOffset = _serializer.uint64(obj.dynamic_loop_freq, buffer, bufferOffset);
    // Serialize message field [n_devices]
    bufferOffset = _serializer.uint8(obj.n_devices, buffer, bufferOffset);
    // Serialize message field [sim_step]
    bufferOffset = _serializer.uint32(obj.sim_step, buffer, bufferOffset);
    // Serialize message field [wall_time]
    bufferOffset = _serializer.float32(obj.wall_time, buffer, bufferOffset);
    // Serialize message field [sim_time]
    bufferOffset = _serializer.float32(obj.sim_time, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type WorldState
    let len;
    let data = new WorldState(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [dynamic_loop_freq]
    data.dynamic_loop_freq = _deserializer.uint64(buffer, bufferOffset);
    // Deserialize message field [n_devices]
    data.n_devices = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [sim_step]
    data.sim_step = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [wall_time]
    data.wall_time = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [sim_time]
    data.sim_time = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 21;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ambf_msgs/WorldState';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '19e71cae5899074bfba211b483c66a1f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header  header
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new WorldState(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.dynamic_loop_freq !== undefined) {
      resolved.dynamic_loop_freq = msg.dynamic_loop_freq;
    }
    else {
      resolved.dynamic_loop_freq = 0
    }

    if (msg.n_devices !== undefined) {
      resolved.n_devices = msg.n_devices;
    }
    else {
      resolved.n_devices = 0
    }

    if (msg.sim_step !== undefined) {
      resolved.sim_step = msg.sim_step;
    }
    else {
      resolved.sim_step = 0
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

    return resolved;
    }
};

module.exports = WorldState;
