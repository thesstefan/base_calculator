#include <iostream>

#include "number.hpp"
#include "convert.hpp"

int main() {
    std::cout << convert_succesive<16, 10>(
        Number<16>("ABCD")).get_value() << std::endl;
}
