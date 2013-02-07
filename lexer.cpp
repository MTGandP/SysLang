//
//  Lexer.cpp
//
//  Created by Michael Dickens on 1/25/13.
//

#include "lexer.h"

using namespace std;

Lexer::Lexer() {
    isBufferEmpty = true;
    addTokenType(new Token(Token::wordTokenReader));
    addTokenType(new Token(Token::spaceTokenReader));
    addTokenType(new Token(Token::numberTokenReader));
}

Lexer::~Lexer() {}

void Lexer::clearTokenTypes()
{
    tokenTypes.clear();
}

void Lexer::addTokenType(Token *type)
{
    tokenTypes.push_back(type);
}

bool Lexer::empty()
{
    return isBufferEmpty || pos >= buffer.length();
}

void Lexer::start(string filename) 
{
    ifstream infile;
    infile.open(filename.c_str());
    if (infile.fail()) throw FileOpenException(filename);

    string str((istreambuf_iterator<char>(infile)), 
               istreambuf_iterator<char>());
    buffer = str;
    isBufferEmpty = buffer.empty();
    pos = 0;
}

string Lexer::readToken() 
{
    for (vector<Token>::size_type i = 0; i < tokenTypes.size(); ++i) {        
        if (tokenTypes[i]->read(buffer.substr(pos))) {
            pos += tokenTypes[i]->length();
            return tokenTypes[i]->toString();
        }
    }

    isBufferEmpty = true;
    return "failed to find token";
}

