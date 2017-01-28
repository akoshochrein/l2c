from collections import Counter


def is_palindrome_permutaion(s):
	letter_frequency = Counter(s.replace(' ', '').lower())
	number_of_odd_letters = len(filter(lambda f: f % 2 == 1, letter_frequency.values()))
	return not number_of_odd_letters > 1
