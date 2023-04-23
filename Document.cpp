#include "Document.h"

Document::Document(std::string fileName) {
	file_name = fileName;
	number_of_sentences = 0;
	partitionDocument();
}

void Document::partitionDocument()  {
	std::string line, sentence;
	fstream file;
	file.open(file_name);
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
	file.close();
}

void Document::printSentences()    {
	for (int i = 0; i < sentences.size(); i++) {
		cout << sentences[i] << endl;
	}
}

string Document::getFullText() { return full_text; }

string Document::getFileName() { return file_name; }

vector<string> Document::getSentences() { return sentences; }

int Document::getNumberOfSentences() { return sentences.size(); }

void Document::setFileName(string s) { file_name = s; }