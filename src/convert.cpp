#include "convert.hpp"

#include <algorithm>
#include <stdexcept>

Number convert_base(unsigned int dstBase, const Number& number) {
    if (!isBaseSupported(dstBase))
        throw std::runtime_error("Base not supported");

    if (is_power_of_two(dstBase) && is_power_of_two(number.base)) 
        return convert_fast(dstBase, number);

    if (number.base < dstBase)
        return convert_substitution(dstBase, number);

    if (number.base > dstBase)
        return convert_successive_division(dstBase, number);

    return number;
}
