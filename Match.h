#pragma once
#include "Includes.h"
class Match
{
private:
	int sentenceIndex;
	int charIndex;

	string documentName;
	string text;
public:
	Match(int sIndex, string txt, string doc);

	Match(int sIndex, int cIndex, string txt, string doc);

	int GetSentenceIndex();

	int GetCharIndex();

	string GetText();

	string GetDocumentName();
};

