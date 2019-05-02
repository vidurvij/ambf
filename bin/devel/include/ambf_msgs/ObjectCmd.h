// Generated by gencpp from file ambf_msgs/ObjectCmd.msg
// DO NOT EDIT!


#ifndef AMBF_MSGS_MESSAGE_OBJECTCMD_H
#define AMBF_MSGS_MESSAGE_OBJECTCMD_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Wrench.h>

namespace ambf_msgs
{
template <class ContainerAllocator>
struct ObjectCmd_
{
  typedef ObjectCmd_<ContainerAllocator> Type;

  ObjectCmd_()
    : header()
    , enable_position_controller(false)
    , pose()
    , wrench()
    , joint_cmds()
    , position_controller_mask()
    , publish_children_names(false)
    , publish_joint_names(false)
    , publish_joint_positions(false)  {
    }
  ObjectCmd_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , enable_position_controller(false)
    , pose(_alloc)
    , wrench(_alloc)
    , joint_cmds(_alloc)
    , position_controller_mask(_alloc)
    , publish_children_names(false)
    , publish_joint_names(false)
    , publish_joint_positions(false)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint8_t _enable_position_controller_type;
  _enable_position_controller_type enable_position_controller;

   typedef  ::geometry_msgs::Pose_<ContainerAllocator>  _pose_type;
  _pose_type pose;

   typedef  ::geometry_msgs::Wrench_<ContainerAllocator>  _wrench_type;
  _wrench_type wrench;

   typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _joint_cmds_type;
  _joint_cmds_type joint_cmds;

   typedef std::vector<uint8_t, typename ContainerAllocator::template rebind<uint8_t>::other >  _position_controller_mask_type;
  _position_controller_mask_type position_controller_mask;

   typedef uint8_t _publish_children_names_type;
  _publish_children_names_type publish_children_names;

   typedef uint8_t _publish_joint_names_type;
  _publish_joint_names_type publish_joint_names;

   typedef uint8_t _publish_joint_positions_type;
  _publish_joint_positions_type publish_joint_positions;





  typedef boost::shared_ptr< ::ambf_msgs::ObjectCmd_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ambf_msgs::ObjectCmd_<ContainerAllocator> const> ConstPtr;

}; // struct ObjectCmd_

typedef ::ambf_msgs::ObjectCmd_<std::allocator<void> > ObjectCmd;

typedef boost::shared_ptr< ::ambf_msgs::ObjectCmd > ObjectCmdPtr;
typedef boost::shared_ptr< ::ambf_msgs::ObjectCmd const> ObjectCmdConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ambf_msgs::ObjectCmd_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ambf_msgs::ObjectCmd_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ambf_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg'], 'ambf_msgs': ['/home/vidur/Desktop/ambf/ambf_ros_modules/ambf_msgs/msg'], 'geometry_msgs': ['/opt/ros/melodic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::ambf_msgs::ObjectCmd_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ambf_msgs::ObjectCmd_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ambf_msgs::ObjectCmd_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ambf_msgs::ObjectCmd_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ambf_msgs::ObjectCmd_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ambf_msgs::ObjectCmd_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ambf_msgs::ObjectCmd_<ContainerAllocator> >
{
  static const char* value()
  {
    return "091c255bd5039de21056e952538cf83c";
  }

  static const char* value(const ::ambf_msgs::ObjectCmd_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x091c255bd5039de2ULL;
  static const uint64_t static_value2 = 0x1056e952538cf83cULL;
};

template<class ContainerAllocator>
struct DataType< ::ambf_msgs::ObjectCmd_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ambf_msgs/ObjectCmd";
  }

  static const char* value(const ::ambf_msgs::ObjectCmd_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ambf_msgs::ObjectCmd_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
bool enable_position_controller\n\
geometry_msgs/Pose pose\n\
geometry_msgs/Wrench wrench\n\
float32[] joint_cmds\n\
bool[] position_controller_mask\n\
bool publish_children_names\n\
bool publish_joint_names\n\
bool publish_joint_positions\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of position and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Wrench\n\
# This represents force in free space, separated into\n\
# its linear and angular parts.\n\
Vector3  force\n\
Vector3  torque\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Vector3\n\
# This represents a vector in free space. \n\
# It is only meant to represent a direction. Therefore, it does not\n\
# make sense to apply a translation to it (e.g., when applying a \n\
# generic rigid transformation to a Vector3, tf2 will only apply the\n\
# rotation). If you want your data to be translatable too, use the\n\
# geometry_msgs/Point message instead.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
";
  }

  static const char* value(const ::ambf_msgs::ObjectCmd_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ambf_msgs::ObjectCmd_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.enable_position_controller);
      stream.next(m.pose);
      stream.next(m.wrench);
      stream.next(m.joint_cmds);
      stream.next(m.position_controller_mask);
      stream.next(m.publish_children_names);
      stream.next(m.publish_joint_names);
      stream.next(m.publish_joint_positions);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ObjectCmd_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ambf_msgs::ObjectCmd_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ambf_msgs::ObjectCmd_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "enable_position_controller: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.enable_position_controller);
    s << indent << "pose: ";
    s << std::endl;
    Printer< ::geometry_msgs::Pose_<ContainerAllocator> >::stream(s, indent + "  ", v.pose);
    s << indent << "wrench: ";
    s << std::endl;
    Printer< ::geometry_msgs::Wrench_<ContainerAllocator> >::stream(s, indent + "  ", v.wrench);
    s << indent << "joint_cmds[]" << std::endl;
    for (size_t i = 0; i < v.joint_cmds.size(); ++i)
    {
      s << indent << "  joint_cmds[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.joint_cmds[i]);
    }
    s << indent << "position_controller_mask[]" << std::endl;
    for (size_t i = 0; i < v.position_controller_mask.size(); ++i)
    {
      s << indent << "  position_controller_mask[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.position_controller_mask[i]);
    }
    s << indent << "publish_children_names: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.publish_children_names);
    s << indent << "publish_joint_names: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.publish_joint_names);
    s << indent << "publish_joint_positions: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.publish_joint_positions);
  }
};

} // namespace message_operations
} // namespace ros

#endif // AMBF_MSGS_MESSAGE_OBJECTCMD_H
