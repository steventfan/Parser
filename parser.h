#ifndef PARSER_H
#define PARSER_H

class Parser
{
    public:
        Parser();
        Parser(char, char = '\0', bool = false);
        Parser(char, char *, bool = false);
        Parser(char *, char = '\0', bool = false);
        Parser(char *, char *, bool = false);
        ~Parser();
        char * at(unsigned int);
        int count();
    private:
        void parsing(char *, char *, bool);
        unsigned int size;
        char ** token;
};

#endif