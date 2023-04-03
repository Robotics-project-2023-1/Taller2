# generated from rosidl_generator_py/resource/_idl.py.em
# with input from robot_interfaces:srv/Reproducir.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Reproducir_Request(type):
    """Metaclass of message 'Reproducir_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('robot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robot_interfaces.srv.Reproducir_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__reproducir__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__reproducir__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__reproducir__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__reproducir__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__reproducir__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Reproducir_Request(metaclass=Metaclass_Reproducir_Request):
    """Message class 'Reproducir_Request'."""

    __slots__ = [
        '_nombre',
    ]

    _fields_and_field_types = {
        'nombre': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.nombre = kwargs.get('nombre', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.nombre != other.nombre:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def nombre(self):
        """Message field 'nombre'."""
        return self._nombre

    @nombre.setter
    def nombre(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'nombre' field must be of type 'str'"
        self._nombre = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Reproducir_Response(type):
    """Metaclass of message 'Reproducir_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('robot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robot_interfaces.srv.Reproducir_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__reproducir__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__reproducir__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__reproducir__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__reproducir__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__reproducir__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Reproducir_Response(metaclass=Metaclass_Reproducir_Response):
    """Message class 'Reproducir_Response'."""

    __slots__ = [
        '_respuesta',
    ]

    _fields_and_field_types = {
        'respuesta': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.respuesta = kwargs.get('respuesta', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.respuesta != other.respuesta:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def respuesta(self):
        """Message field 'respuesta'."""
        return self._respuesta

    @respuesta.setter
    def respuesta(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'respuesta' field must be of type 'bool'"
        self._respuesta = value


class Metaclass_Reproducir(type):
    """Metaclass of service 'Reproducir'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('robot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robot_interfaces.srv.Reproducir')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__reproducir

            from robot_interfaces.srv import _reproducir
            if _reproducir.Metaclass_Reproducir_Request._TYPE_SUPPORT is None:
                _reproducir.Metaclass_Reproducir_Request.__import_type_support__()
            if _reproducir.Metaclass_Reproducir_Response._TYPE_SUPPORT is None:
                _reproducir.Metaclass_Reproducir_Response.__import_type_support__()


class Reproducir(metaclass=Metaclass_Reproducir):
    from robot_interfaces.srv._reproducir import Reproducir_Request as Request
    from robot_interfaces.srv._reproducir import Reproducir_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
