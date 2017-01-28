import unittest
from solution import is_permutation, is_permutation_with_sort


class IsPermutationTestCase(unittest.TestCase):

	def test_true(self):
		self.assertTrue(is_permutation('abcde', 'edbca'))

	def test_false_letter_mismatch(self):
		self.assertFalse(is_permutation('abcde', 'edbcq'))

	def test_false_length_mismatch(self):
		self.assertFalse(is_permutation('abcde', 'edbc'))


class IsPermutationWithSortTestCase(unittest.TestCase):

	def test_true(self):
		self.assertTrue(is_permutation_with_sort('abcde', 'edbca'))

	def test_false_letter_mismatch(self):
		self.assertFalse(is_permutation_with_sort('abcde', 'edbcq'))

	def test_false_length_mismatch(self):
		self.assertFalse(is_permutation_with_sort('abcde', 'edbc'))


if __name__ == '__main__':
	unittest.main()
