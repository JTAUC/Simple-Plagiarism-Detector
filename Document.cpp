#include "Document.h"

Document::Document(string fileName) {
	file_name = fileName;
	file.open(file_name);
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

void Document::printSentences() {
	for (int i = 0; i < sentences.size(); i++) {
		cout << sentences[i] << endl;
	}
}

string Document::getFullText() { return full_text; }

string Document::getFileName() { return file_name; }

void Document::getSentences(vector<string>& s) { s = sentences; }

void Document::setFileName(string s) { file_name = s; }