#include <iostream>
#include <fstream>
#include <string>

std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

std::string terminal_input() {
    std::string message;

    std::cout << "What is the text you want to encypher?\n";
    std::cin >> message;

    return message;
}



std::string file_input() {
    std::string message = "";
    
    // file name
    const char* user_file_name = "C:/Users/JoshPC/Documents/Coding/C++/Encypher_Decypher/the_files/PUT_IN_THIS_FILE.txt";
    
    // ifstream - reads from file (ofstream creates and writes to files)
    // inFile - 
    std::ifstream in_user_file(user_file_name);
    
    std::string current_line = "";
    std::string line = "";

    
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


int encypher(std::string message) {

    std::string encyphered_message = "";

    int user_input;
    int shift_amount;
    int random_number;

    
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
            random_number = std::rand() % 26;
        break;
        case 2:
        // set amount
            std::cout << "\nHow many shifts would you like to do? Enter a number from -26 to +26\n";
            std::cin >> shift_amount;
            for (int i = 0; i < message.size(); i++)
            {

                /*
                THINGS TO DO:
                    MAKE SURE WHITE SPACE IS HANDLED CORRECTLY - LOOK AT HOW TO USE getline()
                    MAKE SURE THE LETTEERS WRAP AROUND SO Z = A IF PLUS 1, NOT SOMETHING ELSE

                    finish random and decypher
                */
                
                
                char character = message[i]; // loops through th message character by character
                if (!isalpha(character)) // if there is a character that is not in th alphabet, don't shift it - can also do (character == ' ') but that only detects for spaces whereas isalpha() detects for a letter in the alphabet
                {
                    encyphered_message += character;
                } else {   
                    encyphered_message += (character + shift_amount);
                }
            }

            std::cout << encyphered_message;

            break;
        default:
            std::cout << "\nPlease enter one of the following options:   0   1   2\n";
            break;
        }
}


// cyphers user text using ceasars cypher
int ceasars_cypher() {
    int user_input;
    std::string message;
    
    std::cout << "\nCeasars Cypher:\n";

    while (true) {
        // menu options
        std::cout << "\nWould you like to enter a message in the terminal or from the file?\n";
        std::cout << "0. Exit\n";
        std::cout << "1. Terminal\n";
        std::cout << "2. File\n";
        
        // user input
        std::cin >> user_input;
        
        // menu select
        switch (user_input) {
            case 0:
                return 0;
                break;    
            case 1:
                message = terminal_input();
                break;
            case 2:
                message = file_input();
                break;
            default:
                std::cout << "\nPlease enter one of the following options:   0   1   2\n";
                break;
        }
        std::cout << message;
        encypher(message);
        break;
    }
}