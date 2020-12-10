#include <algorithm>
#include <stdexcept>

#include "convert.hpp"
#include "tools.hpp"

Number convert_to_base2(const Number& number) {
    if (!is_power_of_two(number.base))
        throw std::runtime_error("Use convert_to_base2 only with power of 2 base");

    std::string base2_string = "";
    size_t number_of_digits_used = BINARY_DIGIT_MAX_LENGTH 
                                   - get_the_power_of_two(number.base);

    for (const char &character : number.get_value()) {
        std::string base2_digit = RAPID_CONVERSION_STRINGS[digitToValue(character)];

        base2_string += base2_digit.substr(number_of_digits_used, BINARY_DIGIT_MAX_LENGTH);
    }

    return Number(2, base2_string);
}

Number convert_from_base2(unsigned int dstBase, const Number& number) {
    if (!is_power_of_two(dstBase))
        throw std::runtime_error("Use convert_to_base2 only with power of 2 base");;

    std::string new_base_string = "";
    const size_t number_of_binary_digits_used = get_the_power_of_two(dstBase);

    std::string base2_string = number.get_value();
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

    return Number(dstBase, new_base_string);
}

Number convert_fast(unsigned int dstBase, const Number& number) {
    if (!is_power_of_two(dstBase) || !is_power_of_two(number.base))
        throw std::runtime_error("Use convert_to_base2 only with bases that are \
                                  powers of two");
    Number base2_number = convert_to_base2(number);

    return convert_from_base2(dstBase, base2_number);
}
