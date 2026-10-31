#include <iostream>
#include <string>
#include <cmath>
#include "calculator.h"


bool ReadNumber(Number& result) {
    bool b;
    if (std::cin >> result) {
        b = true;
        return b;
    } else {
        b = false;
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return b;
    }
}

bool RunCalculatorCycle(){
    using Number = double;
    Number number, n, mem;
    std::string op;
    bool bo = true;
    bool boo = false; //индикатор сохранения в память "s"
    n = 0;
        if (ReadNumber(number)) {
        n = n + number;
        while (std::cin >> op){
            if (op == "+") {
                if (ReadNumber(number)){
                    n = n + number;
                }
            }
            else if (op == "-") {
                if (ReadNumber(number)){
                    n = n - number;
                }  
            }
            else if (op == "*") {
                if (ReadNumber(number)){
                    n = n * number;
                }
            }
            else if (op == "/") {
                if (ReadNumber(number)){
                    n = n / number;
                }
            }
            else if (op == "**") {
                if (ReadNumber(number)){
                    n = pow(n, number);
                } 
            }
            else if (op == "s") {
                    mem = n;
                    boo = true;
                } 
            else if (op == "l") {
                if (boo) {
                    n = mem;
                } else {
                    std::cerr << "Error: Memory is empty" << std::endl;
                }
            }
            else if (op == ":") {
                if (ReadNumber(number)){
                    n = number;
                } 
            }
            else if (op == "c") {
                n = 0;
            }
            else if (op == "=") {
                std::cout << n << std::endl;
            }
            else if (op == "q") {
                break;
                return bo;
            }
            else {
                std::cerr << "Error: Unknown token " << op << std::endl;
                break;
            }
        }
    }
    return bo;
}