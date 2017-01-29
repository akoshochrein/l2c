
def compress(s):
	compressed = ''
	prev_letter, prev_letter_count = '', 0

	for i, c in enumerate(s):
		if c == prev_letter:
			prev_letter_count += 1
		elif prev_letter_count > 0:
			compressed += prev_letter + str(prev_letter_count)
			prev_letter, prev_letter_count = c, 1
		else:
			prev_letter, prev_letter_count = c, 1

	if prev_letter_count > 0:
		compressed += prev_letter + str(prev_letter_count)

	return compressed
