//
// Take input from the terminal
//

#include <iostream>

int main() {
    std::cout << "Your name: ";

    std::string name;
    std::cin >> name;

    std::cout << "Hello " + name + "!" << std::endl;
    return 0;
}
