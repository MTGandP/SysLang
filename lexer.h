//
//  lexer.h
//
//  Created by Michael Dickens on 1/25/13.
//

#ifndef __SysLang__Lexer__
#define __SysLang__Lexer__

#include <fstream>
#include <iostream>
#include <regex>
#include <streambuf>
#include <vector>

#include "exceptions.h"
#include "token.h"

class Lexer {
public:

    /*
     * Constructor for Lexer. Adds Lexer's static reader methods to
     * the list of readers, in the same order that they are declared.
     */
    Lexer();
    
    /* 
     * Destructor for Lexer.
     */
    ~Lexer();

    /* 
     * Defines a new token reader used to lexically analyze the
     * buffer. Checks the buffer for matches against the readers
     * passed in to this method. If a string matches multiple readers,
     * it is matched against whichever reader was passed in first.
     */
    void addReader(TokenReader reader);

    /* 
     * Clears the list of token types.
     */
    void clearTokenTypes();

    /* 
     * Returns true if there are no more tokens to read.
     */
    bool empty();
    
    /* 
     * Opens the specified file and reads in its data. If this object
     * was already reading data, its buffer is overwritten.
     * 
     * If the given file does not exist, this throws a FileOpenException.
     */
    void start(std::string filename);
        
    /* 
     * Returns the next token in the buffer. If no more tokens can be
     * read, returns NULL.
     */
    Token *readToken();

    
private:
    std::string buffer;

    /* The first position in the buffer that has not been read. */
    size_t pos;

    bool isBufferEmpty;

    /* A list of TokenReaders used to lexically analyze the buffer. */
    std::vector<TokenReader> readers;
    
};


#endif /* defined(__SysLang__Lexer__) */

