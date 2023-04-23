#include "Document.h"

Document::Document(string fileName) {
	file_name = fileName;
	file.open(file_name);
	number_of_sentences = 0;
	partitionDocument();
}

Document::~Document() {
	file.close();
}

void Document::partitionDocument() {
	string line, sentence;
	while (!file.eof()) {
		getline(file, line);
		full_text += line;
		for (int i = 0; i < line.length(); i++) {
			if (line[i] != '.') {
				sentence += line[i];
			}
			else {
				sentence += line[i];
				sentences.push_back(sentence);
				sentence = "";
			}
		}
	}
}

void Document::printSentences() const {
	for (int i = 0; i < sentences.size(); i++) {
		cout << sentences[i] << endl;
	}
}

 string Document::getFullText() const { return full_text; } 

string Document::getFileName() const { return file_name; }

void Document::getSentences(vector<string>& s) const { s = sentences; }

int Document::getNumberOfSentences() const { return sentences.size(); }

void Document::setFileName(string s) { file_name = s; }