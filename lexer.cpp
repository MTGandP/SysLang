//
//  Lexer.cpp
//
//  Created by Michael Dickens on 1/25/13.
//

#include "lexer.h"

using namespace std;

Lexer::Lexer() {
    isBufferEmpty = true;
    addReader(WordToken::reader);
    addReader(SpaceToken::reader);
}

Lexer::~Lexer() {}

void Lexer::clearTokenTypes()
{
    readers.clear();
}

void Lexer::addReader(TokenReader reader)
{
    readers.push_back(reader);
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

Token *Lexer::readToken() 
{
    Token *token;
    for (vector<TokenReader>::size_type i = 0; 
         i < readers.size(); ++i) {        
        if ((token = (*readers[i])(buffer.substr(pos)))) {
            pos += token->length();
            return token;
        }
    }
    
    isBufferEmpty = true;
    return NULL;
}

