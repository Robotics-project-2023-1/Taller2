// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_interfaces:srv/Reproducir.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__REPRODUCIR__STRUCT_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__REPRODUCIR__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__srv__Reproducir_Request __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__srv__Reproducir_Request __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Reproducir_Request_
{
  using Type = Reproducir_Request_<ContainerAllocator>;

  explicit Reproducir_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->nombre = "";
    }
  }

  explicit Reproducir_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : nombre(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->nombre = "";
    }
  }

  // field types and members
  using _nombre_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _nombre_type nombre;

  // setters for named parameter idiom
  Type & set__nombre(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->nombre = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::srv::Reproducir_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::srv::Reproducir_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::srv::Reproducir_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::srv::Reproducir_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::Reproducir_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::Reproducir_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::Reproducir_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::Reproducir_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::srv::Reproducir_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::srv::Reproducir_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__srv__Reproducir_Request
    std::shared_ptr<robot_interfaces::srv::Reproducir_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__srv__Reproducir_Request
    std::shared_ptr<robot_interfaces::srv::Reproducir_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Reproducir_Request_ & other) const
  {
    if (this->nombre != other.nombre) {
      return false;
    }
    return true;
  }
  bool operator!=(const Reproducir_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Reproducir_Request_

// alias to use template instance with default allocator
using Reproducir_Request =
  robot_interfaces::srv::Reproducir_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robot_interfaces


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__srv__Reproducir_Response __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__srv__Reproducir_Response __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Reproducir_Response_
{
  using Type = Reproducir_Response_<ContainerAllocator>;

  explicit Reproducir_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->respuesta = false;
    }
  }

  explicit Reproducir_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->respuesta = false;
    }
  }

  // field types and members
  using _respuesta_type =
    bool;
  _respuesta_type respuesta;

  // setters for named parameter idiom
  Type & set__respuesta(
    const bool & _arg)
  {
    this->respuesta = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::srv::Reproducir_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::srv::Reproducir_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::srv::Reproducir_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::srv::Reproducir_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::Reproducir_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::Reproducir_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::Reproducir_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::Reproducir_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::srv::Reproducir_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::srv::Reproducir_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__srv__Reproducir_Response
    std::shared_ptr<robot_interfaces::srv::Reproducir_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__srv__Reproducir_Response
    std::shared_ptr<robot_interfaces::srv::Reproducir_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Reproducir_Response_ & other) const
  {
    if (this->respuesta != other.respuesta) {
      return false;
    }
    return true;
  }
  bool operator!=(const Reproducir_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Reproducir_Response_

// alias to use template instance with default allocator
using Reproducir_Response =
  robot_interfaces::srv::Reproducir_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robot_interfaces

namespace robot_interfaces
{

namespace srv
{

struct Reproducir
{
  using Request = robot_interfaces::srv::Reproducir_Request;
  using Response = robot_interfaces::srv::Reproducir_Response;
};

}  // namespace srv

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__SRV__DETAIL__REPRODUCIR__STRUCT_HPP_
