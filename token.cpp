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

Token::Token(string token)
{
    this->token = token;
}

Token::~Token() {}

bool Token::good() const
{
    return !token.empty();
}

size_t Token::length() const
{
    return token.length();
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

Token *WordToken::reader(string buffer)
{
    if (isalpha(buffer[0])) {
        size_t i;
        for (i = 1; i < buffer.length() && isalnum(buffer[i]); i++) {}
        return new WordToken(buffer.substr(0, i));
    }

    return NULL;
}

WordToken::WordToken(string token) : Token(token) {}

/* 
 *
 * Method definitions for SpaceToken.
 *
 */

Token *SpaceToken::reader(string buffer)
{
    size_t i = 0;
    for (; i < buffer.length() && isspace(buffer[i]); i++) {}
    if (i > 0) return new SpaceToken(buffer.substr(0, i));
    return NULL;
}

SpaceToken::SpaceToken(string token) : Token(token) {}

/* 
 *
 * Method definitions for NumberToken.
 *
 */


// TODO: have some way to exit in case of a false positive
// TODO: put this in NumberToken
Token *reader(string buffer)
{
    size_t i = 0;

    // unary +/-
    if (i < buffer.length() && (buffer[i] == '-' || buffer[i] == '+'))
        i++;

    // base
    if (buffer[i] == '0') {
        i++;
        if (buffer[i] == 'b' || buffer[i] == 'x' || buffer[i] == 'o')
            i++;
    }

    // integral digits
    for (; i < buffer.length() && isdigit(buffer[i]); i++) {}

    // decimal point
    if (buffer[i] == '.') i++;

    // decimal digits
    for (; i < buffer.length() && isdigit(buffer[i]); i++) {}

    // exponent
    if (buffer[i] == 'e' || buffer[i] == 'E') i++;

    // exponent digits
    for (; i < buffer.length() && isdigit(buffer[i]); i++) {}

    return NULL;
}




