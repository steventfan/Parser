#include <iostream>
#include <string>
#include "parser.h"

int main()
{
    std::string input = "Hello World !";
    std::string symbol = " ";
    char inputArray[input.size() + 1];
    char symbolArray[symbol.size() + 1];
    unsigned int index = 0;

    for(index = 0; index < input.size(); index++)
    {
        inputArray[index] = input.at(index);
    }
    inputArray[index] = '\0';
    for(index = 0; index < symbol.size(); index++)
    {
        symbolArray[index] = symbol.at(index);
    }
    symbolArray[index] = '\0';
    std::cout << "Input String:" << std::endl;
    for(unsigned int i = 0; i < input.size() + 1; i++)
    {
        std::cout << inputArray[i];
    }
    std::cout << std::endl << "Parsed Symbols:" << std::endl;
    for(unsigned int i = 0; i < symbol.size() + 1; i++)
    {
        std::cout << symbolArray[i];
    }
    std::cout << std::endl;

    Parser * parsed = new Parser(inputArray, symbolArray, 0);

    for(index = 0; index < parsed->count(); index++)
    {
        std::string sentence = "";
        char * pointer = parsed->at(index);
        unsigned int line = 0;

        while(*(pointer + line) != '\0')
        {
            sentence += *(pointer + line);
        }
        if(sentence.size() > 0)
        {
            std::cout << sentence << std::endl;
        }
    }

    return 0;
}