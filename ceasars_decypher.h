#ifndef CEASARS_DECYPHER_H
#define CEASARS_DECYPHER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// cyphers user text using ceasars cypher
void ceasars_decypher() {
    std::cout << "\nCeasars Decypher:\n";
    
    /* gets the text from a file */
    // file name
    const char* user_file_name = "C:/Users/JoshPC/Documents/Coding/C++/Encypher_Decypher/the_files/PUT_IN_THIS_FILE.txt";
    
    // ifstream - reads from file (ofstream creates and writes to files)
    // inFile - 
    std::ifstream in_user_file(user_file_name);
    
    std::string current_line = "";
    // ' ' - 
    char character = ' ';
    std::string word_maker = "";
    // vector -  
    std::vector<std::string> word = {};
    


    // PUT_IN_THIS_FILE file
    if (in_user_file.is_open())
    {
        // .get - 
        while (in_user_file.get(character))
        {
            
            if (character == '\n') {
                word.push_back(word_maker);
                word_maker = "";
            } else {
                word_maker += tolower(character);
            }
        }
        word.push_back(word_maker);
        word_maker = "";
    }
    else
    {
        std::cout << "File did NOT Open!" << "\n";
    }



    std::cout << '\n';
    for (int number_of_letters = 26; number_of_letters > 0; number_of_letters--)
    {
        for (int i = 0; i < word.size(); i++)
        {
        }
    }
    std::cout << '\n';

    
    in_user_file.close(); // closes file
}

#endif