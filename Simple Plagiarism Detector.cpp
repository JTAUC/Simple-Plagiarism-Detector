#include "Includes.h"
#include "Document.h"

int main()
{
    vector<Document> corpus;
    Document d("new.txt");

    cout << d.getFullText() << endl;

    d.printSentences();
}