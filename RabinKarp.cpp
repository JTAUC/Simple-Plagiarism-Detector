#include "RabinKarp.h"
#include <algorithm>
bool RabinKarp::runDetection(string baseString, string subString, int& index) {
	baseString.erase(remove(baseString.begin(), baseString.end(), ' '), baseString.end());
	subString.erase(remove(subString.begin(), subString.end(), ' '), subString.end());
	int n = baseString.length();
	int m = subString.length();
	int j;
	int hashValue = 0, hashSum = 0;
	int modulus = INT_MAX;
	int totalChar = 256;
	int h = 1;

	if (n < m) {
		swap(baseString, subString);
		swap(n, m);
	}

	for (int i = 0; i < m - 1; i++) {
		h = (h * totalChar) % modulus;
	}
	for (int i = 0; i < m; i++) {
		hashValue = (totalChar * hashValue + subString.at(i)) % modulus;
		hashSum = (totalChar * hashSum + baseString.at(i)) % modulus;;
	}

	if (hashValue < 0) {
		hashValue = (hashValue + modulus);
	}

	for (int i = 0; i < n - m; i++) {

		if (hashSum == hashValue) {
			for (j = 0; j < m; j++) {
				if (subString.at(j) != baseString.at(i + j)) {
					break;
				}
			}
			if (j == m) {
				index = i;
				return true;
			}
		}

		hashSum = (totalChar * (hashSum - baseString.at(i) * h) + baseString.at(i + m)) % modulus;

		if (hashSum < 0) {
			hashSum = (hashSum + modulus);
		}
	}
	return false;
}