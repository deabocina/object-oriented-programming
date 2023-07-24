#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

// Write a program that takes two operands (integers) and an operator as input and prints the operation along with the result. Ensure to use the following functions :
// A function for inputting a single integer - throws an exception if a non - integer value is entered.
// A function for inputting the operator - throws an exception if the operator is not one of the supported ones(+-*/ )
// A function that calculates the result of the operation - throws an exception in case of issues(e.g., division by zero)

class myException {
public:
    virtual const char* what() const throw() = 0;
};

class NaN : public myException {
public:
    const char* what() const throw() {
        return "not a number";
    }
};

class Operation : public myException {
public:
    const char* what() const throw() {
        return "invalid operation";
    }
};

class Division : public myException {
public:
    const char* what() const throw() {
        return "division by zero";
    }
};

int getNumberInput() {
    int number = 0;
    cout << "Enter a number: ";
    cin >> number;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw NaN();
    }
    return number;
}

char getOperatorInput() {
    char op = 0;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;
    if (op != '*' && op != '/' && op != '+' && op != '-') {
        throw Operation();
    }
    return op;
}

float calculate(int num1, int num2, char op) {
    if (num2 == 0 && op == '/') {
        throw Division();
    }
    else if (op == '+') {
        return num1 + num2;
    }
    else if (op == '-') {
        return num1 - num2;
    }
    else if (op == '*') {
        return num1 * num2;
    }
    else {
        return num1 / static_cast<float>(num2);
    }
}

int main() {
    int num1, num2;
    char op;
    float result;
    vector<string> errors;

    for (;;) {
        try {
            num1 = getNumberInput();
            num2 = getNumberInput();
            op = getOperatorInput();
            result = calculate(num1, num2, op);
            cout << num1 << " " << op << " " << num2 << " = " << result << endl;
        }
        catch (NaN&) {
            time_t now = time(0);
            string dt = ctime(&now);
            dt.pop_back();
            cout << "Not a number" << endl;
            errors.push_back(dt + " Not a number");
        }
        catch (Operation&) {
            time_t now = time(0);
            string dt = ctime(&now);
            dt.pop_back();
            cout << "Invalid operation" << endl;
            errors.push_back(dt + " Invalid operation");
        }
        catch (Division&) {
            time_t now = time(0);
            string dt = ctime(&now);
            dt.pop_back();
            cout << "Division by zero" << endl;
            errors.push_back(dt + " Division by zero");
        }
        cout << endl;
        for (string err : errors) {
            cout << err << endl;
        }
        cout << endl;
    }
    return 0;
}
