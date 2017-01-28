
def is_unique(s):
	char_set = set()
	for c in s:
		if c in char_set:
			return False
		else:
			char_set.add(c)
	return True
