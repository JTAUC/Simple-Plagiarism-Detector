#include "Includes.h"
#include "Document.h"
#include "BruteForceMatcher.h"
#include "Match.h"
#include "RabinKarp.h"

vector<Match> BF_exact_matches, RK_exact_matches;
BruteForceMatcher BFMatcher;
RabinKarp RabinKarpMatcher;

float BF_PlagiarizedCharCount = 0, RK_PlagiarizedCharCount = 0;

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

    cout << "Hamming Distance: " << (GetHammingDistances(d1_sentences, d2_sentences) / d1.getFullText().length()) * 100 << endl;
    
    for (int i = 0; i < d2.getSentences().size(); i++) { //Sentence Matching
        int index = BFMatcher.runDetection(d1, d2_sentences[i]);
        if (index != -1) {
            BF_exact_matches.push_back(Match(i, index, d2_sentences[i], d1.getFileName()));
            BF_PlagiarizedCharCount += d2_sentences[i].length();
        }
    }
}

void RabinKarpFunc(Document d1, Document d2) {
    vector<string> d1_sentences = d1.getSentences(), d2_sentences = d2.getSentences();
    int index = 0;

    for (int i = 0; i < d2.getSentences().size(); i++) { //Sentence Matching
        int index = 0;
        if (RabinKarpMatcher.runDetection(d1.getFullText(), d2_sentences[i], index)) {
            RK_exact_matches.push_back(Match(i, index, d2_sentences[i], d1.getFileName()));
            RK_PlagiarizedCharCount += d2_sentences[i].length();
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

    cout << "Processing...\n" << endl;
    for (int i = 0; i < corpus.size(); i++) {
        BruteForce(corpus[i], Plagiarized);
        cout << "\n";
        RabinKarpFunc(Plagiarized, corpus[i]);
    }

    float totalCharCount = Plagiarized.getFullText().length();

    for (int i = 0; i < BF_exact_matches.size(); i++) {
        cout << "(BF) Exact Match Found: " << BF_exact_matches[i].GetText() << " At: " << BF_exact_matches[i].GetCharIndex() << " From: " << BF_exact_matches[i].GetDocumentName() << endl;
        cout << "\n";
    }

    for (int i = 0; i < RK_exact_matches.size(); i++) {
        cout << "(RK) Exact Match Found: " << RK_exact_matches[i].GetText() << " At: " << RK_exact_matches[i].GetCharIndex() << " From: " << RK_exact_matches[i].GetDocumentName() << endl;
        cout << "\n";
    }
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    float RK_plagiarismPercentage = (RK_PlagiarizedCharCount / totalCharCount) * 100;
    float BF_plagiarismPercentage = (BF_PlagiarizedCharCount / totalCharCount) * 100;

    float avgPlagiarism = (RK_plagiarismPercentage + BF_plagiarismPercentage) / 2;

    cout << RK_PlagiarizedCharCount << endl;
    cout << BF_PlagiarizedCharCount << endl;
    cout << totalCharCount << endl;

    cout << "---------------------------------------- " << endl;
    cout << "Total Plagiarism Detected: " << avgPlagiarism << "%" << endl;
    cout << "---------------------------------------- " << endl;
}