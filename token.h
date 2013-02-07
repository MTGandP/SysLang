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
#include <regex>
#include "exceptions.h"

class Token;

/* 
 * Defines the type for a function that attempts to read a token from
 * the beginning of the buffer.
 * 
 * buffer: The input buffer from which to read a token.
 * 
 * return: Upon success, creates an instance of a Token subclass
 *   representing a particular type of token. Upon failure, returns
 *   NULL.
 */
typedef Token *(* TokenReader)(std::string buffer);

/* 
 * A Token object represents a token outputted by the Lexer. Clients
 * may define new types of tokens as subclasses of Token and then pass
 * them to a Lexer to use for lexical analysis.
 * 
 * The client instantiates a subclass of Token to represent a
 * particular type of token. Any subclass should implement all of the
 * un-implemented methods in Token as well as the following.
 * 
 * read(string buffer): A function of type TokenReader that returns a
 *   token of the subclass's type. Each subclass should have its own
 *   read() function.
 * Token(...): A constructor unique to this type of token that is
 *   called by the client-created read() function.
 * private: An internal representation that efficiently stores the
 *   information that represents the token.
 */
class Token {

public:

    /* 
     * Default constructor for Token. Reads in a token as a string and
     * stores it internally.
     */
    Token(std::string token);

    /* 
     * Destructor for Token.
     */
    virtual ~Token() = 0;

    /* 
     * Returns true if the token was successfully read, false
     * if not.
     */
    bool good() const;

    /* 
     * Returns the number of characters read from the buffer to create
     * this token.
     * 
     * Subclasses are responsible for ensuring that this
     * evaluates correctly. A subclass may set the internal variable
     * representing length or may overwrite the implementation of this 
     * method.
     */
    virtual size_t length() const;
    
    /* 
     * Returns a string representation of the token.
     * 
     * By default, returns the private token string. Subclasses may
     * use a different implementation.
     */
    virtual std::string toString() const;

protected:

    /* 
     * Stores the original token as it was read from a
     * file. Subclasses are responsible for correctly setting this
     * value in their constructors; failure to do so will result in
     * undefined behavior.
     */
    std::string token;
};


/* 
 * WordToken: Holds a word as defined by [a-zA-Z][a-zA-Z0-9]*
 */
class WordToken : Token {

public: 
    WordToken(std::string token);

    static Token *reader(std::string buffer);

};

/* 
 * SpaceToken: Holds whitespace.
 */
class SpaceToken : Token {

public: 
    SpaceToken(std::string token);
   
    static Token *reader(std::string buffer);

};


#endif /* ifndef __SysLang__token__ */

