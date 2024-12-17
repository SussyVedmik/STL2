#include "File.h"

int main()
{
    string inputFilename = "input.txt";
    string outputFilename = "output.txt";

    vector<string> lines = readFile(inputFilename);

    map<string, int> wordFreq = buildFrequencyDictionary(lines);

    printWordFrequencies(wordFreq);

    auto [mostFrequentWord, freq] = getMostFrequentWord(wordFreq);
    cout << "Most frequent word: " << mostFrequentWord << " (" << freq << " times)" << endl;

    writeFrequenciesToFile(wordFreq, outputFilename);

    return 0;
}
