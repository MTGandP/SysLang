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
#include <streambuf>
#include <vector>

#include "exceptions.h"

/*
 * A function used to read a token. Takes a data string as input and
 * searches for a token at the beginning of the data. If a matching
 * token is found, returns the length of the token. If not, returns 0.
 */
typedef size_t (*ReaderFun)(std::string);

/* 
 * A struct containing a token string and an int representing the type
 * of the token.
 */
struct Token {
    int type;
    std::string core;
};

/* 
 * A struct containing information necessary to read in a particular
 * type of token.
 * 
 * type: The unique numeric type of the token.
 * fun: The ReaderFun used to read the token.
 */
struct TokenReader {
    int type;
    ReaderFun fun;
};

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
     * Defines a new type of token. When reading data to find tokens,
     * this object uses token readers defined here to find matches.
     * If a string can match multiple token readers, it is matched
     * against whichever token reader was defined first.
     * 
     * value: A unique value representing the token type. If multiple
     *   tokens are defined with the same value, this may result in
     *   undefined behavior. Default token readers always hold values 
     *   greater than or equal to 1000, so the client is free to pass
     *   in values 0-999.
     * fun: A client-defined ReaderFun that finds the token.
     */
    void addTokenReader(int value, ReaderFun fun);

    /* 
     * Clears the list of token readers.
     */
    void clearTokenReaders();

    /* 
     * Returns true if there are no more tokens to read.
     */
    bool empty();
    
    /* 
     * Opens the specified file and reads in its data. If this object
     * was already reading data, the previous data is overwritten.
     * 
     * If the given file does not exist, this throws a FileOpenException.
     */
    void start(std::string filename);
        
    /* 
     * Returns the next token in the data stream.
     */
    std::string readToken();

    static size_t wordReader(std::string data);
    static size_t numberReader(std::string data);
    static size_t spaceReader(std::string data);
//    static std::string symbolReader(std::string data);
//    static std::string stringReader(std::string data);
    
private:
    std::string data;
    size_t pos;
    bool isEmpty;
    std::vector<TokenReader> readers;
    
};


#endif /* defined(__SysLang__Lexer__) */

