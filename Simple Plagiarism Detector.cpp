#include "Includes.h"
#include "Document.h"
#include "BruteForceMatcher.h"
#include "Match.h"


vector<Match> exact_matches;
BruteForceMatcher BFMatcher;

float GetHammingDistances(vector<string> s1, vector<string> s2) { //Calculates hamming distance between each sentence in two documents, 
    int commonCharacters = 0, c = 0;                              //if it is less than a given constant it is considered plagiarism. 
    for (int i = 0; i < s1.size(); i++) {                         //Function returns number of plagiarized characters.
        for (int j = 0; j < s2.size(); j++) {
            if (BFMatcher.HammingDistance(s1[i], s2[j], c) <= 5) {
                commonCharacters += c;
            }
        }
    }
    return commonCharacters;
}

void BruteForce(const Document& d1, const Document& d2) {
    
    vector<string> d1_sentences, d2_sentences;
    d1.getSentences(d1_sentences);
    d2.getSentences(d2_sentences);

    cout << "AVG: " << (GetHammingDistances(d1_sentences, d2_sentences) / d1.getFullText().length()) * 100 << endl;
    
    for (int i = 0; i < d2_sentences.size(); i++) {
        int index = BFMatcher.runDetection(d1, d2_sentences[i]);
        if (index != -1) {
            exact_matches.push_back(Match(i, index, d2_sentences[i], d1.getFileName()));
        }
    }
}

int main()
{
    vector<Document> corpus;

    const Document Doc1("Book1.txt");
    const Document Doc2("Book2.txt");
    const Document Doc3("Book3.txt");
    const Document Doc4("Book4.txt");
    corpus.push_back(Doc2);
    corpus.push_back(Doc3);
    corpus.push_back(Doc4);

    Document Plagiarized("Plagiarized.txt");

    BruteForce(Doc1, Plagiarized);
    BruteForce(Doc2, Plagiarized);
    BruteForce(Doc3, Plagiarized);
    BruteForce(Doc4, Plagiarized);

    for (int i = 0; i < exact_matches.size(); i++) {
        cout << "Exact Match Found: " << exact_matches[i].GetText() << "At: " << exact_matches[i].GetCharIndex() << "From: " << exact_matches[i].GetDocumentName() << endl;
        cout << "\n";
    }

}