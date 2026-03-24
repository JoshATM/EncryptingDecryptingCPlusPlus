#ifndef CEASARS_DECYPHER_H
#define CEASARS_DECYPHER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// cyphers user text using ceasars cypher
void ceasars_cypher() {
    std::cout << "\nCeasars Decypher:\n";
    
    /* gets the text from a file */
    // file name
    const char* user_file_name = "C:/Users/JoshPC/Documents/Coding/C++/Encypher_Decypher/the_files/PUT_IN_THIS_FILE.txt";
    const char* dict_file_name = "C:/Users/JoshPC/Documents/Coding/C++/Encypher_Decypher/the_files/ukenglish.txt";
    
    // ifstream - reads from file (ofstream creates and writes to files)
    // inFile - 
    std::ifstream in_user_file(user_file_name);
    std::ifstream in_dict_file(dict_file_name);
    
    std::string current_line = "";
    // ' ' - 
    char character = ' ';
    std::string word_maker = "";
    std::string dict_word_maker = "";
    // vector -  
    std::vector<std::string> word = {};
    std::vector<std::string> dict_word = {};
    
    // ukenglish file
    if (in_dict_file.is_open())
    {
        // .get - 
        while (in_dict_file.get(character))
        {
            
            if (character == '\n') {
                dict_word.push_back(dict_word_maker);
                dict_word_maker = "";
            } else {
                dict_word_maker += tolower(character);
            }
        }
        dict_word.push_back(dict_word_maker);
        dict_word_maker = "";
    }
    else
    {
        std::cout << "File did NOT Open!" << "\n";
    }

    std::cout << "Dictionary Done! with the Size of " << dict_word.size() << "\n";
    
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

    std::cout << "PITF Done! with the Size of " << word.size() << "\n";


    // word to character
    // for (int i = 0; i < word.size(); i++)
    // {
    //     word[i].
    // }


    std::cout << '\n';
    for (int number_of_letters = 26; number_of_letters > 0; number_of_letters--)
    {
        for (int j = 0; j < dict_word.size(); j++)
        {
            for (int i = 0; i < word.size(); i++)
            {
                if (word[i] == dict_word[j]) {
                    std::cout << "MATCH" << '\n';
                }
            }
        }
        std::cout << '\n';

    }
    
    
    // std::cout << '\n' << "DEBUG" << '\n';
    // std::cout << "Word Size:" << word.size() << '\n';
    // std::cout << "Word front:" << word.front() << '\n';
    // std::cout << "Word back:" << word.back() << '\n';
    
    // std::cout << "Word_Maker:" << '\n';
    // for (int i = 0; i < word.size(); i++)
    // {
    //     std::cout << word[i] << '\n';
    // }
    
    
    // shifts the character over by a specified amount
    
    
    // shifts the character over by a random amount
    
    in_user_file.close(); // closes file
    in_dict_file.close(); // closes file
}

#endif