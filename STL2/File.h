#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<string> readFile(const string& filename);
map<string, int> buildFrequencyDictionary(const vector<string>& lines);
void printWordFrequencies(const map<string, int>& wordFreq);
pair<string, int> getMostFrequentWord(const map<string, int>& wordFreq);
void writeFrequenciesToFile(const map<string, int>& wordFreq, const string& outputFile);

