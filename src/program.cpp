#include <iostream>

#include "number.hpp"
#include "convert_fast.hpp"

int main() {
    std::cout << (Number<2>("1010101010010100101") + 
                  Number<2>("101111111111111")).get_value() << std::endl;
}
