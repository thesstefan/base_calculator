#pragma once

#include "number.hpp"
#include "tools.hpp"

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
