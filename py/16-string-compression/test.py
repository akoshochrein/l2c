import unittest
from solution import compress


class CompressTestCase(unittest.TestCase):

	def test_regular(self):
		self.assertEquals('a3b2c1a4', compress('aaabbcaaaa'))

	def test_singles(self):
		self.assertEquals('a1k1o1s1', compress('akos'))

	def test_single_letter(self):
		self.assertEquals('a10', compress('aaaaaaaaaa'))

	def test_empty(self):
		self.assertEquals('', compress(''))


if __name__ == '__main__':
	unittest.main()
