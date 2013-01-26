//
//  Lexer.h
//
//  Created by Michael Dickens on 1/25/13.
//

#ifndef __SysLang__Lexer__
#define __SysLang__Lexer__

#include <fstream>
#include <iostream>
#include <vector>

#include "Exceptions.h"

struct token {
    int value;
    std::string core;
};

class Lexer {
public:
    
    /*
     * Constructor for Lexer.
     * 
     * patterns: A list of regular expressions where each regular expression 
     *   matches a token. When scanning a file for tokens, Lexer looks for 
     *   strings matching the patterns given. If a string matches more than 
     *   one pattern, it is matched against the pattern that comes
     *   first in the list.
     */
    Lexer(std::vector<std::string> patterns);
    
    /* 
     * Destructor for Lexer.
     */
    ~Lexer();

    
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
    std::vector<std::string> patterns;
    
};


#endif /* defined(__SysLang__Lexer__) */
