#pragma once
#include "Document.h"

class BruteForceMatcher
{
private:

public:
	int runDetection(Document d, string pattern);

	int runDetection(string text, string pattern);

	int HammingDistance(string a, string b);

	int HammingDistance(string a, string b, int& plagiarizedChars);

};

