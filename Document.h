#pragma once
#include "Includes.h"

class Document
{
private:
	string full_text;
	string file_name;

	vector<string> sentences;

	int number_of_sentences;

	void partitionDocument();

public:
	

	Document(string fileName);

	void printSentences(); //Prints all the sentences in a document.

	string getFullText(); //Returns the full text of a document in one string.

	string getFileName(); //Returns the file name of the document.

	vector<string> getSentences(); //Returns the sentences vector by reference.

	int getNumberOfSentences(); //Returns number of sentences in the document.

	void setFileName(string s); //Set the file name of the document.

	
};

