#include <iostream>
#include <fstream>
#include <string>
#include "parser.h"

int main()
{
    char option = '\0';
    bool inclusive;

    while(option != 'y' && option != 'Y' && option != 'n' && option != 'N')
    {
        std::cout << "Include parsing symbols in parsed string? (y/n)" << std::endl;
        std::cin >> option;
        if(option == 'y' || option == 'Y')
        {
            inclusive = true;
        }
        else if(option == 'n' || option == 'N')
        {
            inclusive = false;
        }
        else
        {
            std::cout << "Invalid Input" << std::endl;
        }
    }

    std::ifstream file;

    file.open("inputs/string.txt");
    if(!file)
    {
        std::cout << "Failed to open file string.txt" << std::endl;

        return 1;
    }

    std::string input = "";

    for(std::string reading; getline(file, reading); )
    {
        if(input.size() > 0)
        {
            input += '\n';
        } else if(reading == "")
        {
            input = "\n";
        }
        input += reading;
    }
    file.close();

    file.open("inputs/symbols.txt");
    if(!file)
    {
        std::cout << "Failed to open file symbols.txt" << std::endl;

        return 1;
    }

    std::string symbol = "";

    for(std::string reading; getline(file, reading); )
    {
        if(symbol.size() > 0)
        {
            symbol += '\n';
        } else if(reading == "")
        {
            symbol = "\n";
        }
        symbol += reading;
    }
    file.close();

    char * inputArray = new char [input.size() + 1];
    char * symbolArray = new char [symbol.size() + 1];
    unsigned int index = 0;

    for(index = 0; index < input.size(); index++)
    {
        *(inputArray + index) = input.at(index);
    }
    *(inputArray + index) = '\0';
    for(index = 0; index < symbol.size(); index++)
    {
        *(symbolArray + index) = symbol.at(index);
    }
    *(symbolArray + index) = '\0';
    std::cout << "~~~ Input String: ~~~" << std::endl;
    for(index = 0; index < input.size() + 1; index++)
    {
        std::cout << *(inputArray + index);
    }
    std::cout << std::endl << "~~~ Parsed Symbols: ~~~" << std::endl;
    for(index = 0; index < symbol.size() + 1; index++)
    {
        std::cout << *(symbolArray + index);
    }
    std::cout << std::endl << "~~~ Parsed Sentece: ~~~" << std::endl;

    Parser * parsed = new Parser(inputArray, symbolArray, inclusive);

    for(index = 0; index < parsed->count(); index++)
    {
        std::string sentence = "";
        char * pointer = parsed->at(index);
        unsigned int line = 0;

        while(*(pointer + line) != '\0')
        {
            sentence += *(pointer + line);
            line++;
        }
        if(sentence.size() > 0)
        {
            std::cout << sentence << std::endl;
        }
    }

    delete parsed;

    return 0;
}