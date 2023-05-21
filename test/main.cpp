#include "verify.h"
#include <iostream>

int main() {
    const char* file = "test.txt";
    const char* pem = "test.pem";
    const char* sig = "test.txt.sig";
    int result = verify_result(file,sig, pem);
    if(result ==  0)
        std::cout << "verify pass";
    else std::cout << "verify fail";

}
