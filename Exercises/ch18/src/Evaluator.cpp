#include "Evaluator.h"

Evaluator::Evaluator() {
    currentChar = '\0';
}

bool Evaluator::isDecimal() {
    return (currentChar == '.');
}
bool Evaluator::isDigit() {
    return (currentChar > 47 && currentChar < 58);
}
bool Evaluator::isLeftParen() {
    return (currentChar == '(');
}
bool Evaluator::isRightParen() {
    return (currentChar == ')');
}
bool Evaluator::isOp() {
    return (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/' || currentChar == '^');
}

float Evaluator::evaluate(string expression) {
    int i;
    for (i = 0; i < expression.length(); i++) {
        currentChar = expression[i];
        if (isOp()) {
            cout << "operator" << endl;
        }
        if (isDecimal()) {
            cout << "decimal" << endl;
        }
        if (isDigit()) {
            cout << "digit" << endl;
        }
        if (isLeftParen()) {
            cout << "Left parenthesis" << endl;
        }
        if (isRightParen()) {
            cout << "Right parenthesis" << endl;
        }
    }
}
