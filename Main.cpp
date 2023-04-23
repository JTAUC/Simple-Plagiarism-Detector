#include "Includes.h"
#include "Document.h"
#include "BruteForceMatcher.h"
#include "Match.h"

vector<Match> exact_matches;
BruteForceMatcher BFMatcher;

//Calculates hamming distance between each sentence in two documents, 
//if it is less than a given constant it is considered plagiarism.
//Function returns number of plagiarized characters.

float GetHammingDistances(vector<string> s1, vector<string> s2) { 
    int commonCharacters = 0, c = 0;                               
    for (int i = 0; i < s1.size(); i++) {                         
        for (int j = 0; j < s2.size(); j++) {
            if (BFMatcher.HammingDistance(s1[i], s2[j], c) <= 5) {
                commonCharacters += c;
            }
        }
    }
    return commonCharacters;
}

void BruteForce(Document d1, Document d2) {
    
    vector<string> d1_sentences = d1.getSentences(), d2_sentences = d2.getSentences();

    cout << "AVG: " << (GetHammingDistances(d1_sentences, d2_sentences) / d1.getFullText().length()) * 100 << endl;
    
    for (int i = 0; i < d2.getSentences().size(); i++) {
        int index = BFMatcher.runDetection(d1, d2_sentences[i]);
        if (index != -1) {
            exact_matches.push_back(Match(i, index, d2_sentences[i], d1.getFileName()));
        }
    }
}

int main()
{
    vector<Document> corpus;

    corpus.push_back(Document("Book1.txt"));
    corpus.push_back(Document("Book2.txt"));
    corpus.push_back(Document("Book3.txt"));
    corpus.push_back(Document("Book4.txt"));

    Document Plagiarized("Plagiarized.txt");

    for (int i = 0; i < corpus.size(); i++)
        BruteForce(corpus[i], Plagiarized);

    for (int i = 0; i < exact_matches.size(); i++) {
        cout << "Exact Match Found: " << exact_matches[i].GetText() << " At: " << exact_matches[i].GetCharIndex() << " From: " << exact_matches[i].GetDocumentName() << endl;
        cout << "\n";
    }
}