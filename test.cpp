#include <iostream>
#include <string>
#include "parser.h"

int main()
{
    std::string input = "Hello World !";
    std::string symbol = " ";
    bool inclusive = false;
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
    std::cout << std::endl << std::endl << "~~~ Parsed Sentece: ~~~" << std::endl;

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