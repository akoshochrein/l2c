import unittest
from solution import is_permutation, is_permutation_with_sort, is_permutation_with_counters


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


class IsPermutationWithCounterTestCase(unittest.TestCase):

	def test_true(self):
		self.assertTrue(is_permutation_with_counters('abcde', 'edbca'))

	def test_false_letter_mismatch(self):
		self.assertFalse(is_permutation_with_counters('abcde', 'edbcq'))

	def test_false_length_mismatch(self):
		self.assertFalse(is_permutation_with_counters('abcde', 'edbc'))


if __name__ == '__main__':
	unittest.main()
