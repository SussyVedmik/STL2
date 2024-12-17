#include "File.h"

vector<string> splitLineIntoWords(const string& line)
{
    vector<string> words;
    string word;
    for (char ch : line)
    {
        if (ch == ' ' || ch == '\n')
        {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        else
        {
            if (ch >= 'A' && ch <= 'Z')
            {
                ch += 'a' - 'A';
            }
            words.push_back(string(1, ch));
        }
    }
    if (!word.empty())
    {
        words.push_back(word);
    }
    return words;
}

vector<string> readFile(const string& filename)
{
    vector<string> lines;
    FILE* file = fopen(filename.c_str(), "r");
    if (!file)
    {
        cerr << "Error: Could not open file " << filename << endl;
        return lines;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file))
    {
        lines.push_back(string(buffer));
    }
    fclose(file);
    return lines;
}

map<string, int> buildFrequencyDictionary(const vector<string>& lines)
{
    map<string, int> wordFreq;
    for (const string& line : lines)
    {
        vector<string> words = splitLineIntoWords(line);
        for (const string& word : words)
        {
            wordFreq[word]++;
        }
    }
    return wordFreq;
}

void printWordFrequencies(const map<string, int>& wordFreq)
{
    cout << "Word frequencies:" << endl;
    for (const auto& [word, freq] : wordFreq)
    {
        cout << word << ": " << freq << endl;
    }
}

pair<string, int> getMostFrequentWord(const map<string, int>& wordFreq)
{
    string mostFrequentWord;
    int maxFreq = 0;
    for (const auto& [word, freq] : wordFreq)
    {
        if (freq > maxFreq)
        {
            mostFrequentWord = word;
            maxFreq = freq;
        }
    }
    return { mostFrequentWord, maxFreq };
}

void writeFrequenciesToFile(const map<string, int>& wordFreq, const string& outputFile)
{
    FILE* file = fopen(outputFile.c_str(), "w");
    if (!file)
    {
        cerr << "Error: Could not open file " << outputFile << endl;
        return;
    }

    for (const auto& [word, freq] : wordFreq)
    {
        fprintf(file, "%s: %d\n", word.c_str(), freq);
    }
    fclose(file);
}
