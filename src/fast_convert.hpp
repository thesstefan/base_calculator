#pragma once

#include <cstdlib>
#include <stdexcept>
#include <algorithm>

#include "number.hpp"
#include "misc.hpp"

template <size_t SrcBase>
Number<2> convert_to_base2(const Number<SrcBase>& number_to_convert) {
    if (!is_power_of_two(SrcBase))
        throw std::runtime_error("Use convert_to_base2 only with power of 2 base");

    std::string base2_string = "";
    size_t number_of_digits_used = BINARY_DIGIT_MAX_LENGTH - get_the_power_of_two(SrcBase);

    for (const char &character : number_to_convert.get_value()) {
        std::string base2_digit = RAPID_CONVERSION_STRINGS[digitToValue(character)];

        base2_string += base2_digit.substr(number_of_digits_used, BINARY_DIGIT_MAX_LENGTH);
    }

    return Number<2>(base2_string);
}

template <size_t DstBase>
Number<DstBase> convert_from_base2(const Number<2>& number_to_convert) {
    if (!is_power_of_two(DstBase))
        throw std::runtime_error("Use convert_to_base2 only with power of 2 base");;

    std::string new_base_string = "";
    const size_t number_of_binary_digits_used = get_the_power_of_two(DstBase);

    std::string base2_string = number_to_convert.get_value();
    while (base2_string.size() % number_of_binary_digits_used != 0)
        base2_string.insert(base2_string.begin(), '0');

    for (size_t index = 0; index < base2_string.size(); index += number_of_binary_digits_used) {
        std::string base2_digit_string = 
            base2_string.substr(index, number_of_binary_digits_used);

        while (base2_digit_string.size() != BINARY_DIGIT_MAX_LENGTH) 
            base2_digit_string.insert(base2_digit_string.begin(), '0');

        const size_t digit_value = std::find(RAPID_CONVERSION_STRINGS.cbegin(), 
                                                   RAPID_CONVERSION_STRINGS.cend(),
                                                   base2_digit_string) - RAPID_CONVERSION_STRINGS.cbegin();

        new_base_string += valueToDigit(digit_value);
    }

    return Number<DstBase>(new_base_string);
}

template <size_t SrcBase, size_t DstBase>
Number<DstBase> convert_fast(const Number<SrcBase>& number_to_convert) {
    if (!is_power_of_two(DstBase) || !is_power_of_two(SrcBase))
        throw std::runtime_error("Use convert_to_base2 only with bases that are \
                                  powers of two");

    Number<2> base2_number = convert_to_base2<SrcBase>(number_to_convert);

    return convert_from_base2<DstBase>(base2_number);
}
