/**
 * @file convert_substitution.hpp
 * @brief Base conversion implementation using
 *        the substitution method.
 * @author Stefan Stefanache (916/2) 
 * @date 11.12.2020
 */
#pragma once

#include "number.hpp"
#include "tools.hpp"

/**
 * @brief Converts a Number instance from a source base 
 *        to a destination base using the substitution method.
 *
 * @warning Must be used only for SrcBase < DstBase.
 *
 * @tparam SrcBase the source base
 * @tparam DstBase the destination base
 *
 * @param number_to_convert the Number to be converted
 *
 * @exception std::runtime_error on SrcBase >= DstBase.
 *
 * @return converted Number instance
 */
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
