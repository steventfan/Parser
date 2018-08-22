class Parser
{
    public:
        Parser(char [], char [], bool);
        ~Parser();
    private:
        unsigned int size;
        char ** token;
};

Parser::Parser(char string[], char symbol[], bool inclusive)
{
    unsigned int stringAt = 0;
    
    size = 0;
    while(string[stringAt] != '\0')
    {
        size++;
    }

    char * tokenTemplate[size + 1] = {0};
    char lineTemplate[size + 1] = {'\0'};
    unsigned int tokenTemplateAt, lineTemplateAt, copyAt, lineSize = 0;

    for(stringAt = 0; stringAt < size; stringAt++)
    {
        unsigned int symbolAt = 0;

        while(symbol[symbolAt] != '\0')
        {
            if(string[stringAt] == symbol[symbolAt])
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
                    tokenTemplate[tokenTemplateAt] = new char [2] {string[stringAt], '\0'};
                    tokenTemplateAt++;
                }
                stringAt++;

                break;
            }
            symbolAt++;
        }
        if(stringAt < size)
        {
            lineTemplate[lineTemplateAt] = string[stringAt];
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
        tokenTemplate[tokenTemplateAt] = new char[lineSize + 1];
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

    }
}