#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cout << "Enter N (>= 2): ";
    cin >> n;

    int maxLen = 0, maxStart = 0;
    int curLen = 0, curStart = 0;

    for (int i = 2; i <= n; i++) {
        if (!isPrime(i)) {
            if (curLen == 0) curStart = i;
            curLen++;
            if (curLen > maxLen) {
                maxLen = curLen;
                maxStart = curStart;
            }
        } else {
            curLen = 0;
        }
    }

    if (maxLen > 0) {
        cout << "Longest consecutive sequence of non-primes (Length " << maxLen << "): ";
        for (int i = maxStart; i < maxStart + maxLen; i++) {
            cout << i << " ";
        }
        cout << endl;
    } else {
        cout << "No composite sequence found between 2 and " << n << ".\n";
    }

    return 0;
}