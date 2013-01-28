//
//  Lexer.cpp
//
//  Created by Michael Dickens on 1/25/13.
//

#include "lexer.h"

using namespace std;

Lexer::Lexer() {
    isEmpty = true;

    int type = 1000;
    addTokenReader(type++, wordReader);
    addTokenReader(type++, numberReader);
    addTokenReader(type++, spaceReader);
}

Lexer::~Lexer() {}

void Lexer::clearTokenReaders()
{
    readers.clear();
}

void Lexer::addTokenReader(int type, ReaderFun fun)
{
    TokenReader reader = { type, fun };
    readers.push_back(reader);
}

bool Lexer::empty()
{
    return isEmpty || pos >= data.length();
}

void Lexer::start(string filename) 
{
    ifstream infile;
    infile.open(filename.c_str());
    if (infile.fail()) throw FileOpenException(filename);

    string str((istreambuf_iterator<char>(infile)), 
               istreambuf_iterator<char>());
    data = str;
    isEmpty = data.empty();
    pos = 0;
}

string Lexer::readToken() 
{
    size_t length;
    for (vector<TokenReader>::size_type i = 0; i < readers.size();
         ++i) {
        if ((length = (*readers[i].fun)(data.substr(pos))) > 0) {            
            string token = data.substr(pos, length);
            pos += length;
            return token;
        }
    }

    isEmpty = true;
    return "failed to find token";
}

size_t Lexer::wordReader(string data)
{
    if (isalpha(data[0])) {
        size_t i;
        for (i = 1; i < data.length() && isalnum(data[i]); ++i) ;
        return i;
    }
    
    return 0;
}

size_t Lexer::numberReader(string data)
{
    size_t i = 0;
    if (data.length() >= 2 && data[0] == '0' && 
        (data[1] == 'x' || data[1] == 'X')) i += 2;
    for (; i < data.length() && isdigit(data[i]); ++i) ;
    if (i < data.length() && data[i] == '.') ++i;
    for (; i < data.length() && isdigit(data[i]); ++i) ;
    if (i < data.length() && (data[i] == 'e' || data[i] == 'E')) ++i;
    for (; i < data.length() && isdigit(data[i]); ++i) ;
    return i;
}

size_t Lexer::spaceReader(string data)
{
    size_t i = 0;
    for (; i < data.length() && isspace(data[i]); ++i) ;
    return i;
}

