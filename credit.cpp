#include <iostream>
#include <string>

using namespace std;

bool validateCreditCard(string cardNumber) {
    int sum = 0;
    bool alternate = false;
    for (int i = cardNumber.length() - 1; i >= 0; i--) {
        int digit = cardNumber[i] - '0';
        if (alternate) {
            digit *= 2;
            if (digit > 9) {
                digit = (digit % 10) + 1;
            }
        }
        sum += digit;
        alternate = !alternate;
    }
    return (sum % 10 == 0);
}

int main() {
    string cardNumber;
    cout << "Enter a credit card number: ";
    cin >> cardNumber;
    if (validateCreditCard(cardNumber)) {
        cout << "The credit card number is valid." << endl;
    } else {
        cout << "The credit card number is invalid." << endl;
    }
    return 0;
}
