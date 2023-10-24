// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_intermediate_interfaces:msg/VertexConstraint.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERMEDIATE_INTERFACES__MSG__DETAIL__VERTEX_CONSTRAINT__STRUCT_HPP_
#define MY_INTERMEDIATE_INTERFACES__MSG__DETAIL__VERTEX_CONSTRAINT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'cell'
#include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__my_intermediate_interfaces__msg__VertexConstraint __attribute__((deprecated))
#else
# define DEPRECATED__my_intermediate_interfaces__msg__VertexConstraint __declspec(deprecated)
#endif

namespace my_intermediate_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VertexConstraint_
{
  using Type = VertexConstraint_<ContainerAllocator>;

  explicit VertexConstraint_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : cell(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->agent_name = "";
      this->time_step = 0ll;
    }
  }

  explicit VertexConstraint_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : agent_name(_alloc),
    cell(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->agent_name = "";
      this->time_step = 0ll;
    }
  }

  // field types and members
  using _agent_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _agent_name_type agent_name;
  using _cell_type =
    geometry_msgs::msg::PoseStamped_<ContainerAllocator>;
  _cell_type cell;
  using _time_step_type =
    int64_t;
  _time_step_type time_step;

  // setters for named parameter idiom
  Type & set__agent_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->agent_name = _arg;
    return *this;
  }
  Type & set__cell(
    const geometry_msgs::msg::PoseStamped_<ContainerAllocator> & _arg)
  {
    this->cell = _arg;
    return *this;
  }
  Type & set__time_step(
    const int64_t & _arg)
  {
    this->time_step = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_intermediate_interfaces::msg::VertexConstraint_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_intermediate_interfaces::msg::VertexConstraint_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_intermediate_interfaces::msg::VertexConstraint_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_intermediate_interfaces::msg::VertexConstraint_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_intermediate_interfaces::msg::VertexConstraint_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_intermediate_interfaces::msg::VertexConstraint_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_intermediate_interfaces::msg::VertexConstraint_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_intermediate_interfaces::msg::VertexConstraint_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_intermediate_interfaces::msg::VertexConstraint_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_intermediate_interfaces::msg::VertexConstraint_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_intermediate_interfaces__msg__VertexConstraint
    std::shared_ptr<my_intermediate_interfaces::msg::VertexConstraint_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_intermediate_interfaces__msg__VertexConstraint
    std::shared_ptr<my_intermediate_interfaces::msg::VertexConstraint_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VertexConstraint_ & other) const
  {
    if (this->agent_name != other.agent_name) {
      return false;
    }
    if (this->cell != other.cell) {
      return false;
    }
    if (this->time_step != other.time_step) {
      return false;
    }
    return true;
  }
  bool operator!=(const VertexConstraint_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VertexConstraint_

// alias to use template instance with default allocator
using VertexConstraint =
  my_intermediate_interfaces::msg::VertexConstraint_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_intermediate_interfaces

#endif  // MY_INTERMEDIATE_INTERFACES__MSG__DETAIL__VERTEX_CONSTRAINT__STRUCT_HPP_
