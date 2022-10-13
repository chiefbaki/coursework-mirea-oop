#include <iostream>
#include <string>
#include "ConcreteStates.h"
#include "StateException.h"

void H::proceed(std::string::const_iterator& it, Interpreter* interp)
{
    if (*it < 'a' || *it > 'b') {
        throw StateException(std::string("Invalid symbol: ") + *it);
    }
    interp->setState(D::getInstance());
}

void D::proceed(std::string::const_iterator& it, Interpreter* interp)
{
    if (*it == 'a' || *it == 'b') {
        return interp->setState(S::getInstance());
    }
    else{
         throw StateException(std::string("Invalid symbol: ") + *it);
    }
}

void S::proceed(std::string::const_iterator& it, Interpreter* interp)
{
    if (*it == 'b')
        return interp->setState(S::getInstance());
    else throw StateException(std::string("Invalid symbol: ") + *it);
}

State& H::getInstance()
{
    static H self;
    return self;
}

State& D::getInstance()
{
    static D self;
    return self;
}

State& S::getInstance()
{
    static S self;
    return self;
}
