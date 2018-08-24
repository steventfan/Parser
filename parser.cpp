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

Parser::Parser()
{
    size, token = 0;
}

Parser::Parser(char string, char symbol, bool inclusive)
{
    size, token = 0;

    char stringTemplate[2] = {string, '\0'};
    char symbolTemplate[2] = {symbol, '\0'};

    parsing(stringTemplate, symbolTemplate, inclusive);
}

Parser::Parser(char string, char * symbol, bool inclusive)
{
    size, token = 0;

    char stringTemplate[2] = {string, '\0'};

    parsing(stringTemplate, symbol, inclusive);
}

Parser::Parser(char * string, char symbol, bool inclusive)
{
    size, token = 0;

    char symbolTemplate[2] = {symbol, '\0'};

    parsing(string, symbolTemplate, inclusive);
}

Parser::Parser(char * string, char * symbol, bool inclusive)
{
    size, token = 0;

    parsing(string, symbol, inclusive);
}

Parser::~Parser()
{
    for(unsigned int index = 0; index < size; index++)
    {
        delete[] *(token + index);
    }
    if(size > 0)
    {
        delete[] token;
    }
}

char * Parser::at(unsigned int index)
{
    if(index < size)
    {
        return *(token + index);
    }
    
    return 0;
}

int Parser::count()
{
    return size;
}

void Parser::parsing(char * string, char * symbol, bool inclusive)
{
    unsigned int stringAt = 0;

    while(*(string + stringAt) != '\0')
    {
        size++;
        stringAt++;
    }

    char * tokenTemplate[size + 1] = {0};
    char lineTemplate[size + 1] = {'\0'};
    unsigned int tokenTemplateAt, lineTemplateAt, copyAt, lineSize = 0;

    for(stringAt = 0; stringAt < size; stringAt++)
    {
        unsigned int symbolAt = 0;

        while(*(symbol + symbolAt) != '\0')
        {
            if(*(string + stringAt) == *(symbol + symbolAt) )
            {
                if(lineTemplateAt != 0)
                {
                    lineTemplate[lineTemplateAt] = '\0';
                    copyAt, lineSize = 0;
                    while(lineTemplate[copyAt] != '\0')
                    {
                        lineSize++;
                        copyAt++;
                    }

                    tokenTemplate[tokenTemplateAt] = new char [lineSize + 1];

                    for(copyAt = 0; copyAt < lineSize + 1; copyAt++)
                    {
                        *(tokenTemplate[tokenTemplateAt] + copyAt) = lineTemplate[copyAt];
                    }
                    tokenTemplateAt++;
                    lineTemplateAt = 0;
                }
                if(inclusive)
                {
                    tokenTemplate[tokenTemplateAt] = new char [2] {*(string + stringAt), '\0'};

                    tokenTemplateAt++;
                }
                stringAt++;

                break;
            }
            symbolAt++;
        }
        if(stringAt < size)
        {
            lineTemplate[lineTemplateAt] = *(string + stringAt);
            lineTemplateAt++;
        }
    }
    if(lineTemplateAt != 0)
    {
        lineTemplate[lineTemplateAt] = '\0';
        copyAt, lineSize = 0;
        while(lineTemplate[copyAt] != '\0')
        {
            lineSize++;
            copyAt++;
        }

        tokenTemplate[tokenTemplateAt] = new char [lineSize + 1];

        for(copyAt = 0; copyAt < lineSize + 1; copyAt++)
        {
            *(tokenTemplate[tokenTemplateAt] + copyAt) = lineTemplate[copyAt];
        }
    }
    tokenTemplateAt, size = 0;
    while(tokenTemplate[tokenTemplateAt] != 0)
    {
        size++;
    }
    if(size > 0)
    {
        token = new char * [size];

        for(copyAt = 0; copyAt < size; copyAt++)
        {
            *(token + copyAt) = tokenTemplate[copyAt];
        }
    } else
    {
        token = 0;
    }
}