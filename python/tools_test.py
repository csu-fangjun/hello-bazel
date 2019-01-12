# Copyright (C) 2019, Fangjun Kuang <fangjun.kuang at gmail dot com>

import unittest

import tools


class ToolsTest(unittest.TestCase):
    def setUp(self):
        pass

    def test_is_python2(self):
        if tools.isPython2():
            print("python 2")

    def test_is_python3(self):
        if tools.isPython3():
            print("it is python 3")

    def test_is_at_least_python36(self):
        if tools.isAtLeastPython36():
            print("it is at least python 3.6")


if __name__ == "__main__":
    unittest.main()
