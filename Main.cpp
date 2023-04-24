#include "Includes.h"
#include "Document.h"
#include "BruteForceMatcher.h"
#include "Match.h"
#include "RabinKarp.h"

vector<Match> BF_exact_matches, RK_exact_matches;
BruteForceMatcher BFMatcher;
RabinKarp RabinKarpMatcher;

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
    
    for (int i = 0; i < d2.getSentences().size(); i++) { //Sentence Matching
        int index = BFMatcher.runDetection(d1, d2_sentences[i]);
        if (index != -1) {
            BF_exact_matches.push_back(Match(i, index, d2_sentences[i], d1.getFileName()));
        }
    }
}

void RabinKarpFunc(Document d1, Document d2) {
    vector<string> d1_sentences = d1.getSentences(), d2_sentences = d2.getSentences();

    for (int i = 0; i < d1.getSentences().size(); i++) { //Sentence Matching
        for (int j = 0; j < d2.getSentences().size(); j++) {
            int index = 0;
            if (RabinKarpMatcher.runDetection(d1_sentences[i], d2_sentences[j], index)) {
                RK_exact_matches.push_back(Match(i, index, d2_sentences[j], d1.getFileName()));
            }
        }
    }
}

int main()
{
    vector<Document> corpus;

    corpus.push_back(Document("Doc1.txt"));
    corpus.push_back(Document("Doc2.txt"));
    corpus.push_back(Document("Doc3.txt"));
    corpus.push_back(Document("Doc4.txt"));
    corpus.push_back(Document("Doc5.txt"));

    Document Plagiarized("Plagiarized.txt");

    for (int i = 0; i < corpus.size(); i++) {
        BruteForce(corpus[i], Plagiarized);
        RabinKarpFunc(corpus[i], Plagiarized);
    }
        

    for (int i = 0; i < BF_exact_matches.size(); i++) {
        cout << "(BF) Exact Match Found: " << BF_exact_matches[i].GetText() << " At: " << BF_exact_matches[i].GetCharIndex() << " From: " << BF_exact_matches[i].GetDocumentName() << endl;
        cout << "\n";
    }

    for (int i = 0; i < RK_exact_matches.size(); i++) {
        cout << "(RK) Exact Match Found: " << RK_exact_matches[i].GetText() << " At: " << RK_exact_matches[i].GetCharIndex() << " From: " << RK_exact_matches[i].GetDocumentName() << endl;
        cout << "\n";
    }
}