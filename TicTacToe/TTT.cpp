#include <iostream>
#include <unistd.h>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void drawBoard(){

    system("cls");

    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool checkWin(char player)
{

    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;

        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

void resetBoard()
{
    char resetBoard[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = resetBoard[i][j];
        }
    }
}

bool isBoardFull()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    string player1, player2;
    char player = 'X';
    int choice;
    char playAgain;

    cout << "Enter Player 1 name (X): ";
    getline(cin, player1);

    cout << "Enter Player 2 name (O): ";
    getline(cin, player2);

    do
    {

        resetBoard();

        bool gameWon = false;

        while (true)
        {
            drawBoard();

            if (player == 'X')
            {
                cout << player1 << "'s turn (X), enter your choice (1-9): ";
            }
            else
            {
                cout << player2 << "'s turn (O), enter your choice (1-9): ";
            }
            cin >> choice;

            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;

            if (board[row][col] != 'X' && board[row][col] != 'O')
            {
                board[row][col] = player;

                if (checkWin(player))
                {
                    drawBoard();
                    if (player == 'X')
                    {
                        cout << player1 << " winss!" << endl;
                    }
                    else
                    {
                        cout << player2 << " winss!" << endl;
                    }
                    gameWon = true;
                    break;
                }

                player = (player == 'X') ? 'O' : 'X';
            }
            else
            {

                cout << "Invalid choice. Try again." << endl;
                sleep(2);
            }

            if (isBoardFull() && !gameWon)
            {
                drawBoard();
                cout << "It's a draw!" << endl;
                break;
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "***Thanks for playing!***" << endl;
    return 0;
}
