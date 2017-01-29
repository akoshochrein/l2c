from collections import Counter


def is_one_away(expected, actual):
	result = True

	freq_actual = Counter(actual)
	for c in expected:
		if c in freq_actual and freq_actual[c] > 0:
			freq_actual[c] -= 1

	if sum(freq_actual.values()) > 1 or abs(len(expected) - len(actual)) > 1:
		result = False

	return result
