#ifndef DECYPHER_MAIN_H
#define DECYPHER_MAIN_H

#include "ceasars_decypher.h"

#include <iostream>

// 
void decypher_main() {
// 8 bit unsigned integer
    int user_input;

    std::string decyphered_message;

// menu options
    std::cout << "\nWhat decyphering method would you like to use?\n";
    std::cout << "0. Go Back\n";
    std::cout << "1. Ceasars Decypher\n";

// user input
    std::cin >> user_input;

// menu select
    switch (user_input) {
        case 0:
            return;
            break;    
        case 1:
            ceasars_decypher();
            break;
        default:
            break;
    }
}

#endif