//
//  Exceptions.cpp
//
//  Created by Michael Dickens on 1/25/13.
//

#include "Exceptions.h"

FileOpenException::FileOpenException() throw()
{
    this->message = "Failed to open file";
}

FileOpenException::FileOpenException(std::string filename) throw()
{
    this->message = "Failed to open file: '" + filename + "'";
}

FileOpenException::~FileOpenException() throw() {}

const char *FileOpenException::what() const throw() 
{
    return message.c_str();
}
