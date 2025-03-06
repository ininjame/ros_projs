import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/ininjame/ros2_projs/ros2_ws/install/py_pubsub'
