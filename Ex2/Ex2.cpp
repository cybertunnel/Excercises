#include <iostream>
#include <cstring>
#include <typeinfo>
#include <cmath>

// The options for the menu
enum MenuOption {
    Addition,
    Subtraction,
    Multiplication,
    Division,
    Exponential,
    SquareRoot,
    Exit
};

// Displays the options available in the menu. Dependant on MenuOptions enum
void displayMenu() {
    std::cout << "=================================" << std::endl;
    std::cout << "1.\tAddition" << std::endl;
    std::cout << "2.\tSubtraction" << std::endl;
    std::cout << "3.\tMultiplication" << std::endl;
    std::cout << "4.\tDivision" << std::endl;
    std::cout << "5.\tExponential" << std::endl;
    std::cout << "6.\tSquare Root" << std::endl;
    std::cout << "7.\tExit" << std::endl;
    std::cout << "---------------------------------" << std::endl;

    return;
}

void clearInputBuffer() {
    std::cout << "Invalid input. Please enter a valid selection." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main () {

    while (true) {
        
        displayMenu();
        int selection = 0;
        std::cout << "Enter your menu selection: ";
        if (std::cin >> selection) {
            MenuOption selectedOption = static_cast<MenuOption>(selection-1);

            // Check if the user wants to exit before prompting for numeric inputs
            if (selectedOption == Exit) {
                std::cout << "Goodbye!" << std::endl;
                exit(0);
            }

            int num1, num2;

            std::cout << "Please enter your first number: ";
            if (std::cin >> num1) {

                if (selectedOption == SquareRoot) {
                    std::cout << "Result: Sqrt(" << num1 << ") = " << sqrt(num1) << std::endl;
                } else {

                    std::cout << "Please enter your second number: ";
                    
                    if (std::cin >> num2) {
                        switch(selectedOption) {
                            case Addition:
                                std::cout << "Result: " << num1 << " + " << num2 << " = " << num1 + num2 << std::endl;
                                break;
                            case Subtraction:
                                std::cout << "Result: " << num1 << " - " << num2 << " = " << num1 - num2 << std::endl;
                                break;
                            case Multiplication:
                                std::cout << "Result: " << num1 << " * " << num2 << " = " << num1 * num2 << std::endl;
                                break;
                            case Division:
                                if (num2 == 0) {
                                    std::cout << "Error: Cannot divide by 0" << std::endl;
                                } else {
                                    std::cout << "Result: " << num1 << " / " << num2 << " = " << num1 / num2 << std::endl;
                                }
                                break;
                            case Exponential:

                                std::cout << "Result: " << num1 << "^" << num2 << " = " << pow(num1,num2) << std::endl;
                                break;
                            case Exit:
                                std::cout << "Goodbye!";
                                exit(0);
                            default:
                                clearInputBuffer();
                                break;
                        }
                    } else {
                        clearInputBuffer();
                    }
                }
            } else {
                clearInputBuffer();
            }
        } else {
            clearInputBuffer();
        }
    }
}