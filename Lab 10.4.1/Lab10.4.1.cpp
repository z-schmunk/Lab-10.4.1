#include <iostream>
using namespace std;

bool isCardValid(int digits[], int size) {
    int sum1 = 0, sum2 = 0;

    for (int i = size - 1; i >= 0; i -= 2) {
        sum1 += digits[i];
    }

    for (int i = size - 2; i >= 0; i -= 2) {
        int doubled = digits[i] * 2;
        sum2 += (doubled / 10) + (doubled % 10);
    }

    return (sum1 + sum2) % 10 == 0;
}

int main() {
    int digits[8];
    char input[10];

    while (true) {
        cout << "Enter an 8-digit credit card # or Q to quit: ";
        cin >> input;

        if (input[0] == 'Q' || input[0] == 'q') {
            break;
        }

        if (strlen(input) != 8) {
            cout << "Error - Card number must contain exxactly 8 digits." << endl;
            continue;
        }

        for (int i = 0; i < 8; i++) {
            if (!isdigit(input[i])) {
                cout << "Invalid input." << endl;
                break;
            }
            digits[i] = input[i] - '0';
        }

        if (isCardValid(digits, 8)) {
            cout << "Card is valid." << endl;
        }
        else {
            cout << "Card is not valid." << endl;
        }
    }

    return 0;
}