#ifndef _GRESKE_H_
#define _GRESKE_H_

#include <exception>

class IndexOutOfRange : public std::exception {
public:
	IndexOutOfRange() : exception(" *** Error: Position you provided doesn't exist! Please use a position which is within list's lenght! *** ") {}
};

class InvalidIndex : public std::exception {
public:
	InvalidIndex() : exception(" *** Error: Position should be greater than zero! *** ") {}
};

class InvalidId : public std::exception {
public:
	InvalidId() : exception(" *** Error: Student with provided ID has not been found! *** ") {}
};

class InvalidList : public std::exception {
public:
	InvalidList() : exception(" *** Error: The select listed is empty! *** ") {}
};
#endif