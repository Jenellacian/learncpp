#include <iostream>
#include <stdexcept>

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero is not allowed");
    }
    return a / b;
}

int main() {
    char operation;
    double operand1, operand2, result;

    std::cout << "Enter an arithmetic operation (+, -, *, /): ";
    std::cin >> operation;

    std::cout << "Enter two operands: ";
    std::cin >> operand1 >> operand2;

    try {
        switch (operation) {
            case '+':
                result = add(operand1, operand2);
                break;
            case '-':
                result = subtract(operand1, operand2);
                break;
            case '*':
                result = multiply(operand1, operand2);
                break;
            case '/':
                result = divide(operand1, operand2);
                break;
            default:
                throw std::invalid_argument("Invalid operation");
        }

        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
