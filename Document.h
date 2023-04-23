#pragma once
#include "Includes.h"

class Document
{
private:
	vector<string> sentences;
	string full_text;
	string file_name;
	fstream file;

	int number_of_sentences;

	void partitionDocument();

public:
	Document(string fileName);

	~Document();

	void printSentences() const; //Prints all the sentences in a document.

	string getFullText() const; //Returns the full text of a document in one string.

	string getFileName() const; //Returns the file name of the document.

	void getSentences(vector<string>& s) const; //Returns the sentences vector by reference.

	int getNumberOfSentences() const; //Returns number of sentences in the document.

	void setFileName(string s); //Set the file name of the document.

	
};

