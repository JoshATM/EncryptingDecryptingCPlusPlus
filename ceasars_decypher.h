#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <vector>
#include <algorithm>




// decyphers user text using ceasars decypherer
std::string decypher_file_input() {
    std::string message;
    
    // file name
    const char* user_file_name = "C:/Users/josh8/Documents/Coding/C++/Encypher_Decypher/the_files/PUT_IN_THIS_FILE.txt";

    // ifstream - reads from file (ofstream creates and writes to files)
    // inFile - 
    std::ifstream in_user_file(user_file_name);
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

std::string decypher_terminal_input() {
    std::string message;
    
    std::cout << "What is the text you want to decypher?\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // removes the starting newling (\n) buffer at the start
    std::getline(std::cin, message, '\n');
    
    return message;
}


void decypher_automatically(std::string message) {
    const char* dict_file_name = "C:/Users/josh8/Documents/Coding/C++/EncryptingDecryptingCPlusPlus/the_files/english.txt"; // josh8 on laptop JoshPC on desktop
    std::ifstream in_dict_file(dict_file_name);
    std::string line;
    
    std::string decyphered_message;
    std::vector<std::string> decyphered_messages;

    int leftover;
    
    std::cout << '\n';
    for (int number_of_letters = 0; number_of_letters < 26; number_of_letters++)
    {
        for (int i = 0; i < message.size(); i++)
        {
            std::cout << message[i] << '\n';
            if (!isalpha(message[i])) // if there is a character that is not in th alphabet, don't shift it - can also do (character == ' ') but that only detects for spaces whereas isalpha() detects for a letter in the alphabet
            {
                for (int j = 0; j < message.size(); j++)
                {
                    decyphered_message.push_back(message[i]);
                }
                decyphered_messages.push_back(decyphered_message);
                decyphered_message = "";
                
            } else {
                
                if (std::islower(message[i]))
                {
                    if (message[i] + number_of_letters < 'a') {
                        leftover = (-('a' - (message[i] + number_of_letters)) + 1);
                        message[i] = 'z' + leftover;
                    } else if (message[i] + number_of_letters > 'z')
                    {
                        leftover = (-('z' - (message[i] + number_of_letters)) - 1);
                        message[i] = 'a' + leftover;
                    } else {
                        message[i] = message[i] + number_of_letters;
                    }
                    
                } else if (std::isupper(message[i])) {
                    // if message[i] + number_of_letters > or < , then loop back to a or z and add or take away the difference 
                    if (message[i] + number_of_letters < 'A') {
                        leftover = (-('A' - (message[i] + number_of_letters)) + 1);
                        message[i] = 'Z' + leftover;
                    } else if (message[i] + number_of_letters > 'Z')
                    {
                        leftover = (-('Z' - (message[i] + number_of_letters)) - 1);
                        message[i] = 'A' + leftover;
                    }
                    
                    else {
                        message[i] = message[i] + number_of_letters;
                    }
                }
            }
        }
    }
    
    std::cout << decyphered_messages.size();

    std::vector<int> scores(decyphered_messages.size()); // initialises scores as the size of decyphered messages (26)
    // compares each message to a enlish word
    if (in_dict_file.is_open())
    {
        // .getline - 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // removes the starting newling (\n) buffer at the start
        while (std::getline(in_dict_file, line))
        {
            for (int j = 0; j < decyphered_messages.size(); j++)
            {
                if (line == decyphered_messages[j])
                {
                    // give score based on matching words divided by total amount of words (times by 100 to make it as a percent)
                    scores[j]++;
                }
                std::cout << "Message: " << decyphered_messages[j] << " | Score: " << scores[j] << '\n';
            }
        }
    }
    else
    {
        std::cout << "ERROR: File did NOT Open!" << "\n";
    }
        
    in_dict_file.close();

    // returns the highest scoring result
    // return decyphered_messages[std::max_element(scores.begin(), scores.end()) - scores.begin()];
}


void decypher(std::string message, int shift_amount) {
    std::string decyphered_message;
    int leftover;

    for (int i = 0; i < message.size(); i++)
    {
        if (!isalpha(message[i])) // if there is a character that is not in th alphabet, don't shift it - can also do (character == ' ') but that only detects for spaces whereas isalpha() detects for a letter in the alphabet
        {
            decyphered_message += message[i];
        } else {
            if (std::islower(message[i]))
            {
                if (message[i] + shift_amount < 'a') {
                    leftover = (-('a' - (message[i] + shift_amount)) + 1);
                    decyphered_message += 'z' + leftover;
                } else if (message[i] + shift_amount > 'z')
                {
                    leftover = (-('z' - (message[i] + shift_amount)) - 1);
                    decyphered_message += 'a' + leftover;
                } else {
                    decyphered_message += message[i] + shift_amount;
                }

            } else if (std::isupper(message[i])) {
                // if message[i] + shift_amount >  or < , then loop back to a or z and add or take away the difference 
                if (message[i] + shift_amount < 'A') {
                    leftover = (-('A' - (message[i] + shift_amount)) + 1);
                    decyphered_message += 'Z' + leftover;
                } else if (message[i] + shift_amount > 'Z')
                {
                    leftover = (-('Z' - (message[i] + shift_amount)) - 1);
                    decyphered_message += 'A' + leftover;
                }
                
                else {
                    decyphered_message += message[i] + shift_amount;
                }
            }
        }
    }
}



void decypher_menu(std::string message) {

    std::string decyphered_message;

    int user_input;
    int random_number;
    int shift_amount;
    
    std::cout << "\nWould you like to decypher the message automatically or by a set amount?\n";
    std::cout << "0. Go Back\n";
    std::cout << "1. Automatically\n";
    std::cout << "2. Set Amount\n";
    
    // user input
    std::cin >> user_input;
    
    // menu select
    switch (user_input) {
        case 0:
            decypher_menu(message);
            break;    
        case 1:
            // automatically
            decypher_automatically(message);
            break;
        case 2:
            // set amount
            std::cout << "\nHow many shifts was originally entered to encypher the message? Enter a number from -26 to +26\n";
            std::cin >> shift_amount;
            decypher(message, -shift_amount);
            break;
        default:
            std::cout << "\nPlease enter one of the following options:   0   1   2\n";
        break;
    }
}





// cyphers user text using ceasars cypher
void ceasars_decypher() {
    int user_input;
    std::string message;
    std::string decyphered_message;
    
    std::cout << "\nCeasars Decypher:\n";

    // menu options
    std::cout << "\nWould you like to enter the message in the terminal or from the file?\n";
    std::cout << "0. Go Back\n";
    std::cout << "1. Terminal\n";
    std::cout << "2. File\n";
        
    // user input
    std::cin >> user_input;
        
    // menu select
    switch (user_input) {
        case 0:
            ceasars_decypher();
            break;    
        case 1:
            message = decypher_terminal_input();
            break;
        case 2:
            message = decypher_file_input();
            break;
        default:
            std::cout << "\nPlease enter one of the following options:   0   1   2\n";
            break;
    }
    decypher_menu(message);
}