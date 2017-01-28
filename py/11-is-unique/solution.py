from collections import Counter


def is_unique(s):
	char_set = set()
	for c in s:
		if c in char_set:
			return False
		else:
			char_set.add(c)
	return True


def is_unique_counter(s):
	return all(v == 1 for v in Counter(s).values())
