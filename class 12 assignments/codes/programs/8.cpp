#include <iostream>
using namespace std;

int main() {
    int n, key, arr[100];
    cout << "Enter size of sorted array: ";
    cin >> n;

    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    int low = 0, high = n - 1, mid, index = -1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            index = mid;
            break;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found.\n";

    return 0;
}