#include "BruteForceMatcher.h"

int BruteForceMatcher::runDetection(Document d, string pattern) {
	string text = d.getFullText();
	int n, m;
	n = text.length() - 1;
	m = pattern.length() - 1;

	for (int i = 0; i < n - m; i++) {
		int j = 0;
		while ((j < m) && (pattern[j] == text[i + j])) {
			j++;
		}
		if (j == m) { return i; }
	}
	return -1;
}

int BruteForceMatcher::runDetection(string text, string pattern) {
	int n, m;
	n = text.length() - 1;
	m = pattern.length() - 1;

	for (int i = 0; i < n - m; i++) {
		int j = 0;
		while ((j < m) && (pattern[j] == text[i + j])) {
			j++;
		}
		if (j == m) { return i; }
	}
	return -1;
}

int BruteForceMatcher::HammingDistance(string a, string b) {
	int count = 0;
	if (a.size() > b.size())
		swap(a, b);

	for (int i = 0; i < a.length(); i++) {
		if (a[i] != b[i])
			count++;
	}
	return count;
}

int BruteForceMatcher::HammingDistance(string a, string b, int& plagiarizedChars) {
	int count = 0;
	if (a.size() > b.size())
		swap(a, b);
	
	for (int i = 0; i < a.length(); i++) {
		if (a[i] != b[i])
			count++;
	}
	plagiarizedChars = a.length() - count;
	return count;
}


