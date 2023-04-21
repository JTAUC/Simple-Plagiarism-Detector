#pragma once
#include "Includes.h"

class Document
{
private:
	vector<string> sentences;
	string full_text;
	string file_name;
	fstream file;

	void partitionDocument();

public:
	Document(string fileName);

	~Document();

	void printSentences(); //Prints all the sentences in a document.

	string getFullText(); //Returns the full text of a document in one string.

	string getFileName(); //Returns the file name of the document.

	void getSentences(vector<string>& s); //Returns the sentences vector by reference.

	void setFileName(string s); //Set the file name of the document.
};

