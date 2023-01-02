# generated from rosidl_generator_py/resource/_idl.py.em
# with input from more_interfaces:msg/AddressBook.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_AddressBook(type):
    """Metaclass of message 'AddressBook'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'FEMALE': True,
        'MALE': False,
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
                'more_interfaces.msg.AddressBook')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__address_book
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__address_book
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__address_book
            cls._TYPE_SUPPORT = module.type_support_msg__msg__address_book
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__address_book

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'FEMALE': cls.__constants['FEMALE'],
            'MALE': cls.__constants['MALE'],
        }

    @property
    def FEMALE(self):
        """Message constant 'FEMALE'."""
        return Metaclass_AddressBook.__constants['FEMALE']

    @property
    def MALE(self):
        """Message constant 'MALE'."""
        return Metaclass_AddressBook.__constants['MALE']


class AddressBook(metaclass=Metaclass_AddressBook):
    """
    Message class 'AddressBook'.

    Constants:
      FEMALE
      MALE
    """

    __slots__ = [
        '_first_name',
        '_last_name',
        '_gender',
        '_age',
        '_address',
    ]

    _fields_and_field_types = {
        'first_name': 'string',
        'last_name': 'string',
        'gender': 'boolean',
        'age': 'uint8',
        'address': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.first_name = kwargs.get('first_name', str())
        self.last_name = kwargs.get('last_name', str())
        self.gender = kwargs.get('gender', bool())
        self.age = kwargs.get('age', int())
        self.address = kwargs.get('address', str())

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
        if self.first_name != other.first_name:
            return False
        if self.last_name != other.last_name:
            return False
        if self.gender != other.gender:
            return False
        if self.age != other.age:
            return False
        if self.address != other.address:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def first_name(self):
        """Message field 'first_name'."""
        return self._first_name

    @first_name.setter
    def first_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'first_name' field must be of type 'str'"
        self._first_name = value

    @builtins.property
    def last_name(self):
        """Message field 'last_name'."""
        return self._last_name

    @last_name.setter
    def last_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'last_name' field must be of type 'str'"
        self._last_name = value

    @builtins.property
    def gender(self):
        """Message field 'gender'."""
        return self._gender

    @gender.setter
    def gender(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'gender' field must be of type 'bool'"
        self._gender = value

    @builtins.property
    def age(self):
        """Message field 'age'."""
        return self._age

    @age.setter
    def age(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'age' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'age' field must be an unsigned integer in [0, 255]"
        self._age = value

    @builtins.property
    def address(self):
        """Message field 'address'."""
        return self._address

    @address.setter
    def address(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'address' field must be of type 'str'"
        self._address = value
