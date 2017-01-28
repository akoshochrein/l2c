import unittest
from solution import is_unique


class IsUniqueTest(unittest.TestCase):

	def test_is_unique_true(self):
		self.assertTrue(is_unique('abcdefgh'))

	def test_is_unique_false(self):
		self.assertFalse(is_unique('abccdefgh'))

	def test_is_unique_empty_string(self):
		self.assertTrue(is_unique(''))


if __name__ == '__main__':
	unittest.main()
