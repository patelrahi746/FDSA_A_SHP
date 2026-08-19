#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string sentence;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    stringstream ss(sentence);

    string word;
    string longestWord = "";
    int maxLength = 0;

    while (ss >> word)
    {
        if (word.length() > maxLength)
        {
            maxLength = word.length();
            longestWord = word;
        }
    }

    cout << "Longest word: " << longestWord << endl;
    cout << "Number of letters: " << maxLength << endl;

    return 0;
}