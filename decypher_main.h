#ifndef DECYPHER_MAIN_H
#define DECYPHER_MAIN_H

#include "ceasars_decypher.h"

#include <iostream>

// 
int decypher_main() {
// 8 bit unsigned integer
    int user_input;

// menu options
    std::cout << "\nWhat decyphering method would you like to use?\n";
    std::cout << "0. Exit\n";
    std::cout << "1. Ceasars Decypher\n";

// user input
    std::cin >> user_input;

// menu select
    switch (user_input) {
        case 0:
            return 0;
            break;    
        case 1:
            ceasars_decypher();
            break;
        default:
            break;
    }
    return 0;
}


#endif