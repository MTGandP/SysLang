//
//  Exceptions.h
//
//  Created by Michael Dickens on 1/25/13.
//

#ifndef __SysLang__Exceptions__
#define __SysLang__Exceptions__

#include <exception>
#include <iostream>

class FileOpenException : public std::exception {
    
public:
    FileOpenException() throw();
    FileOpenException(std::string filename) throw();
    virtual ~FileOpenException() throw();
    
    virtual const char *what() const throw();
    
private:
    std::string message;
    
};

#endif /* defined(__SysLang__Exceptions__) */
