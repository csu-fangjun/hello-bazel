# Copyright (C) 2018, Fangjun Kuang <fangjun.kuang at gmail dot com>

import unittest

from person import Person


class PersonTest(unittest.TestCase):
    def setUp(self):
        self._person = Person("Tom", 10)

    def test_name(self):
        self.assertEqual(self._person.name, "Tom")

    def test_age(self):
        with self.assertRaises(AssertionError):
            self._person.age = -2


if __name__ == "__main__":
    unittest.main()
