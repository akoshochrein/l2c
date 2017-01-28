import unittest
from solution import is_unique, is_unique_counter


class IsUniqueTestCase(unittest.TestCase):

	def test_is_unique_true(self):
		self.assertTrue(is_unique('abcdefgh'))

	def test_is_unique_false(self):
		self.assertFalse(is_unique('abccdefgh'))

	def test_is_unique_empty_string(self):
		self.assertTrue(is_unique(''))


class IsUniqueCounterTestCase(unittest.TestCase):

	def test_is_unique_true(self):
		self.assertTrue(is_unique_counter('abcdefgh'))

	def test_is_unique_false(self):
		self.assertFalse(is_unique_counter('abccdefgh'))

	def test_is_unique_empty_string(self):
		self.assertTrue(is_unique_counter(''))


if __name__ == '__main__':
	unittest.main()
