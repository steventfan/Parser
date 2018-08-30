# **Parser**

## Testing

1. Run "make" in the command line
2. In the *inputs/* folder, edit the file *string.txt* to the string you want to parse and the file *symbols.txt* for the characters you want to parse the string at (**Note:** if a newline character is the last character in the text file, that newline character will be ignored)
3. Run "bin/test" in the command line
4. Once testing is finished, run "make clean"

**Note:** The actual parser consists of the files *parser.h* and *parser.cpp*. All other files (*test.cpp*, *string.txt*, *symbols.txt*) are for testing purposes only. The documentation of the parser from here on will thus only refer to the files *parser.h* and *parser.cpp*.
## How To Use
To use the parser, the user must construct a *Parser* object with the valid parameters of the class constructor. The user can call the *Parser* class constructor using the following formats:
* Parser()
* Parser(char, **char**, **bool**)
* Parser(char, **char\***, **bool**)
* Parser(char \*, **char**, **bool**)
* Parser(char \*, **char \***, **bool**)

The bold parameters are optional. The first parameter refers to the string to be parsed, the second parameter refers to the symbols that the string will be parsed at (defaults to empty character), and the third parameter is a boolean value that determines whether the parsing symbol in parameter two be included in the parsed string (*true*) or not (*false*) (defaults to *false*).

**Note:** All instances of *char* arrays that hold strings are expected to end with the null terminating value '*\0*'. The parser generates *char* arrays that end with '*\0*' and expect the user to pass in *char* array parameters that also end with '*\0*'. Failure to follow this standard may result in unintended consequences.

A string is parsed into individual tokens that can be accessed using the *at(unsigned int)* function which returns a *char* pointer to the array holding the string. If no tokens are generated, *at(unsigned int)* will return a *char* pointer to *null*. The *count()* function returns the number of individual tokens there are.

**For example:**

string = "Hello World !"

parsing symbol = "l"

include parse symbol in parsed string = *false*

**Yields:**

"He"

"o Wor"

"d !"

Where *at(0)*, *at(1)*, and *at(2)* are called for each line respectively. The *count()* function in this example returns 3.
