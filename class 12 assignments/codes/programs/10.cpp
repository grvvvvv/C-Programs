#include <iostream>
using namespace std;

int main() {
    int n, pos, arr[100];
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter position (1-based) to delete: ";
    cin >> pos;

    if (pos < 1 || pos > n) {
        cout << "Invalid position!\n";
    } else {
        for (int i = pos - 1; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;

        cout << "Updated Array: ";
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }

    return 0;
}