#include "helloprinter.h"
#include <iostream>

int main() {
    std::cout << "=== HelloWorldPrinter Demo ===" << std::endl;
    
    // Method 1: Using class
    HelloWorldPrinter printer;
    std::cout << "Magic number is: " << printer.getMagicNumber() << std::endl;
    
    // Method 2: Direct function
    printHelloWorld1326();
    
    // Interactive example
    std::cout << "\nEnter 1326 to see magic: ";
    int input;
    std::cin >> input;
    
    if (printer.checkAndPrint(input)) {
        std::cout << "🎉 It works!" << std::endl;
    } else {
        std::cout << "❌ Not " << input << ", try 1326!" << std::endl;
    }
    
    return 0;
}
