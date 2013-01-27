//
//  Exceptions.cpp
//
//  Created by Michael Dickens on 1/25/13.
//

#include "Exceptions.h"

using namespace std;

FileOpenException::FileOpenException() throw()
{
    message = "Failed to open file";
}

FileOpenException::FileOpenException(string filename) throw()
{
    message = "Failed to open file: '" + filename + "'";
}

FileOpenException::~FileOpenException() throw() {}

const char *FileOpenException::what() const throw() 
{
    return message.c_str();
}

RegexExceptionDetail::RegexExceptionDetail() throw() {}

RegexExceptionDetail::RegexExceptionDetail(
    regex_constants::error_type ecode) throw()
{
    this->ecode = ecode;
}

RegexExceptionDetail::~RegexExceptionDetail() throw() {}

const char *RegexExceptionDetail::what() const throw()
{
    using namespace regex_constants;

    switch (ecode) {
    case error_collate:
        return "regex error: invalid collating element name";
    case error_ctype:
        return "regex error: invalid character class name";
    case error_escape:
        return "regex error: invalid escaped character";
    case error_backref:
        return "regex error: invalid back reference";
    case error_brack:
        return "regex error: mismatched square brackets";
    case error_paren:
        return "regex error: mismatched parentheses";
    case error_brace:
        return "regex error: mismatched curly braces";
    case error_badbrace:
        return "regex error: invalid range between braces";
    case error_range:
        return "regex error: invalid character range";
    case error_space:
        return "regex error: insufficient memory to compile expression";
    case error_badrepeat:
        return "regex error: repeat specifier not preceded by valid regular expression";
    case error_complexity:
        return "regex error: too high complexity of attempted match";
    case error_stack:
        return "regex error: insufficient memory in attempted match";
    default:
        return "regex error";
    }
}

std::regex_constants::error_type RegexExceptionDetail::code() 
    const throw()
{
    return ecode;
}
