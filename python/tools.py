import sys


def isPython2():
    return sys.version_info.major == 2


def isPython3():
    return sys.version_info.major == 3


def isAtLeastPython36():
    return sys.version_info.major >= 3 and sys.version_info.minor >= 6
