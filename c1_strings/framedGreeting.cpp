// Take input from terminal, then make an elaborate greeting message

#include <iostream>

int main() {
    std::cout << "Your name: ";
    std::string name;
    std::cin >> name;

    const std::string greeting = "Hello " + name + "!";

    // Build the lines
    const std::string spaces(greeting.size(), ' ');
    const std::string secondLine = "* " + spaces + " *";
    const std::string firstLine(secondLine.size(), '*');

    // Output them all!
    std::cout << std::endl;
    std::cout << firstLine << std::endl;
    std::cout << secondLine << std::endl;
    std::cout << "* " + greeting + " *" << std::endl;
    std::cout << secondLine << std::endl;
    std::cout << firstLine << std::endl;

    return 0;
}
