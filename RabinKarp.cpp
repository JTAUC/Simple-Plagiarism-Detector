#include "RabinKarp.h"

bool RabinKarp::runDetection(string doc, string subString, int& index) {
	string baseString = doc;
	int n = baseString.length();
	int m = subString.length();
	int hashValue = 0, hashSum = 0;
	int modulus = 100;
	int totalChar = 128;
	int h = 1;
	bool detected = true;

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

	for (int i = 0; i < n - m; i++) {
		if (hashSum == hashValue) {
			for (int j = 0; j < m; j++) {
				if (subString.at(j) != baseString.at(i + j)) {
					detected = false;
					break;
				}
			}
			if (detected) {
				cout << "DETECTED" << endl;
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
