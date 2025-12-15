#include <iostream>
using namespace std;

void Hangman(int wrong)
{
    cout << "__________\n";
    cout << "|     |\n";

    if (wrong >= 1)
        cout << "|     O\n";
    else
        cout << "|\n";

    if (wrong == 2)
        cout << "|     |\n";
    else if (wrong == 3)
        cout << "|   / |\n";
    else if (wrong >= 4)
        cout << "|   / | \\\n";
    else
        cout << "|\n";

    if (wrong == 5)
        cout << "|   /\n";
    else if (wrong >= 6)
        cout << "|   /   \\\n";
    else
        cout << "|\n";
}

void playGame(string setter, string guesser)
{

    string word;
    string guess;
    char letter;
    int wrong;
    bool found;
    int i;

    wrong = 0;

    cout << setter << ", enter the word: ";
    cin >> word;

    for (i = 0; i < word.length(); i++)
        word[i] = tolower(word[i]);

    guess = string(word.length(), '_');

    system("cls");

    cout << guesser << ", start guessing!\n";

    while (wrong < 6 && guess != word)
    {
        Hangman(wrong);

        cout << "\nWord: " << guess;
        cout << "\nGuess a letter: ";
        cin >> letter;
        letter = tolower(letter);

        found = false;

        for (i = 0; i < word.length(); i++)
        {
            if (word[i] == letter && guess[i] == '_')
            {
                guess[i] = letter;
                found = true;
            }
        }

        if (found == false)
        {
            wrong++;
            cout << "Wrong guess!\n";
        }
        else
        {
            cout << "Correct guess!\n";
        }
        system("pause");

        cout << "\n--------------------\n";
    }

    Hangman(wrong);

    if (guess == word)
        cout << "\n let's goo " << guesser << " WON! Word was: " << word << endl;
    else
        cout << "\n damnn " << guesser << " LOST! Word was: " << word << endl;
}

int main()
{

    string player1;
    string player2;

    cout << "Enter Player 1 name: ";
    cin >> player1;

    cout << "Enter Player 2 name: ";
    cin >> player2;

    cout << "\n--- ROUND 1 ---\n";
    playGame(player1, player2);

    cout << "\n--- ROUND 2 ---\n";
    playGame(player2, player1);

    cout << "\n***Game Over ***\n";
    return 0;
}
