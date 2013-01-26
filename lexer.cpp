//
//  Lexer.cpp
//
//  Created by Michael Dickens on 1/25/13.
//

#include "Lexer.h"

using namespace std;

Lexer::Lexer(vector<string> patterns)
{
    this->patterns = patterns;
}

Lexer::~Lexer() 
{
    finish();
}

void Lexer::start(string filename) 
{
    finish();
    
    infile.open(filename.c_str());
    if (infile.fail()) throw FileOpenException(filename);
}

bool Lexer::finish() 
{
    if (infile.is_open()) {
        infile.close();
        return true;
    } else {
        return false;
    }
}

string Lexer::getToken() 
{
    return "";
}

