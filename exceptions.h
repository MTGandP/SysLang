//
//  Exceptions.h
//
//  Created by Michael Dickens on 1/25/13.
//

#ifndef __SysLang__Exceptions__
#define __SysLang__Exceptions__

#include <exception>
#include <iostream>
#include <regex>

class FileOpenException : public std::exception {
    
public:
    FileOpenException() throw();
    FileOpenException(std::string filename) throw();
    virtual ~FileOpenException() throw();
    
    virtual const char *what() const throw();
    
private:
    std::string message;
    
};

/* 
 * A more sophisticated version of regex_error that provides support
 * for returning error codes as strings.
 */
class RegexExceptionDetail : public std::exception {

public:

    /* 
     * Default constructor.
     * 
     * WARNING: If this constructor is used, the value of this
     * object's error code will be undefined.
     */
    RegexExceptionDetail() throw();

    /* 
     * Initializes a RegexExceptionDetail object with error type
     * ecode.
     */
    RegexExceptionDetail(std::regex_constants::error_type ecode) throw();

    /* 
     * Destructor.
     */
    virtual ~RegexExceptionDetail() throw();

    /* 
     * Returns a string representation of the error code.
     */
    virtual const char *what() const throw();

    /* 
     * Returns the value of the error code.
     */
    virtual std::regex_constants::error_type code() const throw();

private:
    std::regex_constants::error_type ecode;

};

#endif /* defined(__SysLang__Exceptions__) */
