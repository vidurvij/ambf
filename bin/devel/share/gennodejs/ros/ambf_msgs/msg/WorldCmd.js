// Auto-generated. Do not edit!

// (in-package ambf_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class WorldCmd {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.enable_step_throttling = null;
      this.step_clock = null;
      this.n_skip_steps = null;
    }
    else {
      if (initObj.hasOwnProperty('enable_step_throttling')) {
        this.enable_step_throttling = initObj.enable_step_throttling
      }
      else {
        this.enable_step_throttling = false;
      }
      if (initObj.hasOwnProperty('step_clock')) {
        this.step_clock = initObj.step_clock
      }
      else {
        this.step_clock = false;
      }
      if (initObj.hasOwnProperty('n_skip_steps')) {
        this.n_skip_steps = initObj.n_skip_steps
      }
      else {
        this.n_skip_steps = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type WorldCmd
    // Serialize message field [enable_step_throttling]
    bufferOffset = _serializer.bool(obj.enable_step_throttling, buffer, bufferOffset);
    // Serialize message field [step_clock]
    bufferOffset = _serializer.bool(obj.step_clock, buffer, bufferOffset);
    // Serialize message field [n_skip_steps]
    bufferOffset = _serializer.uint8(obj.n_skip_steps, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type WorldCmd
    let len;
    let data = new WorldCmd(null);
    // Deserialize message field [enable_step_throttling]
    data.enable_step_throttling = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [step_clock]
    data.step_clock = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [n_skip_steps]
    data.n_skip_steps = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 3;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ambf_msgs/WorldCmd';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '6941ddbc8f8196cff4beb0278a6ad79d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool enable_step_throttling
    bool step_clock
    uint8 n_skip_steps
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new WorldCmd(null);
    if (msg.enable_step_throttling !== undefined) {
      resolved.enable_step_throttling = msg.enable_step_throttling;
    }
    else {
      resolved.enable_step_throttling = false
    }

    if (msg.step_clock !== undefined) {
      resolved.step_clock = msg.step_clock;
    }
    else {
      resolved.step_clock = false
    }

    if (msg.n_skip_steps !== undefined) {
      resolved.n_skip_steps = msg.n_skip_steps;
    }
    else {
      resolved.n_skip_steps = 0
    }

    return resolved;
    }
};

module.exports = WorldCmd;
