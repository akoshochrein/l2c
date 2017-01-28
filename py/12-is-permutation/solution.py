from collections import Counter


def is_permutation(s1, s2):
	result = False

	if len(s1) == len(s2):
		letter_frequency = Counter(s1)
		for c in s2:
			if c in letter_frequency:
				letter_frequency[c] -= 1

		if all(v == 0 for v in letter_frequency.values()):
			result = True

	return result


def is_permutation_with_sort(s1, s2):
	return sorted(s1) == sorted(s2) if len(s1) == len(s2) else False
