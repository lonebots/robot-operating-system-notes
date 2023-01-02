# generated from rosidl_generator_py/resource/_idl.py.em
# with input from more_interfaces:msg/MotorDriver.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MotorDriver(type):
    """Metaclass of message 'MotorDriver'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'ON': True,
        'OFF': False,
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('more_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'more_interfaces.msg.MotorDriver')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__motor_driver
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__motor_driver
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__motor_driver
            cls._TYPE_SUPPORT = module.type_support_msg__msg__motor_driver
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__motor_driver

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'ON': cls.__constants['ON'],
            'OFF': cls.__constants['OFF'],
        }

    @property
    def ON(self):
        """Message constant 'ON'."""
        return Metaclass_MotorDriver.__constants['ON']

    @property
    def OFF(self):
        """Message constant 'OFF'."""
        return Metaclass_MotorDriver.__constants['OFF']


class MotorDriver(metaclass=Metaclass_MotorDriver):
    """
    Message class 'MotorDriver'.

    Constants:
      ON
      OFF
    """

    __slots__ = [
        '_device_id',
        '_rot_ang',
        '_power_in',
        '_rpm',
    ]

    _fields_and_field_types = {
        'device_id': 'string',
        'rot_ang': 'uint8',
        'power_in': 'uint8',
        'rpm': 'uint64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.device_id = kwargs.get('device_id', str())
        self.rot_ang = kwargs.get('rot_ang', int())
        self.power_in = kwargs.get('power_in', int())
        self.rpm = kwargs.get('rpm', int())

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
        if self.device_id != other.device_id:
            return False
        if self.rot_ang != other.rot_ang:
            return False
        if self.power_in != other.power_in:
            return False
        if self.rpm != other.rpm:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def device_id(self):
        """Message field 'device_id'."""
        return self._device_id

    @device_id.setter
    def device_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'device_id' field must be of type 'str'"
        self._device_id = value

    @builtins.property
    def rot_ang(self):
        """Message field 'rot_ang'."""
        return self._rot_ang

    @rot_ang.setter
    def rot_ang(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'rot_ang' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'rot_ang' field must be an unsigned integer in [0, 255]"
        self._rot_ang = value

    @builtins.property
    def power_in(self):
        """Message field 'power_in'."""
        return self._power_in

    @power_in.setter
    def power_in(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'power_in' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'power_in' field must be an unsigned integer in [0, 255]"
        self._power_in = value

    @builtins.property
    def rpm(self):
        """Message field 'rpm'."""
        return self._rpm

    @rpm.setter
    def rpm(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'rpm' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'rpm' field must be an unsigned integer in [0, 18446744073709551615]"
        self._rpm = value
