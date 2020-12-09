#pragma once

#include "number.hpp"
#include "tools.hpp"

template <unsigned int SrcBase, unsigned int DstBase>
Number<DstBase> convert_substitution(const Number<SrcBase>& number_to_convert) {
    static_assert(SrcBase < DstBase, "Use the substitution method only          \
                                      for SrcBase < DstBase");

    const Number<DstBase> base(std::string{valueToDigit(SrcBase)});
    Number<DstBase> sum("0");
    Number<DstBase> base_power("1");

    const std::string value = number_to_convert.get_value();
    for (int char_index = value.size() - 1; char_index >= 0; char_index--) {
        sum = sum + base_power * Number<DstBase>(std::string{value[char_index]});

        base_power = base_power * base;
    }

    return sum;
}
