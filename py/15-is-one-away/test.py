import unittest
from solution import is_one_away


class IsOneAwayTestCase(unittest.TestCase):

	def test_true_same(self):
		self.assertTrue(is_one_away('apple', 'apple'))

	def test_true_one_missing(self):
		self.assertTrue(is_one_away('apple', 'aple'))

	def test_true_longer_expected(self):
		self.assertTrue(is_one_away('applee', 'apple'))

	def test_true_longer_actual(self):
		self.assertTrue(is_one_away('apple', 'aapple'))

	def test_true_changed_letter(self):
		self.assertTrue(is_one_away('arple', 'apple'))

	def test_false_longer_expected(self):
		self.assertFalse(is_one_away('applepies', 'apple'))

	def test_false_longer_actual(self):
		self.assertFalse(is_one_away('apple', 'pineapple'))

	def test_false_mismatched_letters(self):
		self.assertFalse(is_one_away('apple', 'pears'))

	def test_false_mixed(self):
		self.assertFalse(is_one_away('apple', 'aprles'))


if __name__ == '__main__':
	unittest.main()
