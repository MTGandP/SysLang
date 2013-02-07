//
// token.cpp
//
// Created by Michael Dickens on 1/28/13.
//

#include "token.h"

using namespace std;

/* 
 * 
 * Method definitions for Token.
 *
 */

Token::Token()
{
    privateLength = 0;
}

Token::Token(ReaderFun reader)
{
    this->reader = reader;
    privateLength = 0;
}

Token::~Token() {}

bool Token::read(string buffer)
{
    size_t index = (*reader)(buffer);
    if (index > 0) {
        privateLength = index;
        token = buffer.substr(0, index);
        return true;
    }
    
    return false;
}

bool Token::good() const
{
    return privateLength != 0;
}

size_t Token::length() const
{
    return privateLength;
}

string Token::toString() const
{
    return token;
}

/* 
 *
 * Method definitions for WordToken.
 *
 */

size_t Token::wordTokenReader(string buffer)
{
    if (isalpha(buffer[0])) {
        size_t i;
        for (i = 1; i < buffer.length() && isalnum(buffer[i]); ++i) {}
        return i;
    }

    return 0;
}


size_t Token::spaceTokenReader(string buffer)
{
    size_t i = 0;
    for (; i < buffer.length() && isspace(buffer[i]); ++i) {}
    return i;
    
}

size_t Token::numberTokenReader(string buffer)
{
    size_t i = 0;

    // unary +/-
    if (i < buffer.length() && (buffer[i] == '-' || buffer[i] == '+'))
        ++i;

    // integral digits
    for (; i < buffer.length() && isdigit(buffer[i]); ++i) {}

    // decimal point
    // TODO: finish this

    return i;
}
