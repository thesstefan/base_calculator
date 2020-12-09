#pragma once

#include "number.hpp"
#include "tools.hpp"

#include "convert_fast.hpp"

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

template <unsigned int SrcBase, unsigned int DstBase>
Number<DstBase> convert_succesive(const Number<SrcBase>& number_to_convert) {
    static_assert(SrcBase > DstBase, "Use the succesive division method only \
                                         for SrcBase > DstBase");

    const Number<SrcBase> base(std::string{valueToDigit(DstBase)});
    Number<SrcBase> quotinent(number_to_convert.get_value());

    std::string result_string = "";
    while (quotinent.get_value() != "0") {
        auto division_pair = quotinent / base;

        quotinent = division_pair.first;
        result_string.insert(result_string.begin(), division_pair.second.get_value()[0]);
    }

    return Number<DstBase>(result_string);
}

template <unsigned int SrcBase, unsigned int DstBase>
Number<DstBase> convert_base(const Number<SrcBase>& number_to_convert) {
    if (is_power_of_two(SrcBase) && is_power_of_two(DstBase)) 
        return convert_fast<SrcBase, DstBase>(number_to_convert);

    if (SrcBase < DstBase)
        return convert_substitution<SrcBase, DstBase>(number_to_convert);

    if (SrcBase > DstBase)
        return convert_succesive<SrcBase, DstBase>(number_to_convert);

    // Same base (SrcBase == DstBase)
    return number_to_convert;
}
