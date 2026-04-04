#include <iostream>
#include <fstream>
#include <string>
#include <limits>

std::string encypher_terminal_input() {
    std::string message;

    std::cout << "What is the text you want to encypher?\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // removes the starting newling (\n) buffer at the start
    std::getline(std::cin, message, '\n');

    return message;
}



std::string encypher_file_input() {
    std::string message;
    
    // file name
    const char* user_file_name = "C:/Users/JoshPC/Documents/Coding/C++/Encypher_Decypher/the_files/PUT_IN_THIS_FILE.txt";
    
    // ifstream - reads from file (ofstream creates and writes to files)
    // inFile - 
    std::ifstream in_user_file(user_file_name);
    
    std::string current_line;
    std::string line;

    
// opens and reads PUT_IN_THIS_FILE file
    if (in_user_file.is_open())
    {
        // .get - 
        while (std::getline(in_user_file, line))
        {
            message += line + '\n';
        }
    }
    else
    {
        std::cout << "ERROR: File did NOT Open!" << "\n";
    }

    return message;
}


                /*
                THINGS TO DO:
                    finish random and decypher

                    make sure after whatever happens, it returns to main.cpp
                */

std::string encypher(std::string message, int shift_amount) {
    std::string encyphered_message;
    int leftover;

    for (int i = 0; i < message.size(); i++)
    {   
        char character = message[i]; // loops through th message character by character
        if (!isalpha(character)) // if there is a character that is not in th alphabet, don't shift it - can also do (character == ' ') but that only detects for spaces whereas isalpha() detects for a letter in the alphabet
        {
            encyphered_message += character;
        } else {
            if (std::islower(character))
            {
                // if character + shift_amount > 97 or < 122, then loop back to a or z and add or take away the difference 
                if (character + shift_amount < 'a') {
                    leftover = (-('a' - (character + shift_amount)) + 1);
                    encyphered_message += 'z' + leftover;
                } else if (character + shift_amount > 'z')
                {
                    leftover = (-('z' - (character + shift_amount)) - 1);
                    encyphered_message += 'a' + leftover;
                } else {
                    encyphered_message += character + shift_amount;
                }

            } else if (std::isupper(character)) {
                // if character + shift_amount >  or < , then loop back to a or z and add or take away the difference 
                if (character + shift_amount < 'A') {
                    leftover = (-('A' - (character + shift_amount)) + 1);
                    encyphered_message += 'Z' + leftover;
                } else if (character + shift_amount > 'Z')
                {
                    leftover = (-('Z' - (character + shift_amount)) - 1);
                    encyphered_message += 'A' + leftover;
                } else {
                    encyphered_message += character + shift_amount;
                }
            }
        }
    }

    return encyphered_message;
}
            
std::string encypher_menu(std::string message) {

    std::string encyphered_message;

    int user_input;
    int random_number;
    int shift_amount;
    
    std::cout << "\nWould you like to encypher the message randomly or by a set amount?\n";
    std::cout << "0. Exit\n";
    std::cout << "1. Randomly\n";
    std::cout << "2. Set Amount\n";
    
    // user input
    std::cin >> user_input;
    
    // menu select
    switch (user_input) {
        case 0:
            return 0;
            break;    
        case 1:
            // random
            // Get a different random number each time the program runs
            srand(time(0));
            
            // MAKE IT SO IT DOESN'T GENERATE 0
            shift_amount = std::rand() % 27; // random number between 1-26
            break;
        case 2:
            // set amount
            std::cout << "\nHow many shifts would you like to do? Enter a number from -26 to +26\n";
            std::cin >> shift_amount;
            break;
        default:
            std::cout << "\nPlease enter one of the following options:   0   1   2\n";
        break;
    }
    
    encyphered_message = encypher(message, shift_amount);

    std::cout << encyphered_message;

    return encyphered_message;
}


// cyphers user text using ceasars cypher
std::string ceasars_cypher() {
    int user_input;
    std::string message;
    std::string encyphered_message;
    
    std::cout << "\nCeasars Cypher:\n";

    // menu options
    std::cout << "\nWould you like to enter a message in the terminal or from the file?\n";
    std::cout << "0. Go Back\n";
    std::cout << "1. Terminal\n";
    std::cout << "2. File\n";
        
    // user input
    std::cin >> user_input;
        
    // menu select
    switch (user_input) {
        case 0:
            ceasars_cypher();
            break;    
        case 1:
            message = encypher_terminal_input();
            break;
        case 2:
            message = encypher_file_input();
            break;
        default:
            std::cout << "\nPlease enter one of the following options:   0   1   2\n";
            break;
    }
    encyphered_message = encypher_menu(message);
    return encyphered_message;
}