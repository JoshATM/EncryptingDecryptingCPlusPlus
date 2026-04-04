#ifndef CYPHER_MAIN_H
#define CYPHER_MAIN_H

#include "ceasars_cypher.h"

#include <iostream>

// 
void cypher_main() {
// 8 bit unsigned integer
    int user_input;

    std::string encyphered_message;
    
// menu options
    std::cout << "\nWhat encyphering method would you like to use?\n";
    std::cout << "0. Go Back\n";
    std::cout << "1. Ceasars Cypher\n";

// user input
    std::cin >> user_input;

// menu select
    switch (user_input) {
        case 0:
            return;
            break;    
        case 1:
            ceasars_cypher();
            break;
        default:
            break;
    }
}

#endif