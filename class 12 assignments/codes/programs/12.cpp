#include <iostream>
using namespace std;

int main() {
    int r, c, a[10][10], b[10][10], sum[10][10];
    cout << "Enter rows and columns: ";
    cin >> r >> c;

    cout << "Enter Matrix A elements:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];

    cout << "Enter Matrix B elements:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> b[i][j];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            sum[i][j] = a[i][j] + b[i][j];

    cout << "\nResultant Sum Matrix:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}