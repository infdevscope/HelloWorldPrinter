#ifndef HELLOPRINTER_H
#define HELLOPRINTER_H

#include <iostream>
#include <string>

class HelloWorldPrinter {
public:
    HelloWorldPrinter();
    bool checkAndPrint(int number);
    static int getMagicNumber();
    
private:
    int magicNumber;
    void printHelloWorld() const;
};

void printHelloWorld1326();

#endif
