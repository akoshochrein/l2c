import unittest
from solution import replace_whitespaces


class ReplaceWhitespacesTestCase(unittest.TestCase):

	def test_replaced(self):
		self.assertEquals('a%20s', replace_whitespaces('a '))

	def test_replaced_multiple(self):
		self.assertEquals('%20sa%20s%20s', replace_whitespaces(' a  '))

	def test_no_need_to_replace(self):
		self.assertEquals('a', replace_whitespaces('a'))

	def test_empty_string(self):
		self.assertEquals('', replace_whitespaces(''))


if __name__ == '__main__':
	unittest.main()
