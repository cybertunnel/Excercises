#include <iostream>
#include <cstring>
#include <typeinfo>

int main () {

    char menuOptions[][44] = {"Addition", "Subtraction", "Multiplication", "Division", "Exit"};
    int menuSize = sizeof(menuOptions)/sizeof(menuOptions[0]);
    while (true) {

        // Reset selection
        int selection = 0;

        // Present menu
        std::cout << "Please select an option from the menu:" << std::endl;
        for (int i = 0; i < menuSize; i++) {
            std::cout << i + 1<< ".\t" << menuOptions[i] << std::endl;
        }

        // Get user's selection
        std::cout << "Enter your choice:";
        if (std::cin >> selection) {
            if (selection > 5) {
                std::cout << "Invalid selection" << std::endl;
            } else if (selection == 5) {
                std::cout << "Goodbye!" << std::endl;
                exit(0);
            } else {
                int num1, num2;
                std::cout << "Enter number 1:";
                std::cin >> num1;

                std::cout << "Enter number 2:";
                std::cin >> num2;

                double result;
                switch (selection) {
                    case 1:
                        std::cout << "Result : " << num1 << " + " << num2 << " = " << num1 + num2 << std::endl;
                        break;
                    case 2:
                        std::cout << "Result : " << num1 << " - " << num2 << " = " << num1 - num2 << std::endl;
                        break;
                    case 3:
                        std::cout << "Result : " << num1 << " * " << num2 << " = " << num1 * num2 << std::endl;
                        break;
                    case 4:
                        std::cout << "Result : " << num1 << " / " << num2 << " = " << num1 / num2 << std::endl;
                        break;
                    default:
                        std::cout << "ERROR: Invalid selection";
                        break;
                }
            }

        } else {
            std::cout << "Invalid input. Please enter a valid selection." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    std::cout << std::endl;
}