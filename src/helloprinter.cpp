#include "helloprinter.h"

HelloWorldPrinter::HelloWorldPrinter() : magicNumber(1326) {}

int HelloWorldPrinter::getMagicNumber() {
    return 1326;
}

void HelloWorldPrinter::printHelloWorld() const {
    std::cout << "hello world " << magicNumber << "!" << std::endl;
}

bool HelloWorldPrinter::checkAndPrint(int number) {
    if (number == magicNumber) {
        printHelloWorld();
        return true;
    }
    return false;
}

void printHelloWorld1326() {
    std::cout << "hello world 1326!" << std::endl;
}
