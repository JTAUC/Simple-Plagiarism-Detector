#include "Match.h"

Match::Match(int sIndex, string txt, string doc) {
	sentenceIndex = sIndex;
	text = txt;
	documentName = doc;
}
Match::Match(int sIndex, int cIndex, string txt, string doc) {
	sentenceIndex = sIndex;
	charIndex = cIndex;
	text = txt;
	documentName = doc;
}

int Match::GetSentenceIndex() {
	return sentenceIndex;
}

int Match::GetCharIndex() {
	return charIndex;
}

string Match::GetText() {
	return text;
}

string Match::GetDocumentName() {
	return documentName;
}