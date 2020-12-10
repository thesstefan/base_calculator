#include <algorithm>
#include <stdexcept>

#include "convert.hpp"
#include "tools.hpp"

Number convert_substitution(unsigned int dstBase,
                            const Number& number) {
    if (!(number.base < dstBase))
        throw std::runtime_error(
                "Use the substitution method only for SrcBase < DstBase");

    const Number base(dstBase, std::string{valueToDigit(number.base)});
    Number sum(dstBase, "0");
    Number base_power(dstBase, "1");

    const std::string value = number.get_value();
    for (int char_index = value.size() - 1; char_index >= 0; char_index--) {
        sum = sum + base_power * Number(dstBase, std::string{value[char_index]});

        base_power = base_power * base;
    }

    return sum;
}
