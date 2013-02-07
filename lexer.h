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
     * Defines a new type of token. When reading buffer to find tokens,
     * this object uses token types defined here to find matches.
     * If a string can match multiple token types, it is matched
     * against whichever was defined first.
     * 
     * type: An instance of a token type. The object passed in should
     *   not be used for anything else.
     * 
     * Usage
     * // lexer is an instantiation of Lexer
     * lexer->add(new WordToken());
     */
    void addTokenType(Token *type);

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
     * Returns the next token in the buffer.
     */
    std::string readToken();

    
private:
    std::string buffer;
    size_t pos;
    bool isBufferEmpty;
    std::vector<Token *> tokenTypes;
    
};


#endif /* defined(__SysLang__Lexer__) */

