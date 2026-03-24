#include <iostream>

#include "cypher_main.h"
#include "decypher_main.h"

// & - get the address of the variable (like A0-A15 in comparison to the EPROM)
// * - get the data / value at the address (like D0-D15 in comparison to the EPROM)

int main() {
// 8 bit unsigned integer
    int user_input;

    while (true) {
        // menu options
        std::cout << "\nWould you like to encypher or decypher the message?\n";
        std::cout << "0. Exit\n";
        std::cout << "1. Encypher\n";
        std::cout << "2. Decypher\n";
        
        // user input
        std::cin >> user_input;
        
        // menu select
        switch (user_input) {
            case 0:
                return 0;
                break;    
            case 1:
                cypher_main();
                break;
            case 2:
                decypher_main();
                break;
            default:
                break;
        }
        return 0;
    }
}