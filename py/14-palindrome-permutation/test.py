import unittest
from solution import is_palindrome_permutaion


class IsPalindromePermutationTestCase(unittest.TestCase):

	def test_true(self):
		self.assertTrue(is_palindrome_permutaion('tactcoa'))

	def test_true_ignore_case(self):
		self.assertTrue(is_palindrome_permutaion('TactCoa'))

	def test_true_ignore_spaces(self):
		self.assertTrue(is_palindrome_permutaion('Tact Coa'))

	def test_true_empty_string(self):
		self.assertTrue(is_palindrome_permutaion(''))

	def test_false(self):
		self.assertFalse(is_palindrome_permutaion('not even close bro'))


if __name__ == '__main__':
	unittest.main()
