#include "Stacks.h"
#include <string>

class Evaluator {
    private:
        Stack<float> numbers;
        Stack<char> operations;
        // Stores the current character being looked
        // at from the expression
        char currentChar;
    public:
        // Default constructor
        Evaluator();
        // Checks if a char is a digit
        bool isDigit();
        // Checks if currentChar is an operation
        bool isOp();
        // Checks if currentChar is a left parenthesis
        bool isLeftParen();
        // Checks if currentChar is a right parenthesis
        bool isRightParen();
        // Checks if currentChar is a decimal
        bool isDecimal();
        // Evaluates a string expression
        float evaluate(string expression);
};