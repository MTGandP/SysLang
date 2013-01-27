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
        lexer.addPattern("[0-9A-Z]+");
        lexer.start("");
        cout << lexer.finish() << endl;
    } catch (regex_error& ex) {
        cerr << ex.what() << ": " << (ex.code() == regex_constants::error_brack) << endl;
    } catch (exception& ex) {
        cerr << ex.what() << endl;
    }
    
    return 0;
}

