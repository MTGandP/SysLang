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
        Lexer lexer;
        Token *token = NULL;
//        lexer.start("files/simple");
        lexer.setBuffer("testing one two three");
        while (true) {
            token = lexer.readToken();
            if (token == NULL) break;
            cout << token->toString();
            delete token;
        }
        cout << endl;

    } catch (exception& ex) {
        cerr << ex.what() << endl;
    }
    
    return 0;
}

