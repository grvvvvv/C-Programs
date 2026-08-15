#include <iostream>
#include <random>
#include <string>
#include <cctype>

using namespace std;

int countCows(const string &userInput, const string &secretKey)
{
    int cows = 0;
    for (int i = 0; i < 4; i++)
    {
        if (userInput[i] == secretKey[i])
        {
            cows++;
        }
    }
    return cows;
}

int countBulls(const string &userInput, const string &secretKey)
{
    int bulls = 0;
    bool used[4] = {false};

    for (int i = 0; i < 4; i++)
    {
        if (userInput[i] == secretKey[i])
        {
            used[i] = true;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (userInput[i] != secretKey[i])
        {
            for (int j = 0; j < 4; j++)
            {
                if (!used[j] && userInput[i] == secretKey[j])
                {
                    bulls++;
                    used[j] = true;
                    break;
                }
            }
        }
    }

    return bulls;
}

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1000, 9999);

    string userInput;
    char again;

    cout << "------ Welcome to Cow & Bull Game ------\n\n";
    cout << "RULES:\n";
    cout << "1. Enter a 4-digit number\n";
    cout << "2. COW  = correct digit & correct position\n";
    cout << "3. BULL = correct digit & wrong position\n";
    cout << "----------------------------------------\n\n";

    do
    {
        int secretNumber = dis(gen);
        string secretKey = to_string(secretNumber);

        while (true)
        {
            cout << "Enter your guess: ";
            cin >> userInput;

            bool validInput = true;

            if (userInput.length() != 4)
                validInput = false;

            for (char c : userInput)
            {
                if (!isdigit(c))
                {
                    validInput = false;
                    break;
                }
            }

            if (!validInput)
            {
                cout << "Invalid input! Enter a 4-digit number.\n\n";
                continue;
            }

            int cows = countCows(userInput, secretKey);
            int bulls = countBulls(userInput, secretKey);

            cout << "Cows: " << cows << " , Bulls: " << bulls << endl;

            if (cows == 4)
            {
                cout << "\nCOW WINS! Exact match!\n";
                cout << "Secret number was: " << secretKey << endl;
                break;
            }
            else if (bulls == 4)
            {
                cout << "\nBULL WINS! All digits correct but positions wrong!\n";
                cout << "Secret number was: " << secretKey << endl;
                break;
            }
        }

        cout << "\nPlay again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    cout << "\nGame Over! Thanks for playing\n";
    return 0;
}
