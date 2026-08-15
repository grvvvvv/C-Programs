#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

void countWords() {
    ifstream file("ARTICLE.TXT");
    if (!file) {
        cout << "Error: Cannot open ARTICLE.TXT\n";
        return;
    }

    string word;
    int countThis = 0, countThese = 0;

    while (file >> word) {
        string cleanWord = "";
        for (char ch : word) {
            if (isalpha(ch)) cleanWord += tolower(ch);
        }
        if (cleanWord == "this") countThis++;
        if (cleanWord == "these") countThese++;
    }
    file.close();

    cout << "Count of 'this': " << countThis << endl;
    cout << "Count of 'these': " << countThese << endl;
}

int main() {
    countWords();
    return 0;
}