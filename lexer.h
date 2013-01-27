//
//  Lexer.h
//
//  Created by Michael Dickens on 1/25/13.
//

#ifndef __SysLang__Lexer__
#define __SysLang__Lexer__

#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

#include "Exceptions.h"

/* 
 * struct token
 * 
 * A struct containing a token string and an int representing the type
 * of the token.
 */
struct token {
    int type;
    std::string core;
};

class Lexer {
public:
    
    /*
     * Constructor for Lexer.
     */
    Lexer();
    
    /* 
     * Destructor for Lexer.
     */
    ~Lexer();

    /*
     * Adds a pattern to the list of patterns. When scanning a file
     * for tokens, this object looks for strings matching the given
     * patterns. If a string matches more than one pattern, it is
     * matched against the pattern that was added first.
     * 
     * Lexer supports POSIX extended regular expressions. If the given
     * pattern is not a well-formed regular expression, throws a
     * RegexExceptionDetail exception.
     */
    void addPattern(std::string pattern);
    
    /* 
     * Opens the specified file. If Lexer was already reading a file, closes
     * the previous file.
     * 
     * If the given file does not exist, this throws a FileOpenException.
     */
    void start(std::string filename);
    
    /* 
     * If a file is currently open, closes the file. If no file is open, does 
     * nothing.
     * 
     * return: true if a file was closed, false if not.
     */
    bool finish();
    
    /* 
     * Returns the next token in the currently-open file.
     */
    std::string getToken();

    
private:
    std::ifstream infile;
    std::vector<std::regex> patterns;
    
};


#endif /* defined(__SysLang__Lexer__) */

