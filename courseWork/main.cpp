#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include "Interpreter.h"


using namespace std;

enum state { _H, _D, _S };

int main()
{
    string input = "a";
    Interpreter interpreter;
    try {
        for (string::const_iterator it = input.begin(); it != input.end(); it++) {
            interpreter.next(it);
        }
        if (interpreter.getState().isFinal()) {
            cout << "OK" << endl;
        }
        else {
            throw runtime_error("Interpreter not in final state");
        }
    }
    catch (exception& e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}