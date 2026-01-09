#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main()
{
    char playAgain;
    string playerName;

    cout << "Enter your name: ";
    getline(cin, playerName);

    cout << "\nWELCOME TO OUR GAME, " << playerName << "!\n";
    cout << "\n1. Guess the number between 1 and 100";

    do
    {
        srand(time(0));
        int secretNumber = rand() % 100 + 1;
        int guesses[100];
        int guess;
        int attempts = 0;

        cout << "\n\nLet's play!\n";
        cout << "I have selected a number between 1 and 100.\n";

        do
        {
            cout << "Enter your guess: ";
            cin >> guess;

            guesses[attempts] = guess;
            attempts++;

            if (guess > secretNumber)
            {
                cout << "Too high! Try again.\n";
            }
            else if (guess < secretNumber)
            {
                cout << "Too low! Try again.\n";
            }
            else
            {
                cout << "\nCongratulations, " << playerName
                     << "! You guessed the number in "
                     << attempts << " attempts!\n";

                cout << "Your guesses are: ";
                for (int i = 0; i < attempts; i++)
                {
                    cout << guesses[i] << " ";
                }
                cout << endl;
            }

        } while (guess != secretNumber);

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;
        cin.ignore();

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\nThanks for playing, " << playerName << "!" << endl;

    return 0;
}
