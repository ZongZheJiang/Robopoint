// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robopoint_interfaces:srv/MoveToPoint.idl
// generated code does not contain a copyright notice

#ifndef ROBOPOINT_INTERFACES__SRV__DETAIL__MOVE_TO_POINT__TRAITS_HPP_
#define ROBOPOINT_INTERFACES__SRV__DETAIL__MOVE_TO_POINT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robopoint_interfaces/srv/detail/move_to_point__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robopoint_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const MoveToPoint_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveToPoint_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveToPoint_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace robopoint_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robopoint_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robopoint_interfaces::srv::MoveToPoint_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  robopoint_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robopoint_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const robopoint_interfaces::srv::MoveToPoint_Request & msg)
{
  return robopoint_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robopoint_interfaces::srv::MoveToPoint_Request>()
{
  return "robopoint_interfaces::srv::MoveToPoint_Request";
}

template<>
inline const char * name<robopoint_interfaces::srv::MoveToPoint_Request>()
{
  return "robopoint_interfaces/srv/MoveToPoint_Request";
}

template<>
struct has_fixed_size<robopoint_interfaces::srv::MoveToPoint_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robopoint_interfaces::srv::MoveToPoint_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robopoint_interfaces::srv::MoveToPoint_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace robopoint_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const MoveToPoint_Response & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveToPoint_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveToPoint_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace robopoint_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robopoint_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robopoint_interfaces::srv::MoveToPoint_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  robopoint_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robopoint_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const robopoint_interfaces::srv::MoveToPoint_Response & msg)
{
  return robopoint_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robopoint_interfaces::srv::MoveToPoint_Response>()
{
  return "robopoint_interfaces::srv::MoveToPoint_Response";
}

template<>
inline const char * name<robopoint_interfaces::srv::MoveToPoint_Response>()
{
  return "robopoint_interfaces/srv/MoveToPoint_Response";
}

template<>
struct has_fixed_size<robopoint_interfaces::srv::MoveToPoint_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robopoint_interfaces::srv::MoveToPoint_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robopoint_interfaces::srv::MoveToPoint_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<robopoint_interfaces::srv::MoveToPoint>()
{
  return "robopoint_interfaces::srv::MoveToPoint";
}

template<>
inline const char * name<robopoint_interfaces::srv::MoveToPoint>()
{
  return "robopoint_interfaces/srv/MoveToPoint";
}

template<>
struct has_fixed_size<robopoint_interfaces::srv::MoveToPoint>
  : std::integral_constant<
    bool,
    has_fixed_size<robopoint_interfaces::srv::MoveToPoint_Request>::value &&
    has_fixed_size<robopoint_interfaces::srv::MoveToPoint_Response>::value
  >
{
};

template<>
struct has_bounded_size<robopoint_interfaces::srv::MoveToPoint>
  : std::integral_constant<
    bool,
    has_bounded_size<robopoint_interfaces::srv::MoveToPoint_Request>::value &&
    has_bounded_size<robopoint_interfaces::srv::MoveToPoint_Response>::value
  >
{
};

template<>
struct is_service<robopoint_interfaces::srv::MoveToPoint>
  : std::true_type
{
};

template<>
struct is_service_request<robopoint_interfaces::srv::MoveToPoint_Request>
  : std::true_type
{
};

template<>
struct is_service_response<robopoint_interfaces::srv::MoveToPoint_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROBOPOINT_INTERFACES__SRV__DETAIL__MOVE_TO_POINT__TRAITS_HPP_
