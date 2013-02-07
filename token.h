//
// token.h
//
// Created by Michael Dickens on 1/28/13.
//
// Contains declarations for Token and its default subclasses.
// 

#ifndef __SysLang__token__
#define __SysLang__token__

#include <cstdlib>
#include <string>

/* 
 * Defines the type of function used to read in a token. Takes a
 * buffer as input and returns a number indicating the length of the
 * token. Upon failure to find a token, returns 0.
 * 
 * See Token::read() for specification on how tokens should be read.
 */
typedef size_t (* ReaderFun)(std::string);

/* 
 * A Token object represents a token outputted by the Lexer. Clients
 * may define new types of tokens as subclasses of Token and then pass
 * them to a Lexer to use for lexical analysis.
 * 
 */
class Token {

public:

    /* 
     * Initializes an empty token. Should not be used.
     * TODO: Throw an exception when this is called.
     */
    Token();

    /*
     * Constructor for Token. Takes a function that defines how this
     * object should read tokens.
     */
    Token(ReaderFun reader);

    /* 
     * Destructor for Token.
     */
    ~Token();

    /* 
     * Reads in a buffer where the beginning of the buffer may
     * represent an instance of this token's type. This function 
     * attempts to read in a token from the beginning of the
     * buffer. Upon success, it stores the token within this object,
     * possibly overwriting a previously-stored token. The token may
     * be accessed using toString().
     * 
     * return: true on success, false on failure.
     */
    bool read(std::string buffer);

    /* 
     * Returns true if the token was successfully read, false
     * if not.
     */
    bool good() const;

    /* 
     * Returns the number of characters read from the buffer to create
     * this token.
     */
    size_t length() const;
    
    /* 
     * Returns a string representation of the token.
     */
    virtual std::string toString() const;

    static size_t wordTokenReader(std::string buffer);
    static size_t spaceTokenReader(std::string buffer);
    static size_t numberTokenReader(std::string buffer);


private:
    ReaderFun reader;
    std::string token;
    size_t privateLength;

};

#endif /* ifndef __SysLang__token__ */
