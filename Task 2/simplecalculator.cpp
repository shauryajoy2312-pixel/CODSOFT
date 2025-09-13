#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char op;

    // Taking first number
    cout << " enter the first number: ";
    cin >> num1;

    // Taking operator
    cout << " choose an operation (+, -, *, /): ";
    cin >> op;

    // Taking second number
    cout << " enter the second number: ";
    cin >> num2;

    // Performing operation
    switch(op) {
        case '+':
            cout << "Result: " << num1 << " + " << num2 << " = " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 << " - " << num2 << " = " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Result: " << num1 << " / " << num2 << " = " << num1 / num2 << endl;
            } else {
                cout <<  "Oops! Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << " Sorry, that's not a valid operation. " << endl;
    }

    cout << "\n Thanks for using this calculator. \n";
    return 0;
}
