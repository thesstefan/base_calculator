/**
 * @file convert_succesive.hpp
 * @brief Base conversion implementation using the method
 *        of succesive division.
 * @author Stefan Stefanache (916/2) 
 * @date 11.12.2020
 */
#pragma once

#include "number.hpp"
#include "tools.hpp"

/**
 * @brief Converts a Number instance from a source base 
 *        to a destination base using the succesive
 *        division method.
 *
 * @warning Must be used only for SrcBase > DstBase.
 *
 * @tparam SrcBase the source base
 * @tparam DstBase the destination base
 *
 * @param number_to_convert the Number to be converted
 *
 * @exception std::runtime_error on SrcBase <= DstBase.
 *
 * @return converted Number instance
 */
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
