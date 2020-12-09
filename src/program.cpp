#include <iostream>

#include "number.hpp"
#include "fast_convert.hpp"

int main() {
    Number<4> number("12312312312321321321");

    auto nr = convert_fast<4, 2>(number);

    std::cout << nr.get_value();
}
