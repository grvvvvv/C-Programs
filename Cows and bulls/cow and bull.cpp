#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

int main()
{
    srand(time(0));

    int winning_number = rand() % 9000 + 1000;
    int attempts = 0;

    cout << "Welcome to the Cow and Bull number guessing game!\n"
         << endl;

    while (true)
    {
        int guess;
        cout << "Guess the number: ";
        cin >> guess;

        if (guess < 1000 || guess > 9999)
        {
            cout << "Enter a valid 4-digit number.\n";
            continue;
        }

        attempts++;

        int winning_digits[4], guessDigits[4];
        int tempWin = winning_number, tempGuess = guess;

        for (int i = 0; i < 4; i++)
        {
            winning_digits[i] = tempWin % 10;
            guessDigits[i] = tempGuess % 10;
            tempWin /= 10;
            tempGuess /= 10;
        }

        int bulls = 0, cows = 0;
        bool usedWin[4] = {false}, usedGuess[4] = {false};

        for (int i = 0; i < 4; i++)
        {
            if (winning_digits[i] == guessDigits[i])
            {
                bulls++;
                usedWin[i] = true;
                usedGuess[i] = true;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            if (usedWin[i])
                continue;

            for (int j = 0; j < 4; j++)
            {
                if (usedGuess[j])
                    continue;

                if (winning_digits[i] == guessDigits[j])
                {
                    cows++;
                    usedWin[i] = true;
                    usedGuess[j] = true;
                    break;
                }
            }
        }

        cout << "Cows: " << cows << ", Bulls: " << bulls << endl;

        if (bulls == 4)
        {
            cout << "\nCongratulations! You guessed the number in "
                 << attempts << " attempts.\n";

            char playAgain;
            cout << "Play again? (y/n): ";
            cin >> playAgain;

            if (playAgain == 'y' || playAgain == 'Y')
            {
                winning_number = rand() % 9000 + 1000;
                attempts = 0;
                cout << "\nNew game started!\n";
            }
            else
                break;
        }

        sleep(1);
    }

    return 0;
}
