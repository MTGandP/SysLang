//
//  main.cpp
//
//  Created by Michael Dickens on 1/25/13.
//

#include <iostream>
#include "lexer.h"
#include "parser.h"

using namespace std;

int main(int argc, const char * argv[])
{
    try {
        vector<string> patterns;
        Lexer lexer(patterns);
        lexer.start("");
        cout << lexer.finish() << endl;
    } catch (exception& ex) {
        cerr << ex.what() << endl;
    }
    
    return 0;
}

